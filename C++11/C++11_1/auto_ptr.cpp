
// auto_ptr是标准库提供的一种智能型指针(smart pointer),防止被异常
// 抛出时发生资源泄露，auto_ptr保证只要自己被摧毁，就一定连带释放
// 其所指资源，auto_ptr要求一个对象只能有一个拥有者，严禁一物二主

// std::auto_ptr<ClassA> ptr(new ClassA);

// auto_ptr拥有权的转移，令auto_ptr的copy函数和assignment操作符将
// 对象拥有权交出去

// 如果auto_ptr已传值的方式被当做一个参数传递给某函数,此时被调用的
// 函数的参数获得了这个auto_ptr的拥有权，如果函数不在将它传递出去，
// 它所指的对象就会在函数退出时被删除
// 当一个auto_ptr被返回时，其拥有权便被转交给调用端了
// 如果你无意转交拥有权，就不要在参数列表中使用auto_ptr，也不要以它
// 作为返回值
// 如果通过传引用方式传递，这样会使得拥有权的概念变得难以捉摸，应该
// 避免传引用方式

// 运用constant reference,通过一些技巧，可以令constant reference无法
// 交出拥有权
// const std::auto_ptr<int> p(new int);	// no ownership transfer possible
// const并非意味着不能更改auto_ptr所拥有的对象，而是不能更改auto_ptr的拥有权
// 使用const auto_ptr作为参数,对新对象的任何赋值操作都将导致编译期错误
// const auto_ptr比较类似于常量指针T* const p;而非指向常数的指针(const T* p)
// 尽管语法看上去像后者

// auto_ptr确实解决了一个特定问题，那就是在异常处理过程中的资源遗失问题
// 1.auto_ptr之间不能共享拥有权，一个auto_ptr不能指向另一个auto_ptr所
// 拥有的对象
// 2.并不存在针对array而设计的auto_ptr,auto_ptr不可以指向array,因为auto_ptr
// 是透过delete而非delete[]来释放其所拥有的对象，C++标准程序库并未提供针对
// array而设计的auto_ptr
// 3.auto_ptr绝非一个四海通用的智能型指针
// 4.auto_ptr不满足STL容器对其元素的要求，因为在拷贝和赋值之后，原本的auto_ptr
// 和新产生的auto_ptr并不相等

#include<iostream>
#include<memory>

using std::cout;
using std::endl;
using std::ostream;
using std::auto_ptr;

/* define output operator for auto_ptr
 * print object value or NULL
 * 第二个参数为const auto_ptr<T>&,所以并没有发生拥有权的转移
*/
template<class T>
ostream& operator <<(ostream& out, const auto_ptr<T>& p)
{
	// does p own an object?
	if (NULL == p.get())
		out << "NULL";
	else
		out << *p;
	return out;
}


int main()
{
	// int*无法隐式转换成auto_ptr,必须通过显示转换
	// 因为其构造函数被声明为explicit
	// auto_ptr<int> p1 = new int(32);		// error

	auto_ptr<int> p(new int(42));
	auto_ptr<int> q;

	cout << "after initialization: " << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << endl;

	q = p;
	cout << "after assigning auto pointers: " << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << endl;

	*q += 13;
	p = q;
	cout << "after change and reassignment: " << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << endl;

	system("pause");
	return 0;
}
