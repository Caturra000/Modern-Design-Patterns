#include <memory>
#include <string>
#include <iostream>
#include <map>
#include <functional>
#include "Context.h"
// ContextImpl不需要.h文件

struct ContextImpl {
    // pimpl实现都需要接口类传递this，从而有机会使用到它的public部分
    void call(Context *context, const std::string &request);

// 本来应该是context的private部分
// 现在全部转移到impl类上
private:
    void add(const std::string &path);
    void del(const std::string &path);
    void fail();
};

void ContextImpl::call(Context *context, const std::string &request) {
    using Callback = std::function<void(ContextImpl*, const std::string&)>;
    using Router = std::map<std::string, Callback>;
    static Router router {
        {"add",    &ContextImpl::add},
        {"delete", &ContextImpl::del}
    };

    std::cout << context->server << " received request: " << request << std::endl;
    auto pivot = request.find_first_of(':');
    auto action = request.substr(0, pivot);
    auto query = router.find(action);
    if(query == router.end()) {
        fail();
    } else {
        auto &functor = query->second;
        functor(this, request.substr(pivot + 1));
    }
}

void ContextImpl::add(const std::string &path) {
    std::cout << path << " added." << std::endl;
}

void ContextImpl::del(const std::string &path) {
    std::cout << path << " deleted." << std::endl;
}

void ContextImpl::fail() {
    std::cout << "failed." << std::endl;
}