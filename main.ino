/*
  Dylan Kainth
  Based of a project by Rui Santos https://RandomNerdTutorials.com/esp32-http-get-open-weather-map-thingspeak-arduino/

  The licence of that project can be found below.
  ---------------------------------------------------------------------------------------------
  Rui Santos
  Complete project details at Complete project details at https://RandomNerdTutorials.com/esp32-http-get-open-weather-map-thingspeak-arduino/

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  ---------------------------------------------------------------------------------------------

*/

// Include libraries
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include <LiquidCrystal.h>

// Define pins for LCD Display
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);

// Set your own WIFI password and SSID here.
const char *ssid = "WIFI_SSID";
const char *password = "WIFI_PASSWORD";

// Set your own API here
String openWeatherMapApiKey = "KEY";

// Set your country code and city name here
String city = "London";
String countryCode = "UK";

// THE DEFAULT TIMER IS SET TO 10 SECONDS FOR TESTING PURPOSES
// For a final application, check the API call limits per hour/minute to avoid getting blocked/banned
unsigned long lastTime = 0;

// Timer set to 1 hr in ms
unsigned long timerDelay = 3600000;

// set boolean firsttime
bool firstTime = true;
String jsonBuffer;

void setup()
{
    // Init serial and LCD
    Serial.begin(115200);
    lcd.begin(16, 2);

    // Connect to WIFI
    WiFi.begin(ssid, password);
    Serial.println("Connecting");

    // print wifi connecting to lcd
    lcd.setCursor(0, 0);
    lcd.print("Connecting to");
    lcd.setCursor(0, 1);
    lcd.print(ssid);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());

    Serial.println("Timer set to " + timerDelay / 1000 + " seconds (timerDelay variable), it will take 10 seconds before publishing the first reading.");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Weather - " + city);
}

void loop()
{
    // Send an HTTP GET request to OpenWeatherMap

    if (((millis() - lastTime) > timerDelay) || firstTime)
    {
        // Check WiFi connection status
        if (WiFi.status() == WL_CONNECTED)
        {
            String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&units=metric&APPID=" + openWeatherMapApiKey;

            jsonBuffer = httpGETRequest(serverPath.c_str());
            Serial.println(jsonBuffer);
            JSONVar myObject = JSON.parse(jsonBuffer);

            // JSON.typeof(jsonVar) can be used to get the type of the var
            if (JSON.typeof(myObject) == "undefined")
            {
                Serial.println("Parsing input failed!");
                return;
            }

            // Dump to serial
            Serial.print("JSON object = ");
            Serial.println(myObject);
            Serial.print("Temperature: ");
            Serial.println(myObject["main"]["temp"]);
            Serial.print("Pressure: ");
            Serial.println(myObject["main"]["pressure"]);
            Serial.print("Humidity: ");
            Serial.println(myObject["main"]["humidity"]);
            Serial.print("Wind Speed: ");
            Serial.println(myObject["wind"]["speed"]);

            lcd.setCursor(0, 1);

            // print to LCD
            lcd.print(myObject["main"]["temp"]);
            lcd.print("C");

            lcd.setCursor(8, 1);

            // print weather main description
            lcd.print(myObject["weather"][0]["main"]);
        }
        else
        {
            Serial.println("WiFi Disconnected");
        }

        // Reset timer
        lastTime = millis();

        // disable firsttime
        firstTime = false;
    }
}

String httpGETRequest(const char *serverName)
{
    WiFiClient client;
    HTTPClient http;

    // Your Domain name with URL path or IP address with path
    http.begin(client, serverName);

    // Send HTTP POST request
    int httpResponseCode = http.GET();

    String payload = "{}";

    if (httpResponseCode > 0)
    {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        payload = http.getString();
    }
    else
    {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();

    return payload;
}