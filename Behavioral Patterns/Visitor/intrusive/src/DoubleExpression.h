#pragma once
#include "Expression.h"

struct DoubleExpression: Expression {

    double value;

    DoubleExpression(double value): value(value) {}

    void print(std::ostream &os) override {
        // ...
    }

};