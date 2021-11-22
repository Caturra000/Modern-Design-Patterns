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
    // IMPROVEMENT:
    // - 这是很有规律性的操作，实现类中只有this类型是不同的，
    // - 完全可以用policy-based继承一个方法来完成
    // - 比如 struct AdditionExpression: Expression, Acceptable<AdditionExpression>;
    // - 此时Expression可以抛弃accept接口，且实现类都不用再写这个实现
    void accept(ExpressionVisitor *visitor) override {
        visitor->visit(this);
    }
};