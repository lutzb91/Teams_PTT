#include <Arduino.h>
#include <DigiKeyboard.h>
#include <JC_Button.h>

#define PIN_LED     1
#define PIN_BUTTON  2

Button button(PIN_BUTTON);

void setup() {
  pinMode(PIN_LED, OUTPUT);

  button.begin();
}

void loop() {

  button.read();
  

  if(button.wasPressed()) {
    DigiKeyboard.update();
    DigiKeyboard.sendKeyStroke(KEY_O, MOD_SHIFT_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_N);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    digitalWrite(PIN_LED, HIGH);
  }

  if(button.wasReleased()) {
    DigiKeyboard.update();
    DigiKeyboard.sendKeyStroke(KEY_O, MOD_SHIFT_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_F);
    DigiKeyboard.sendKeyStroke(KEY_F);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    digitalWrite(PIN_LED, LOW);
  }
}