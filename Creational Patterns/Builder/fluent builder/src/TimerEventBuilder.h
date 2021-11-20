#pragma once
#include <string>
#include <chrono>
#include <functional>
#include "TimerEvent.h"

class TimerEventBuilder {
public:
    TimerEventBuilder(std::string name);
    TimerEventBuilder& when(TimerEvent::TimePoint timePoint);
    TimerEventBuilder& atMost(size_t times);
    TimerEventBuilder& per(TimerEvent::TimeUnit interval);
    TimerEventBuilder& with(std::function<void()> callable);

    TimerEvent build();

private:
    TimerEvent event;
};