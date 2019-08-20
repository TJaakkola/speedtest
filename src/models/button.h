#ifndef BUTTON_H
#define BUTTON_H

class Button {
  public:
    Button(int pin);
    bool isEventTriggered();
  private:
    int pin;
    bool state;
};

#endif