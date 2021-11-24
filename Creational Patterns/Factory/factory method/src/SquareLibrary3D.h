#pragma once
#include <memory>
#include "Vector.h"
#include "Vector3D.h"
#include "SquareLibrary.h"

struct SquareLibrary3D: SquareLibrary {
protected:
    std::shared_ptr<Vector> makeSquareVector(size_t param) override {
        return std::make_shared<Vector3D>(param, param, param);
    }
};