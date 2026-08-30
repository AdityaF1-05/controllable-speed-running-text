#include <Arduino.h>
#include "../include/oled-manager.h"

OLED myoled(128, 64);
OLED* thisoled = &myoled;

DelaySpeed pinDelay(A0);
DelaySpeed* thisDelay = &pinDelay;

void setup() {
    if (!thisoled->OLEDbegin()) {
      while(true);
    }
}

void loop() {

    // Users also can change the parameters (minimal, maximum) of delay Range
    int delaySpeed = thisDelay->MappedDelay(1, 250);

    // Users can Rewrite the Message
    // Don't overwrite the "delaySpeed" Variable
    thisoled->RunningText("HELLO AND WELCOME", delaySpeed);
}