#pragma once
#include <cstddef>

struct Vector {
public:
    // 这两个构造函数对编译器来说存在二义性，无法共存
    // Vector(size_t size);
    // Vector(size_t capacity);

    // 通过simple factory简单解决
    // simple factory并不关注factory形式是什么
    // 简单应用的话，static函数即可
    static Vector makeWithSize(size_t size);
    static Vector makeWithCapacity(size_t capacity);

private:
    size_t _size;
    size_t _capacity;
};