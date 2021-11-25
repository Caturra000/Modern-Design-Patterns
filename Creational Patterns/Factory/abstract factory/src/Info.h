#pragma once

// 一个Vector中的组件
// 这里暂且用繁琐的多态来展示用法
struct Info {
    virtual const char *text() = 0;
};