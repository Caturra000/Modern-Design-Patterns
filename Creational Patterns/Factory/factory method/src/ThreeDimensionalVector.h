#pragma once
#include "Vector.h"

// arr[][][]，通过长宽高决定元素个数
struct ThreeDimensionalVector: Vector {
    ThreeDimensionalVector(size_t l, size_t w, size_t h)
        : Vector(l * w * h) {}

    const char* info() const override { return "[3D]"; }
};