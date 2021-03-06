// 静态链接也叫做内部链接，static关键字表示具有静态链接
// 将static用于内部链接的另一种方式是使用匿名名称空间
// 可将变量或者函数封装到一个没有名字的名称空间，而不是使用static
// extern 关键声明具有外部链接性，
// C++中的static关键字的最终目的是创建离开和进入作用域时
// 都可以保留的局部变量。函数中的局部变量就像是一个只能在
// 函数内部访问的全局变量。静态变量最常见的用法是记住某个
// 函数是否执行了特定的初始化操作

// 静态变量令人迷惑，在构建代码时通常有更好的方法，以避免使用
// 静态变量。在次情况下，可编写一个类，用构造函数执行所需的初始化
// 避免使用单独的静态变量，为了维持状态可以改用对象

// 不同源文件中非局部变量的初始化顺序是不确定的
// C++没有提供规范，说明在不同源文件中初始化非局部变量的顺序。
// 如果在某个源文件中有一个全局变量x，在另一个文件中有一个全局
// 变量y,无法知道那个变量先初始化。通常，不需要关注这一规范的
// 缺失，但是如果某个全局变量或者静态变量依赖于另一个变量，就
// 可能引发问题。对象的初始化以为这调用构造函数，全局对象的构造
// 函数可能会访问另一个全局对象，并假定另一个对象已经构建，如果
// 这两个全局对象在不同源文件中声明，就不能指望一个对象在另一个
// 对象之前构建，也无法控制他们的初始化顺序。不同的编译器可能
// 有不同的初始化顺序，即使同一编译器的不同版本也可能如此，
// 甚至在项目中添加另一个文件也可能会影响初始化顺序
