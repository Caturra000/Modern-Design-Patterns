#pragma once
#include <cstddef>
#include <ostream>

// 一般声明`factory method`接口的是调用方（client）或者仅充当factory的类型，而不是产品类（看实际场合）
struct Vector {

    Vector(size_t size): size(size) {}
    virtual ~Vector() = default;

    // 仅用于示例输出结果，可忽略
    virtual const char* info() const { return ""; }

    const size_t size;
};