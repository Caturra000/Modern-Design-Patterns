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

    // 为什么不用Functor _functor，而要用指针形式？
    // 至少我们需要多态的支持
    // 但正如前面所说的，不知道具体的类型，就无法真正地copy
    //
    // 那么，改用std::shared_ptr通过引用计数来代替copy行为可不可以？
    // 就行为而言，引入引用计数确实能表面上替换掉copy（起码能填上被delete的两个函数）
    // 但是这样的话FunctorImpl里面的_callable就处于共享的状态。这对于仿函数来说，不一定是期望的做法
    Functor *_functor;
};