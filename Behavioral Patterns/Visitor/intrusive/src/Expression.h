#pragma once
#include <ostream>

// struct Expression {
//     // empty
// };

struct Expression {

    // 这是新增的接口，用于输出Expression
    // 意味着子类都必须要实现一遍print接口
    // 这就是所谓的侵入式
    virtual void print(std::ostream &os) = 0;

    // 如果再接着增加一个eval()，用于求值
    // 那么子类还是要重复一遍
    // virtual std::any eval() = 0;
};