# ESP8266 BLE(Bluetooth) & Wi-Fi Jammer

This project aims to develop a jammer using ESP8266 to interfere with BLE and Wi-Fi networks. The project utilizes the RF24 library to generate interference in the 2.4 GHz bands and provides user feedback via an OLED display.

## 📌 Requirements

- **NodeMCU ESP8266** (or a compatible ESP8266-based board)
- **NRF24L01+** module
- **0.96" OLED SSD1306** display
- **Push Button** (to switch modes)
- **Connecting wires**

## 🛠 Required Libraries

The following libraries must be installed in Arduino IDE:

- [RF24](https://github.com/nRF24/RF24)
- [SPI](https://github.com/espressif/arduino-esp32/tree/master/libraries%2FSPI)
- [ezButton](https://github.com/ArduinoGetStarted/button)
- [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)

## ⚡ Hardware Connections

| ESP8266 Pin | NRF24L01+ Pin | Description |
|------------|---------------|-------------|
| D2 (GPIO4) | CSN            | Chip Select |
| D4 (GPIO2) | CE           | Module enable |
| D5 (GPIO14)| SCK           | Serial clock signal |
| D7 (GPIO13)| MOSI          | Data output |
| D6 (GPIO12)| MISO          | Data input |
| 3.3V       | VCC           | Power supply |
| GND        | GND           | Ground |

| ESP8266 Pin | OLED Pin | Description |
|------------|---------|-------------|
| D1 (GPIO5)| SDA     | Serial data line |
| D3 (GPIO0)| SCL     | Serial clock line |
| 3.3V       | VCC     | Power supply |
| GND        | GND     | Ground |

| ESP8266 Pin | Button Pin | Description |
|------------|---------|-------------|
| RX (GPIO3) | Button  | User input button (Another PIN Button to GND) |

## 🚀 Setup & Execution

1. **Make the connections**: Complete the hardware setup as per the table above.
2. **Install libraries**: Use **Library Manager** in Arduino IDE to install the required libraries.
3. **Upload the code**: Open `jammer.ino` in Arduino IDE and upload it to your ESP8266 board.
4. **Power up the device**: Connect your ESP8266 to a power source. The OLED screen will display jammer information.

## 📡 Usage

When powered on, the device starts in **"Waiting Idly :("** mode by default.
Press the button to switch between the following modes:

1. **BLE(Bluetooth) & All 2.4 GHz** (Interferes with all Bluetooth, 2.4 GHz devices)
2. **Just Wi-Fi** (Interferes only with Wi-Fi networks)
3. **Waiting Idly :(** (Puts the device in standby mode)

The current mode will be displayed on the OLED screen.

**Note:** You can connect external power like small lipo batteries.

**Warning:** The nRF24l01 module getting extremely hot during use. This does not affect operation probably. But it may overheat your hand :D.

### Example photos
![Front side of jammer](https://github.com/system-linux/FazJammer/blob/main/photos/1.jpg?raw=true)
![Other side of jammer](https://github.com/system-linux/FazJammer/blob/f7895b19fa5819ae011fccfad6261fd778de5186/photos/2.jpg?raw=true)
[![Video Aç](https://img.youtube.com/vi/4Mi9WWJwfMw/0.jpg)](https://www.youtube.com/watch?v=4Mi9WWJwfMw)
## 📜 License & Legal Disclaimer

This project is for **educational purposes only** and unauthorized usage is **illegal**. Please check your country's laws and adhere to ethical guidelines.

---

**Developer:** [system-linux](https://github.com/system-linux)

## Star History
[![Star History Chart](https://api.star-history.com/svg?repos=system-linux/FazJammer&type=Date)](https://www.star-history.com/#system-linux/FazJammer&Date)
