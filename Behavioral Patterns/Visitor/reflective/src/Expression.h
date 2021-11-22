#pragma once

struct Expression {
    virtual ~Expression() = default;

    // 考虑到单一职责，print应该由Printer类型处理
};