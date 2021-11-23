# Builder

## 概述

`Builder`适用于替代复杂的<sup>1</sup>构造函数

常用的形式就是`fluent builder`，也就是带有链式调用的写法

## 语言特性

在`C++`中推荐搭配使用的语言特性有：
- 禁止直接调用构造函数
- `operator`隐式转换类型
- 内部类和`auto`推导
- [可选]初始化列表

关于可选项初始化列表，见下方进阶使用章节

## 进阶使用

`builder`搭配初始化列表可以写出形如脚本语言的代码

例子：[Caturra/dlog/dlog.conf](https://github.com/Caturra000/dLog/blob/master/dlog.conf)

上面是一个编译时确认的配置清单，代码文件本身仍是`C++`实现

## 注意点

`builder`本身是为了简化构造流程而设计的

如果你遇到了`template`，既类型本身是个类模板，且`typename`依赖于构造函数的参数类型

而`builder`却需要显式声明需要的**所有**`typename`（因为我需要知道这个实例化的`class`是什么）

通常比直接写构造函数还要复杂（由于前提条件是复杂构造函数<sup>1</sup>，因此无法搭配`factory`解决）

<sup>1</sup> 具体是指你的参数太多了，或者是参数的顺序存在争议。反例：[AOSP/frameworks/Activity/startActivityLocked](https://cs.android.com/android/platform/superproject/+/android-6.0.0_r41:frameworks/base/services/core/java/com/android/server/am/ActivityStackSupervisor.java;drc=f1ddb5e090d553bf6ddc50a35b455fade3e905b4;l=1399)
