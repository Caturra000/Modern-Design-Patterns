#pragma once
#include <memory>
#include "Vector.h"
#include "Vector2D.h"
#include "SquareLibrary.h"

struct SquareLibrary2D: SquareLibrary {
protected:
    std::shared_ptr<Vector> makeSquareVector(size_t param) override {
        return std::make_shared<Vector2D>(param, param);
    }
};