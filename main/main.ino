#include "ButtonManager.h"
#include "LEDManager.h"
#include "PumpManager.h"

unsigned long previousMillis = 0;
unsigned long pumpDuration = 10800000; // 기본 펌프 동작 시간 (3분 = 180000ms)
unsigned long interval = 10800000;   // 기본 간격: 3시간 (밀리초 단위)
unsigned long pumpStartTime = 0;     // 펌프가 켜진 시간을 기록

bool pumpRunning = false;            // 펌프가 켜져 있는지 상태 확인

ButtonManager buttonManager(2);      // 버튼 핀 2번
LEDManager ledManager(8, 9);         // 노란색 LED 8번, 초록색 LED 9번
PumpManager pumpManager(7);          // 릴레이 제어 핀 7번

void setup() {
  buttonManager.init();
  ledManager.init();
  pumpManager.init();

  Serial.begin(9600);
  Serial.println("System Initialized");

  // 이전 시간을 기록
  previousMillis = millis();
  buttonManager.resetState();         // 기본 버튼 상태 설정
  ledManager.updateLedState(buttonManager.getState());  // 기본 LED 상태

  // 최초로 펌프를 4분 동안 동작
  pumpStartTime = millis();           // 펌프 시작 시간 기록
  pumpManager.startPump();            // 펌프 ON
  pumpRunning = true;                 // 펌프 상태를 켜짐으로 설정
}

void loop() {
  buttonManager.update();
  int buttonState = buttonManager.getState();

  // 버튼 상태 출력
  Serial.print("Current Button State: ");
  Serial.println(buttonState);

  ledManager.updateLedState(buttonState); // LED 상태 업데이트

  // 상태에 따른 펌프 동작 간격 설정
  switch (buttonState) {
    case 0:
      interval = 10800000;  // 3시간 간격
      pumpDuration = 180000; // 3분 동안 급수

      break;
    case 1:
      interval = 7200000;   // 2시간 간격
      pumpDuration = 240000; // 4분 동안 급수
      break;
    case 2:
      interval = 14400000;  // 4시간 간격
      pumpDuration = 240000; // 4분 동안 급수
      break;
    case 3:
      pumpManager.startPump();  // 펌프가 계속 동작
      pumpRunning = true;
      return;
  }

  unsigned long currentMillis = millis();

  // 펌프가 켜져 있는 동안 펌프 동작 시간(4분)이 경과했는지 확인
  if (pumpRunning && (currentMillis - pumpStartTime >= pumpDuration)) {
    pumpManager.stopPump();   // 4분 후 펌프 OFF
    pumpRunning = false;      // 펌프 상태를 꺼짐으로 설정
    previousMillis = currentMillis;  // previousMillis를 펌프가 꺼진 시간으로 갱신
    Serial.println("Pump OFF after set duration");
  }

  // 설정된 간격에 따라 펌프를 다시 켤지 확인
  if (!pumpRunning && (currentMillis - previousMillis >= interval)) {
    pumpStartTime = currentMillis;   // 펌프 시작 시간 기록
    pumpManager.startPump();         // 펌프 ON
    pumpRunning = true;              // 펌프 상태를 켜짐으로 설정
    previousMillis = currentMillis;  // 다음 주기 시간 갱신
    Serial.println("Pump ON for next interval");
  }
}
