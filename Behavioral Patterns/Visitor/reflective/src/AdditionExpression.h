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

    // 相比intrusive不需要实现print()
};