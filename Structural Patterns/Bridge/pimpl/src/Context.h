#pragma once
#include <string>
#include <memory>

// 在header中并不需要知道impl的具体内容
// 保持为不完整类型即可
struct ContextImpl;

// Context基本只有public接口
// 要达成这种目的并不需要virtual来完成接口和实现的分离
struct Context {
public:

    // 构建一个连接上下文
    Context(const char *server);

    // 需要获取远程调用，只能调用某些api
    void call(const std::string &api);

public:

    // 需要连接到的服务器
    const char *server;

// 除了pimpl以外，这个提供给用户的header没有任何private
private:
    // _impl的具体内容隐藏在cpp里面
    std::shared_ptr<ContextImpl> _impl;
};