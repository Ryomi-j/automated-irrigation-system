#include "LEDManager.h"
#include <Arduino.h>

LEDManager::LEDManager(int yellowPin, int greenPin) {
  yellowLedPin = yellowPin;
  greenLedPin = greenPin;
}

void LEDManager::init() {
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void LEDManager::updateLedState(int state) {
  switch (state) {
    case 0:
      digitalWrite(yellowLedPin, LOW);
      digitalWrite(greenLedPin, LOW);
      break;
    case 1:
      digitalWrite(yellowLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);
      break;
    case 2:
      digitalWrite(yellowLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      break;
    case 3:
      digitalWrite(yellowLedPin, HIGH);
      digitalWrite(greenLedPin, HIGH);
      break;
  }
}
