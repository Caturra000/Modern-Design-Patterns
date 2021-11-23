#include <bits/stdc++.h>
#include "SquareLibrary.h"
#include "Vector.h"
#include "TwoDimensionalSquareLibrary.h"
#include "TwoDimensionalVector.h"
#include "ThreeDimensionalSquareLibrary.h"
#include "ThreeDimensionalVector.h"

int main() {
    using Library = std::shared_ptr<SquareLibrary>;
    std::vector<Library> libraries {
        std::make_shared<TwoDimensionalSquareLibrary>(),
        std::make_shared<ThreeDimensionalSquareLibrary>()
    };
    for(auto &&library : libraries) {
        auto square = library->getSquareVector(3);
        std::cout << *square << std::endl;
    }
    return 0;
}