#pragma once
#include <memory>
#include "Vector.h"
#include "TwoDimensionalVector.h"
#include "SquareLibrary.h"

struct TwoDimensionalSquareLibrary: SquareLibrary {
protected:
    std::shared_ptr<Vector> makeSquareVector(size_t param) override {
        return std::make_shared<TwoDimensionalVector>(param, param);
    }
};