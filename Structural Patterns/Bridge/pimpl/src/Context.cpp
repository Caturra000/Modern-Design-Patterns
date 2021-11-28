#include <memory>
#include <string>
#include "Context.h"
// 只有在.cpp我们才知道pimpl的声明
// #include "ContextImpl.h"
//
// 但是考虑到ContextImpl只会在Context实现中用到
// 因此直接把声明也写在实现里
// 这样可以进一步保证：.h就是接口，.cpp就是实现，而不会有impl.h这种意义不明的文件存在
#include "ContextImpl.cpp"

Context::Context(const char *server)
    : server(server),
      _impl(std::make_shared<ContextImpl>()) {}

void Context::call(const std::string &api) {
    // pimpl的固定实现模式
    _impl->call(this, api);
}
