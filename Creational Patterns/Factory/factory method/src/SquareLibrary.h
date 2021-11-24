#pragma once
#include <iostream>
#include <memory>
#include "Vector.h"

// 一个提供Square的库，作为client调用更为底层的Vector来实现
// FIXME 这个Square表达的意思似乎不太准确？
struct SquareLibrary {
    // 提供给更为上层的user调用的API
    std::shared_ptr<Vector> getSquareVector(size_t param) {
        // 这里是factory变更的部分
        auto product = makeSquareVector(param);

        // 可能会做一些固定不变的操作
        log(std::cout, "[INFO]", "size:", product->size, "info:", product->info());
        return product;
    }

protected:
    // 构造函数无法由子类来实现
    // 而函数却可以通过接口形式间接完成
    // 这种形式如同一个virtual constructor
    // 注意，既然是接口，那么返回类型需要有支持多态的能力
    virtual std::shared_ptr<Vector> makeSquareVector(size_t param) = 0;

    template <typename T, typename ...Ts>
    void log(std::ostream &os, const T &param, const Ts &...params) {
        os << param;
        os << (sizeof...(params) ? ' ' : '\n');
        log(os, params...);
    }
    void log(std::ostream &os) { os << std::flush; }
};