#pragma once
#include <memory>
#include "Vector.h"
#include "ThreeDimensionalVector.h"
#include "SquareLibrary.h"

struct ThreeDimensionalSquareLibrary: SquareLibrary {
protected:
    std::shared_ptr<Vector> makeSquareVector(size_t param) override {
        return std::make_shared<ThreeDimensionalVector>(param, param, param);
    }
};