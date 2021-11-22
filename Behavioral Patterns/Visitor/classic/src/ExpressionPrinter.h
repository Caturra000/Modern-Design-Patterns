#pragma once
#include <ostream>
#include "Expression.h"
#include "DoubleExpression.h"
#include "AdditionExpression.h"
#include "ExpressionVisitor.h"

// 新增继承visitor接口
struct ExpressionPrinter: ExpressionVisitor {

    // 在intrusive中因为没法实现这写接口
    // void print(DoubleExpression *expression, );
    // void print(AdditionExpression *, std::ostream &);
    // 从而实现了一个很胖的print(Expression *expression, std::ostream &os)实现
    // void print(Expression *expression, std::ostream &os);

    // 而visitor针对不同类型直接实现即可
    // 具体子类的类型信息由子类本身的this指针提供
    void visit(DoubleExpression *);
    void visit(AdditionExpression *);

    // 如果还需要增加其它类型，比如ExpressionEvaluator，
    // 所有的Expression实现类是不需要增加接口的，直接使用accept即可

// 由于visitor很通用，不止是用于printer
// 因此像输出就由子类来持有ostream引用，避免传入接口参数
private:
    std::ostream &_os;
};