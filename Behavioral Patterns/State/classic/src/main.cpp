#include <vector>
#include <functional>
#include <iostream>
#include <sstream>
#include <tuple>
#include <random>
#include <algorithm>
#include "TaskStruct.h"

using Action = std::tuple<const char*, std::function<bool()>>;

auto makeStateMachineFor(TaskStruct &process) {
    std::vector<Action> machine {
        std::make_tuple("NEW",           [&] { return process.setNew(); }),
        std::make_tuple("READY",         [&] { return process.setReady(); }),
        std::make_tuple("RUNNING",       [&] { return process.setRunning(); }),
        std::make_tuple("INTERRUPTIBLE", [&] { return process.setInterruptible(); }),
        std::make_tuple("TRACED",        [&] { return process.setTraced(); }),
        std::make_tuple("STOPPED",       [&] { return process.setStopped(); }),
        std::make_tuple("DEAD",          [&] { return process.setDead(); })
    };
    return machine;
}

auto makeRandomFactors(size_t size, size_t begin, size_t end) {
    std::vector<size_t> randomFactors(size);
    std::uniform_int_distribution<size_t> d(begin, end);
    std::random_device rd;
    std::for_each(randomFactors.begin(), randomFactors.end(), [&](size_t &factor) {
        factor = d(rd);
    });
    return randomFactors;
}

auto makeActions(const std::vector<Action> &machine,
                 const std::vector<size_t> &factors) {
    // actions with info (const char*)
    std::vector<std::tuple<const char*, std::function<bool()>>> actions;
    for(auto iter = factors.cbegin(); iter != factors.cend(); iter++) {
        auto repeat = *iter;
        auto &elem = machine[iter - factors.cbegin()];
        while(repeat--) {
            actions.emplace_back(elem);
        }
    }
    std::random_shuffle(actions.begin(), actions.end());
    return actions;
}

// g++ -o main main.cpp TaskStates.cpp TaskStruct.cpp && ./main
int main() {
    // 尝试模拟一个进程的生命周期
    // 随机地让状态A转移到状态B（各10-20次，错误的状态转移会失败）
    // 转移的过程称为action
    TaskStruct process;
    auto stateMachine = makeStateMachineFor(process);
    auto randomFactors = makeRandomFactors(stateMachine.size(), 10, 20);
    auto actions = makeActions(stateMachine, randomFactors);
    const char *current = "NEW";
    std::stringstream logger;
    logger << "[logger] " << current;
    for(auto &&action : actions) {
        auto &realAction = std::get<1>(action);
        const char *next = std::get<0>(action);
        if(realAction()) {
            std::cout << "[OK]  " << current << "->" << next << std::endl;
            current = next;
            logger << "->" << current;
        } else {
            std::cout << "[ERR] " << current << "->" << next << std::endl;
        }
    }
    std::cout << "======================\n"
              << logger.str() << std::endl;
}
