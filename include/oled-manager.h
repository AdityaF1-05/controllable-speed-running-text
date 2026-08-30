#pragma once
#ifndef OLED_MANAGER_H
#define OLED_MANAGER_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

class OLED {
    private:
    uint8_t addressOled;    // Variable of AddressOLED
    Adafruit_SSD1306 display;   // Class of Display

    int currentX;
    unsigned long previousMillis;

    public:
    // Class OLED Member (Width & Height Input in Main Object, Address has initialized)
    OLED(uint8_t width, uint8_t height, uint8_t address = 0x3C);
    bool OLEDbegin();
    void ShowMessage(const char* message1);
    void clear();

    void RunningText(const char* runningMessage, unsigned long intervalTime);
};

class DelaySpeed {
    private:
    uint8_t pinPot;

    public:
    DelaySpeed(uint8_t analogPin);
    
    void begin();
    int readValue();
    int MappedDelay(int minDelay, int maxDelay);
};

#endif