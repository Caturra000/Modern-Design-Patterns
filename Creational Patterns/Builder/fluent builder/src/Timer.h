#pragma once
#include <vector>
#include "TimerEvent.h"

class Timer {
public:
    void add(TimerEvent event);
    void run();

private:
    // 假设的内部容器
    std::vector<TimerEvent> _events;
};