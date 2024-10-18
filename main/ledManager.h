#ifndef LED_MANAGER_H
#define LED_MANAGER_H

class LEDManager {
  private:
    int yellowLedPin;
    int greenLedPin;

  public:
    LEDManager(int yellowPin, int greenPin);
    void init();
    void updateLedState(int state);
};

#endif
