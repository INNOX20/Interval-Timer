#include "IntervalTimerLib.h"

unsigned long seconds(float s) {
    return static_cast<unsigned long>(s * 1000);
}

unsigned long minutes(float m) {
    return seconds(m * 60);
}

unsigned long hours(float h) {
    return minutes(h * 60);
}

IntervalTimer::IntervalTimer(unsigned long interval, void (*callback)()) : _interval(interval), _callback(callback) {
    reset();
}

void IntervalTimer::update() {
    if (millis() >= _nextTrigger) {
        _nextTrigger += _interval;
        _callback();
    }
}

void IntervalTimer::setInterval(unsigned long interval) {
    _interval = interval;
}

void IntervalTimer::reset() {
    _nextTrigger = millis() + _interval;
}
