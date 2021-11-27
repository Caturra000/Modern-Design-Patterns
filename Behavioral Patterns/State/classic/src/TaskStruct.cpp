#include <memory>
#include "TaskStruct.h"
#include "TaskStates.h"

TaskStruct::TaskStruct()
    : _state(std::make_shared<NewTaskState>()) {}

bool TaskStruct::setNew() { return _state->setNew(this); }
bool TaskStruct::setReady() { return _state->setReady(this); }
bool TaskStruct::setRunning() { return _state->setRunning(this); }
bool TaskStruct::setInterruptible() { return _state->setInterruptible(this); }
bool TaskStruct::setTraced() { return _state->setTraced(this); }
bool TaskStruct::setStopped() { return _state->setStopped(this); }
bool TaskStruct::setDead() { return _state->setDead(this); }

void TaskStruct::setState(std::shared_ptr<TaskState> state) {
    _state = std::move(state);
}