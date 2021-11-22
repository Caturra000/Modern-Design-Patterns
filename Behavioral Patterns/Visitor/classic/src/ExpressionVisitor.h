#pragma once
#include "AdditionExpression.h"
#include "DoubleExpression.h"
#include "Expression.h"

struct ExpressionVisitor {
    // 所有的实现类都必须要声明对应的接口
    // 这个是在reflective中我们做不到的事情
    virtual void visit(DoubleExpression *) = 0;
    virtual void visit(AdditionExpression *) = 0;
};