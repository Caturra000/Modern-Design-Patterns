#pragma once
#include <cstddef>

// simple factory的例子中，product通过static function替代构造
// 但是static也存在不太满意的地方：
// 1. static只适合用于无状态的场合，难以记录/修改复杂状态（比如你要记录创建次数、时间戳和历史耗时）
// 2. 当应用场合足够复杂时，应该考虑单一职责，既把factory流程分离出product
// 因此这个时候应该有一个class VectorFactory独立于Vector
// 至于make()流程是static还是non-static看需求
//
// 通常，类会以inner class的形式来实现
// 因为有时候会用到一些product的私有的字段，比如在make()里引入二阶段构造
// （这是一个simple factory的补充，自然不希望为了这个问题引入大量接口来解决）
// 相比friend特性，inner class更加在其他语言中更加通用
struct Vector {

    struct VectorFactory {
        Vector makeWithSize(size_t size);
        Vector makeWithCapacity(size_t size);

    // 如果是以inner class加上static function来实现make的话
    // 可以尝试把显式构造Factory禁止
    // private:
    //     Factory() = default;
    // 也可以新增构造函数以实现有状态的factory
    // 如Factory(size_t limit)表示最多允许make次数，控制_count--达到0后抛出异常
    // public:
    //     Factory(size_t limit): _count(limit) {}

    private:
        // 每个make内部都会调用
        // 里面用到product(Vector)的一些私有字段
        // 因为是inner class，product不必为了factory访问私有字段而新增接口
        void initProduct();

        // 调用make的记录次数
        size_t _count;
    };

    // client可以通过Vector::Factory()获得实例
    using Factory = VectorFactory;

private:
    size_t _size;
    size_t _capacity;
};