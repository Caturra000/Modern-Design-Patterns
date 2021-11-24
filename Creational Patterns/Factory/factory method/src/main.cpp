#include <bits/stdc++.h>
#include "Vector.h"
#include "Vector2D.h"
#include "Vector3D.h"
#include "SquareLibrary.h"
#include "SquareLibrary2D.h"
#include "SquareLibrary3D.h"

int main() {
    using Library = std::shared_ptr<SquareLibrary>;
    std::vector<Library> libraries {
        std::make_shared<SquareLibrary2D>(),
        std::make_shared<SquareLibrary3D>()
    };
    for(auto &&library : libraries) {
        auto square = library->getSquareVector(3);
    }
    return 0;
}