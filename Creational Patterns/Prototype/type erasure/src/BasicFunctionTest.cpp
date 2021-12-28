#include "BasicFunction.h"
#include <iostream>
#include <string>
#include <vector>

// 测试多个参数
// 并使用不同形式的可调用对象

struct MyCallable {
    double operator()(int v, std::string info) {
        std::cout << info << std::endl;
        return v * 1.1;
    }
};

double simple(int v, std::string info) {
    std::cout << info << std::endl;
    return v * 2.2;
}

int main() {
    MyCallable cb;
    std::vector<Function<double(int, std::string)>> functions;
    functions.emplace_back(cb);
    functions.emplace_back(simple);
    functions.emplace_back([](int v, std::string info) {
        std::cout << info << std::endl;
        return v * 3.3;
    });
    for(auto &&f : functions) {
        std::cout << f(1, "test") << std::endl;
    }
}