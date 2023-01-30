#ifndef LedControl_h
#define LedControl_h

#include "Arduino.h"

class LedControl {
  public:
    LedControl(int pin);
    void turnOn(int onTime, int offTime, int times);
    void turnOff();
    void update();
  private:
    int _pin;
    int _onTime;
    int _offTime;
    int _times;
    int _state;
    unsigned long _previousMillis;
};

#endif


