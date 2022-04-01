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
![image2](/docs/20220213_170215.jpg)

## Social Media
Find a Reddit post for this project [here](https://www.reddit.com/r/electronics/comments/tt9dw8/esp32_connected_to_a_16x2_lcd_display/).

## Products
[ESP32](https://www.aliexpress.com/item/32826540261.html?spm=a2g0o.order_detail.0.0.710ff19ckwHSkZ) / I bought this one.

[16x2 LCD](https://www.aliexpress.com/item/32845856464.html?spm=a2g0o.productlist.0.0.69fb6c234l8Mkg&algo_pvid=399d261e-b833-488f-bce6-d7daa3d6e4fd&algo_exp_id=399d261e-b833-488f-bce6-d7daa3d6e4fd-21&pdp_ext_f=%7B%22sku_id%22%3A%2265129311451%22%7D&pdp_pi=-1%3B1.06%3B-1%3B-1%40salePrice%3BGBP%3Bsearch-mainSearch) / I didn't buy this exact one, but here's a similar one.

[Breadboard](https://www.aliexpress.com/item/1005001607502404.html?spm=a2g0o.productlist.0.0.2a2168e8xttYsb&algo_pvid=f6168882-ccfe-4833-800e-5336558e9817&algo_exp_id=f6168882-ccfe-4833-800e-5336558e9817-5&pdp_ext_f=%7B%22sku_id%22%3A%2212000016780239155%22%7D&pdp_pi=-1%3B0.38%3B-1%3B-1%40salePrice%3BGBP%3Bsearch-mainSearch) / Similar one to this.

[Wires](https://www.aliexpress.com/item/1005002118864496.html?spm=a2g0o.productlist.0.0.4adf1d3d76edPe&algo_pvid=cdca95ac-e9c2-450d-bc0e-a4edf72990e2&algo_exp_id=cdca95ac-e9c2-450d-bc0e-a4edf72990e2-6&pdp_ext_f=%7B%22sku_id%22%3A%2212000023064345895%22%7D&pdp_pi=-1%3B2.59%3B-1%3B3.0%40salePrice%3BGBP%3Bsearch-mainSearch) / Wires similar to this.
