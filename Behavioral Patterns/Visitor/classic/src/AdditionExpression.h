#pragma once
#include "Expression.h"

struct AdditionExpression: Expression {

    Expression *left;
    Expression *right;

    AdditionExpression(Expression *left, Expression *right)
        : left(left), right(right) {}

    ~AdditionExpression() {
        delete left;
        delete right;
    }

    // 相比intrusive仍需要实现接口
    // 但是为visitor接口，而不是具体的print
    // 不写成静态策略的方式是为了提供多态
    void accept(ExpressionVisitor *visitor) override {
        visitor->visit(this);
    }
};