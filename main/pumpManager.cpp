#include "PumpManager.h"
#include <Arduino.h>

PumpManager::PumpManager(int pin) {
  relayPin = pin;
}

void PumpManager::init() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // 릴레이 OFF로 초기화
}

void PumpManager::startPump() {
  Serial.println("Pump ON.");
  digitalWrite(relayPin, HIGH);  // 펌프 ON
}

void PumpManager::stopPump() {
  Serial.println("Pump OFF.");
  digitalWrite(relayPin, LOW);   // 펌프 OFF
}
