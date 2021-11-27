#pragma once
#include <memory>
#include "TaskState.h"

struct TaskStruct {

    TaskStruct();

    bool setNew();
    bool setReady();
    bool setRunning();
    bool setInterruptible();
    bool setTraced();
    bool setStopped();
    bool setDead();

    void setState(std::shared_ptr<TaskState> state);
private:
    std::shared_ptr<TaskState> _state;
};