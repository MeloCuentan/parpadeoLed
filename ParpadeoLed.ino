#include "LedControl.h"

LedControl led(2);

void setup() {
  Serial.begin(115200);
}

void loop() {
  led.update();
  if (Serial.available() != 0) {
    String RX = Serial.readStringUntil('\r');
    if (RX == "1") {
      Serial.println("Activamos el led");
      led.turnOn(500, 1500, 5);
    }
  }
}