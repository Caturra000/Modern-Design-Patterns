#pragma once
#include <cstddef>
#include <map>
#include <string>
#include <functional>
#include <memory>

struct Vector {
public:
    Vector(size_t size): _size(size) {}
    virtual ~Vector() = default;
    virtual const char *info() const = 0;

    // TODO non-copyable
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

    using Factories = VectorFactories;
    static Factories& getFactories() {
        static Factories factories {
            {"null", nullptr},
            {"", nullptr}
        };
        return factories;
    }
private:
    size_t _size;
};