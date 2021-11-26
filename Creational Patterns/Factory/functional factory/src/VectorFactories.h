#pragma once
#include <map>
#include <string>
#include <functional>
#include <memory>

struct Vector;

// TODO non-copyable
// 这里用的形式为simple factory
// 考虑单一职责则把factory设为单独一个类
// 也可以使用inner factory形式，这样不必考虑前向声明product
//
// 可以注意到整个factories是很模板的，可以把它抽象为一个template class，如Factories<Vector>
struct VectorFactories {
    using FunctionalFactory = std::function<std::shared_ptr<Vector>()>;
    using Container = std::map<std::string, FunctionalFactory>;

    VectorFactories() = default;
    VectorFactories(std::initializer_list<Container::value_type> factories)
        : _container(std::move(factories)) {}

    void add(const std::string &type, FunctionalFactory factory) {
        _container[type] = std::move(factory);
    }

    std::shared_ptr<Vector> make(const std::string &type) {
        auto &function = _container[type];
        if(!function) return nullptr;
        return function();
    }

private:
    Container _container;
};