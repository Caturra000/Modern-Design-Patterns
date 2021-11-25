#pragma once
#include <memory>
#include "Info.h"
#include "VectorFactory.h"

struct SquareVector2DFactory: VectorFactory {
    SquareVector2DFactory(size_t length): _length(length) {}

    size_t makeSize() override {
        return _length * _length;
    }

    std::shared_ptr<Info> makeInfo() override {
        return std::make_shared<Vector2DInfo>();
    }
private:
    size_t _length;

    struct Vector2DInfo: Info {
        const char* text() override {
            return "[2D]";
        }
    };
};