#pragma once
#include "TaskState.h"
#include "TaskStruct.h"

// 虽然这些前向声明用不着，但还是把汇总的类型列出来方便查阅
struct NewTaskState;
struct ReadyTaskState;
struct RunningTaskState;
struct InterruptibleTaskState;
struct TracedTaskState;
struct StoppedTaskState;
struct DeadTaskState;

///////////////////////
// 接口
///////////////////////

struct NewTaskState: TaskState {
    // fork()
    bool setReady(TaskStruct *process) const override;
};

struct ReadyTaskState: TaskState {
    // schedule()
    bool setRunning(TaskStruct *process) const override;
};

struct RunningTaskState: TaskState {
    // yield/preempt
    bool setReady(TaskStruct *process) const override;

    // wait_event/sleep
    bool setInterruptible(TaskStruct *process) const override;

    // trace
    bool setTraced(TaskStruct *process) const override;

    // signal:STOP
    bool setStopped(TaskStruct *process) const override;

    // exit()
    bool setDead(TaskStruct *process) const override;
};

struct InterruptibleTaskState: TaskState {
    // wakeup[/timeout]
    bool setReady(TaskStruct *process) const override;
};

struct TracedTaskState: TaskState {
    // resume
    bool setReady(TaskStruct *process) const override;
};

struct StoppedTaskState: TaskState {
    // signal:CONT
    bool setReady(TaskStruct *process) const override;
};

// 人被杀，就会死
//                 by Emiya Shirou
struct DeadTaskState: TaskState {};


///////////////////////
// 实现
///////////////////////


