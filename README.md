# ESP32-LCD-Weather
Arduino Code to connect my ESP32 to WIFI and then drive a 16x2 LCD board.

## Dependencies
Arduino JSON [here](https://www.arduino.cc/reference/en/libraries/arduino_json/)

## Code
Flash the main.ino code to the ESP32. You'll need to setup the board from the Board Manager in the Arduino IDE.
You need to change variables in lines 29-37
You can obtain the API key from the [OpenWeatherMap Website](https://openweathermap.org/api)

## Wiring
Wire the LCD screen up like [this](https://www.circuitschools.com/interfacing-16x2-lcd-module-with-esp32-with-and-without-i2c/) guide from circuitschools. 
![diagram](https://www.circuitschools.com/wp-content/uploads/2020/09/Interfacing-16X2-LCD-module-with-ESP-32-without-using-I2C-adapter.webp)

## Example
![image1](/docs/20220121_211039.jpg)