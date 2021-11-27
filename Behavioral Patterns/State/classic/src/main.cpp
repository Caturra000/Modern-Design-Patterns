#include <vector>
#include <functional>
#include <iostream>
#include "TaskStruct.h"

int main() {
    TaskStruct process;
    std::vector<std::function<bool()>> actions {
        [&] { return process.setNew(); },
        [&] { return process.setReady(); },
        [&] { return process.setRunning(); },
        [&] { return process.setInterruptible(); },
        [&] { return process.setTraced(); },
        [&] { return process.setStopped(); },
        [&] { return process.setDead(); }
    };
    for(auto &&action : actions) {
        std::cout << (action() ? "Y" : "N") << std::endl;
    }
}