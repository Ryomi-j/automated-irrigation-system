#ifndef PUMP_MANAGER_H
#define PUMP_MANAGER_H

class PumpManager {
  private:
    int relayPin;

  public:
    PumpManager(int pin);
    void init();
    void startPump();
    void stopPump();
};

#endif
