#include "LedControl.h"

LedControl::LedControl(int pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
  _previousMillis = 0;
  _state = LOW;
}

void LedControl::turnOn(int onTime, int offTime, int times) {
  _onTime = onTime;
  _offTime = offTime;
  _times = times * 2; // *2 because it will switch on and off
  _state = LOW;
}

void LedControl::turnOff() {
  digitalWrite(_pin, LOW);
  _state = LOW;
}

void LedControl::update() {
  unsigned long currentMillis = millis();
  if ((_state == LOW) && (currentMillis - _previousMillis >= _offTime)) {
    digitalWrite(_pin, HIGH);
    _previousMillis = currentMillis;
    _state = HIGH;
    _times--;
  } else if ((_state == HIGH) && (currentMillis - _previousMillis >= _onTime)) {
    digitalWrite(_pin, LOW);
    _previousMillis = currentMillis;
    _state = LOW;
    _times--;
  }
  if (_times == 0) {
    turnOff();
  }
}