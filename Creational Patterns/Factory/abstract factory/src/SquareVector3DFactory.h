#pragma once
#include <memory>
#include "Info.h"
#include "VectorFactory.h"

struct SquareVector3DFactory: VectorFactory {
    SquareVector3DFactory(size_t length): _length(length) {}

    size_t makeSize() override {
        return _length * _length * _length;
    }

    std::shared_ptr<Info> makeInfo() override {
        return std::make_shared<Vector3DInfo>();
    }
private:
    size_t _length;

    struct Vector3DInfo: Info {
        const char* text() override {
            return "[3D]";
        }
    };
};