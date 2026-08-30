#include <Arduino.h>
#include "../include/oled-manager.h"

// Constructor for OLED
OLED::OLED(uint8_t width, uint8_t height, uint8_t address) 
    : addressOled(address), display(width, height, &Wire, -1) {}

DelaySpeed::DelaySpeed(uint8_t analogPin) : pinPot(analogPin) {}

// Method for Initiate OLED
bool OLED::OLEDbegin() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, addressOled)) {
        return false;
    }
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextWrap(false);
    display.display();
    return true;
}

void OLED::ShowMessage(const char* message1) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("--- WELCOME ---");

    display.setCursor(0, 12);
    display.println(message1);
}

void OLED::RunningText(const char* newMessage, unsigned long intervalms) {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= intervalms) {
        previousMillis = currentMillis;

        int totalPixel = strlen(newMessage) * 12;
        int limitLeft = -totalPixel;

        currentX--;

        if (currentX < limitLeft) {
            currentX = 128;
        }

        display.clearDisplay();
        display.setTextSize(2);
        
        display.setCursor(currentX, 24);
        display.print(newMessage);

        display.display();
    }
}

void OLED::clear() {
    display.clearDisplay();
    display.display();
}

void DelaySpeed::begin() {
    pinMode(pinPot, INPUT);
}

int DelaySpeed::readValue() {
    return analogRead(pinPot);
}

int DelaySpeed::MappedDelay(int minDelay, int maxDelay) {
    int rawValue = readValue();

    return map(rawValue, 0, 1023, minDelay, maxDelay);
}