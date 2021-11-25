#pragma once
#include <memory>
#include "Info.h"

// factory针对product内部需要的组件而声明对应的若干接口
struct VectorFactory {
    virtual size_t makeSize() = 0;
    virtual std::shared_ptr<Info> makeInfo() = 0;
};