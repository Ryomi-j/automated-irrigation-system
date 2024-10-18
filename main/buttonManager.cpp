#include "ButtonManager.h"
#include <Arduino.h>

ButtonManager::ButtonManager(int pin) {
  buttonPin = pin;
  buttonState = 0;
  lastButtonState = HIGH;
  lastDebounceTime = 0;
  debounceDelay = 50;  // 디바운스 시간 설정
}

void ButtonManager::init() {
  pinMode(buttonPin, INPUT); // 스위치 핀을 INPUT 모드로 설정
}

void ButtonManager::update() {
  int reading = digitalRead(buttonPin);

  // 디바운스 처리
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if (reading == LOW && lastButtonState == HIGH) {
    buttonState = (buttonState + 1) % 4;  // 0, 1, 2, 3 상태 순환
  }
  lastButtonState = reading;  // 이전 버튼 상태 업데이트
}

void ButtonManager::resetState() {
  buttonState = 0;  // 기본 상태로 리셋
}

int ButtonManager::getState() {
  return buttonState;
}
