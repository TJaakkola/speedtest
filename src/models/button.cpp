#include <Arduino.h>
#include <models/button.h>

Button::Button(int pin) {
  this->pin = pin;
  this->state = false;
}

bool Button::isEventTriggered() {
  bool isPressed = digitalRead(pin) == LOW;
  if(this->state == true && isPressed) {
    return false;
  } else if(state == true && !isPressed) {
    this->state = false;
    return false;
  } else if(state == false && isPressed) {
    this->state = true;
    return true;
  } else {
    return false;
  }

}