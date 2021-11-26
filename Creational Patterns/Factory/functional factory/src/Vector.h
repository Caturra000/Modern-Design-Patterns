#pragma once
#include <cstddef>
#include "VectorFactories.h"

struct Vector {
public:
    Vector(size_t size): _size(size) {}
    virtual ~Vector() = default;

    virtual const char *info() const = 0;

    using Factories = VectorFactories;
    static Factories& getFactories() {
        // 为了方便带入默认的配置，使用初始化列表
        // 但是不太推荐在这里引入具体实现类，仅用nullptr做示例
        static Factories factories {
            {"null", nullptr},
            {"", nullptr}
        };
        return factories;
    }
private:
    size_t _size;
};