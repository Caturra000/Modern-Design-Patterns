#include "TimerEvent.h"
#include "TimerEventBuilder.h"
#include "Timer.h"

// 一个不太好但能用的fluent builder
int main() {
    using namespace std::chrono_literals;

    Timer timer;

    // builder构造函数的参数：TimerEvent中必须要有的字段
    // 问题1：builder的构造函数本身不能链式调用，如何改进？
    // 问题2：我必须要知道TimerEventBuilder这个类型，能不能隐藏？
    TimerEventBuilder builder {"my first event"};
    builder.when(std::chrono::system_clock::now() + 5s)
           .atMost(3)
           .per(500ms)
           .with([] {
               // ...
           });
    // build()也是可以在紧接在链式调用后面
    // 问题3：我必须要调用显式的build()类似的过程才能得到TimerEvent吗？
    TimerEvent event = builder.build();
    timer.add(event);

    timer.run();
    return 0;
}