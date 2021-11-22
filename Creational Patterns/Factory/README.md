# Factory

## 前言

<del>当你觉得构造函数不好用的时候，用`factory`就对了</del>

我认为，`factory`最初的设想是为了解决构造函数本身只能是类名的限制。因为这个限制会影响类的表达能力<sup>1</sup>，比如：
- 你有一个类`Vector`，构造函数可以指定初始大小（`size`）或者底层容器的实际大小（`capacity`）
- 构造函数是`Vector(size_t)`，由于同时有两种需求，所以无法`Vector(size_t size)`和`Vector(size_t capacity)`共存
- 而`factory method`就简单了，本身是一个普通的函数，可以`makeWithSize(size_t)` / `makeWithCapacity(size_t)`轻易解决

这里的问题有两个：
1. `factory`只是解决了构造函数重载能力不足（或者说函数命名含糊）的缺点吗？
2. `factory`的形式到底是怎样？

## 作用

对于作用，我先做汇总：
1. 对于重载冲突，解决了构造函数表达能力不足（或者说函数命名含糊）
2. 对于实际场合，允许二阶段构造
3. 对于返回类型，符合面向接口的原则
4. 对于`template`，提供自动推导类型
5. 对于异常处理，提供构造时返回error code的可行性
6. 强化代码规范，比如返回类型必须是`std::shared_ptr<T>`
7. 提供对象池

TODO 细节后续补

至少你知道了为什么“当你觉得构造函数不好用的时候，用`factory`就对了”，因为它真的很实用（也易于实现）

## 实现形式

TODO

## 语言特性

推荐使用的`C++`语言特性有：
1. 禁止直接调用构造函数
2. 内部类、`using` / `typedef`：实现`inner factory`
3. `lambda`：实现匿名工厂类

## 进阶使用

当你在纠结它应该作为一个函数，还是作为一个类的时候，可以考虑`functional factory`形式

## <sup>1</sup> 关于构造函数的限制

并不是说构造函数本身一定干不了这种事情，可以解决的方式有：
1. 标签派发，设计构造函数形如`Vector(size_t, SizeTag)` / `Vector(size_t, CapacityTag)`
2. 封装类型，把`size`和`capacity`各封装为`Vector::Size`和`Vector::Capacity`类型
3. 使用枚举，`enum`blabla

但是这些处理方法只能解决我提到的第一个表达能力上的问题，对于`factory`所带来的其它若干特性（如二阶段构造），它都缺失
