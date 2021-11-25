#include <vector>
#include <iostream>
#include "Vector.h"
#include "VectorFactory.h"
#include "SquareVector2DFactory.h"
#include "SquareVector3DFactory.h"

int main() {
    using Factory = std::shared_ptr<VectorFactory>;
    std::vector<Factory> factories = {
        std::make_shared<SquareVector2DFactory>(3),
        std::make_shared<SquareVector3DFactory>(3)
    };
    for(auto &&factory : factories) {
        Vector vec(factory);
        std::cout << vec << std::endl;
    }
}