#pragma once
#include "ExpressionVisitor.h"

struct Expression {
    virtual ~Expression() = default;

    virtual void accept(ExpressionVisitor *visitor) = 0;
};