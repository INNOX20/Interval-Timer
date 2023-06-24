#ifndef IntervalTimerLib_h
#define IntervalTimerLib_h

#include <Arduino.h>

unsigned long seconds(float s);
unsigned long minutes(float m);
unsigned long hours(float h);

class IntervalTimer {
public:
    IntervalTimer(unsigned long interval, void (*callback)());
    void update();
    void setInterval(unsigned long interval);
    void reset();

private:
    unsigned long _interval;
    unsigned long _nextTrigger;
    void (*_callback)();
};

#endif
