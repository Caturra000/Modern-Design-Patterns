#pragma once
#include "Expression.h"

struct DoubleExpression: Expression {

    double value;

    DoubleExpression(double value): value(value) {}

    // 相比intrusive不需要实现print()
};