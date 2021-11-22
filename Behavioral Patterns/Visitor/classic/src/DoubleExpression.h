#pragma once
#include "Expression.h"

struct DoubleExpression: Expression {

    double value;

    DoubleExpression(double value): value(value) {}

    // 相比intrusive仍需要实现接口
    // 但是为visitor接口，而不是具体的print
    void accept(ExpressionVisitor *visitor) override {
        visitor->visit(this);
    }
};