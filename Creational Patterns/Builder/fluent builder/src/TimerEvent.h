#pragma once
#include <string>
#include <chrono>
#include <functional>

struct TimerEvent {
    using TimePoint = std::chrono::system_clock::time_point;
    using TimeUnit = std::chrono::milliseconds;

    // 一些基本属性
    // what: 事件的命名
    // when: 接收调度的时间点
    // how: 调度的内容
    // count: 可重复次数
    // interval: 再次调度的间隔差

    std::string what;
    TimePoint when;
    std::function<void()> how;
    size_t count;
    TimeUnit interval;

    // 假设后面有若干个字段
    // ...

};
