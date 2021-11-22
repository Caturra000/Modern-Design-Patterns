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

    void print(std::ostream &os) override {
        // ...
    }

};