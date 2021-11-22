#pragma once
#include <ostream>
#include "Expression.h"
#include "DoubleExpression.h"
#include "AdditionExpression.h"

struct ExpressionPrinter {

    // 目前没法这样写，因为无法直接得知子类的具体类型
    // void print(DoubleExpression *expression, );
    // void print(AdditionExpression *, std::ostream &);

    void print(Expression *expression, std::ostream &os) {
        if(auto e = dynamic_cast<DoubleExpression*>(expression)) {
            // ...
        } else if(auto e = dynamic_cast<AdditionExpression*>(expression)) {
            // ...
        }
        // 如果有其它的子类，则继续往下添加
        // 但相比接口，它不是强制实现，不需要那就是no-op
    }
};