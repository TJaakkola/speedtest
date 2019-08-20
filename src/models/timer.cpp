#include <Arduino.h>
#include <models/timer.h>
#include <globals/instances.h>

Timer::Timer() {
  this->blinkDelay = 2000;
  this->previousBlinkOnEventTimestamp = 0;
  this->previousBlinkOffEventTimestamp = 0;
  this->isTimerOn = false;
  this->isTopGamespeed = false;
}

Timer::~Timer() {}

void Timer::startTimer() {
  this->isTimerOn = true;
  this->previousBlinkOnEventTimestamp = millis();
  this->blinkDelay = 2000;
  this->isTopGamespeed = false;
}

void Timer::stopTimer(){
  this->isTimerOn = false;
  this->previousBlinkOnEventTimestamp = 0;
  this->blinkDelay = 2000;
  this->isTopGamespeed = false;
}

// Should a color light (yellow, red, blue, green) be turned on
bool Timer::isBlinkOnEventTriggered() {
  if(this->isTimerOn) {
    unsigned long currentMillis = millis();
    if( (currentMillis - this->previousBlinkOnEventTimestamp) >= this->blinkDelay) {
      this->previousBlinkOnEventTimestamp = currentMillis;
      if(!this->isTopGamespeed) {
        this->updateDelay();
      }
      return true;
    }
  }
  return false;
}

// Should a color light (yellow, red, blue, green) be turned off
bool Timer::isBlinkOffEventTriggered() {
  if(this->isTimerOn) {
    unsigned long currentMillis = millis();
    if( (currentMillis - this->previousBlinkOnEventTimestamp) >= (this->blinkDelay / 2) && this->previousBlinkOffEventTimestamp <= this->previousBlinkOnEventTimestamp) {
      this->previousBlinkOffEventTimestamp = currentMillis;
      return true;
    }
  }
  return false;
}


void Timer::updateDelay() {
  if(this->blinkDelay < 500 && this->blinkDelay >= 300 ) {
    this->blinkDelay = this->blinkDelay - (unsigned long) 5;
  } else if(this->blinkDelay < 1000 && this->blinkDelay >= 500) {
    this->blinkDelay = this->blinkDelay - (unsigned int) 10;
  } else if(this->blinkDelay >= 1000) {
    this->blinkDelay = this->blinkDelay - (unsigned int) 50;
  } else {
    this->isTopGamespeed = true;
  }
}

/* 
void Timer::updateDelay() {
  if(this->blinkDelay >= 300) {
    this->blinkDelay = this->blinkDelay - (unsigned long) 50;
  } else {
    this->isTopGamespeed = true;
  }
}
*/