#pragma once
#include <ostream>
#include <memory>
#include "Info.h"
#include "VectorFactory.h"

// product可以是接口类也可以是实现类
//
// 我个人推荐用实现类即可
// 因为factory可以对任意product内部成员进行组合
// product自身类型上（继承）的多态反而没有太多必要
//
// 如果是接口类的话
// 那么不同具体product本身就可以影响factory的行为
// （比如选择性忽略某个成员不使用factory对应make接口来构造）
// product和factory之间都互不知道对方的具体类型
struct Vector {

    // 一个可能的好处是，
    // 不管内部流程多复杂（需要传递很多参数信息）的构造函数，
    // 现在只需要接收一个factory即可
    Vector(std::shared_ptr<VectorFactory> factory)
        : _factory(std::move(factory)),
          // 基本用法
          _size(_factory->makeSize()),
          // 如果有多个成员的话就由同一factory下的多个接口处理
          // 且factory可以配置成员，适合面向为接口类的成员
          _info(_factory->makeInfo()) {}

    friend std::ostream& operator<<(std::ostream &os, Vector &vec);

private:
    // product持有factory
    // 因为可能会在二阶段构造时才会用到
    std::shared_ptr<VectorFactory> _factory;
    size_t _size;
    std::shared_ptr<Info> _info;
};

inline std::ostream& operator<<(std::ostream &os, Vector &vec) {
    return os << "size: " << vec._size << ", info: " << vec._info->text();
}