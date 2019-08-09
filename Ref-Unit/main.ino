#include "pinout.h"
#include "RefUnit.h"
#define BUTTON_PORT (D3)
#define LED_PORT (D5)
static RefUnit unit;

void setup() {
  unit = RefUnit(BUTTON_PORT, LED_PORT);
}

void loop() {
  if (digitalRead(BUTTON_PORT) == HIGH)
  {
    unit.on_button_pressed();
    while (digitalRead(BUTTON_PORT) == HIGH);
  }
  unit.get_led().operate();
}