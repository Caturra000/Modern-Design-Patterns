#pragma
#include <utility>

template <typename ...>
struct Function;

// 模仿实现一个简单的std::function
template <typename Ret, typename ...Args>
struct Function<Ret(Args...)> {

    // 用于泛型擦除
    struct Functor {
        virtual Ret operator()(Args &&...args) = 0;
        virtual ~Functor() = default;
    };

    template <typename C>
    struct FunctorImpl: Functor {
        FunctorImpl(C c): _callable(std::move(c)) {}
        Ret operator()(Args &&...args) override {
            return _callable(std::forward<Args>(args)...);
        }
        C _callable;
    };

    template <typename C>
    Function(C callable): _functor(new FunctorImpl<C>(std::move(callable))) {}

    ~Function() { delete _functor; }

    // 注意，这里copy相关的接口都被禁止了
    // 毕竟你不知道该怎么copy一个被擦除具体类型的指针
    Function(const Function &that) = delete;
    // 移动相关的操作是没有问题的
    // 只需要对所有权进行转移即可
    Function(Function &&that): _functor(that._functor) { that._functor = nullptr; }

    Function& operator=(const Function &that) = delete;
    Function& operator=(Functor &&that) {
        Function(std::move(that)).swap(*this);
        return this;
    }

    Ret operator()(Args &&...args) {
        return (*_functor)(std::forward<Args>(args)...);
    }

    Functor *_functor;
};