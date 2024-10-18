#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H

class ButtonManager {
  private:
    int buttonPin;
    int buttonState;
    int lastButtonState;
    unsigned long lastDebounceTime;
    unsigned long debounceDelay;
    
  public:
    ButtonManager(int pin);
    void init();
    void update();
    void resetState();
    int getState();
};

#endif
