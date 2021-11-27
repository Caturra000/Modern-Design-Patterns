#pragma once

struct TaskStruct;

// 尝试模仿task_struct的运行时状态切换
// 这里是一个比较理论的模型（比如实际并不采用TASK_READY，睡眠也不只有TASK_INTERRUPTIBLE）
//
// 可以注意到，state本身可以为read-only
struct TaskState {
    virtual bool setNew(TaskStruct*) const { return false; }
    virtual bool setReady(TaskStruct*) const { return false; }
    virtual bool setRunning(TaskStruct*) const { return false; }
    virtual bool setInterruptible(TaskStruct*) const { return false; }
    virtual bool setTraced(TaskStruct*) const { return false; }
    virtual bool setStopped(TaskStruct*) const { return false; }
    virtual bool setDead(TaskStruct*) const { return false; }
};