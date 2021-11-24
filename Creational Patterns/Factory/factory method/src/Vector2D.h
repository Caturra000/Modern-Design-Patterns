#pragma once
#include "Vector.h"

// arr[][]，通过行列数列决定元素个数
struct Vector2D: Vector {
    Vector2D(size_t r, size_t c)
        : Vector(r * c) {}

    const char* info() const override { return "[2D]"; }
};