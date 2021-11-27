#include <memory>
#include "TaskStruct.h"
#include "TaskState.h"
#include "TaskStates.h"

template <typename ST>
bool makeState(TaskStruct *process) {
    process->setState(std::make_shared<ST>());
    return true;
}

bool NewTaskState::setReady(TaskStruct *process) const {
    return makeState<ReadyTaskState>(process);
}

bool ReadyTaskState::setRunning(TaskStruct *process) const {
    return makeState<RunningTaskState>(process);
}

bool RunningTaskState::setReady(TaskStruct *process) const {
    return makeState<ReadyTaskState>(process);
}

bool RunningTaskState::setInterruptible(TaskStruct *process) const {
    return makeState<InterruptibleTaskState>(process);
}

bool RunningTaskState::setTraced(TaskStruct *process) const {
    return makeState<TracedTaskState>(process);
}

bool RunningTaskState::setStopped(TaskStruct *process) const {
    return makeState<StoppedTaskState>(process);
}

bool RunningTaskState::setDead(TaskStruct *process) const {
    return makeState<DeadTaskState>(process);
}

bool InterruptibleTaskState::setReady(TaskStruct *process) const {
    return makeState<ReadyTaskState>(process);
}

bool TracedTaskState::setReady(TaskStruct *process) const {
    return makeState<ReadyTaskState>(process);
}

bool StoppedTaskState::setReady(TaskStruct *process) const {
    return makeState<ReadyTaskState>(process);
}