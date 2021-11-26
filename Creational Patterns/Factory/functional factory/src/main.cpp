#include <iostream>
#include <memory>
#include "Vector.h"
#include "Vector2D.h"
#include "Vector3D.h"

int main() {
    auto &factories = Vector::getFactories();
    // 这里形式比较简单，如果是带参数的，那就是完善callback
    factories.add("2D-Square-Default", [] {
        return std::make_shared<Vector2D>(3, 3);
    });
    factories.add("3D-Square-Default", [] {
        return std::make_shared<Vector3D>(3, 3, 3);
    });
    auto product = factories.make("2D-Square-Default");
    std::cout << (product ? product->info() : "null") << std::endl;
    auto nullProduct = factories.make("2D-any");
    std::cout << (nullProduct ? product->info() : "null") << std::endl;
}