#pragma once
#include <map>
#include <set>
#include <tuple>

struct TaskStruct {

    TaskStruct(): _state(TASK_NEW) {}

    bool setNew() { return testAndSet(TASK_NEW); }
    bool setReady() { return testAndSet(TASK_READY); }
    bool setRunning() { return testAndSet(TASK_RUNNING); }
    bool setInterruptible() { return testAndSet(TASK_INTERRUPTIBLE); }
    bool setTraced() { return testAndSet(TASK_TRACED); }
    bool setStopped() { return testAndSet(TASK_STOPPED); }
    bool setDead() { return testAndSet(TASK_DEAD); }

private:

    enum State {
        TASK_NEW,
        TASK_READY,
        TASK_RUNNING,
        TASK_INTERRUPTIBLE,
        TASK_TRACED,
        TASK_STOPPED,
        TASK_DEAD,

        __END_OF_STATE
    };

    bool testAndSet(State next) {
        if(!getRules()[_state].count(next)) {
            return false;
        }
        _state = next;
        return true;
    }

    // 数量级小，容器可随意，
    // 用map和set比较适用于enum比较离散的场合
    using Rules = std::map<State, std::set<State>>;
    static Rules& getRules() {
        static Rules rules {
            {TASK_NEW, {TASK_READY}},
            {TASK_READY, {TASK_RUNNING}},
            {TASK_RUNNING, {TASK_READY, TASK_INTERRUPTIBLE, TASK_TRACED, TASK_STOPPED, TASK_DEAD}},
            {TASK_INTERRUPTIBLE, {TASK_READY}},
            {TASK_TRACED, {TASK_READY}},
            {TASK_STOPPED, {TASK_READY}}
        };
        return rules;
    }

private:
    State _state;
};