#pragma once
#include <cstddef>
#include <ostream>

// 一般声明`factory method`接口的是调用方（client），而不是产品类（看实际场合）
struct Vector {

    Vector(size_t size): _size(size) {}
    virtual ~Vector() = default;

    // 仅用于示例输出结果，可忽略
    virtual const char* info() const { return ""; }
    friend std::ostream& operator<<(std::ostream &os, const Vector &vec);

private:
    size_t _size;
};

inline std::ostream& operator<<(std::ostream &os, const Vector &vec) {
    return os << "size = " << vec._size << ' ' << vec.info();
}