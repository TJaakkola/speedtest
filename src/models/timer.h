#ifndef TIMER_H
#define TIMER_H

class Timer {
  public:
    Timer();
    ~Timer();
    void startTimer();
    void stopTimer();
    bool isBlinkOnEventTriggered();
    bool isBlinkOffEventTriggered();
    bool isTimerOn;
    bool isTopGamespeed;
    unsigned long blinkDelay;
  private:
    
    unsigned long previousBlinkOnEventTimestamp;
    unsigned long previousBlinkOffEventTimestamp;
    void updateDelay();

};

#endif