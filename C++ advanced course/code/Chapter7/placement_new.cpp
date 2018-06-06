
// 一般来说，使用new申请空间时，是从系统的堆(heap)中分配空间，申请所得的空间的
// 位置是根据当时的内存的实际使用情况决定的，但是在某些特殊的情况下，可能需要
// 在程序员指定的特定内存处创建对象，这就是所谓的定位放置new(placement new)操作

#include <iostream>
#include <new>			// for placement new

using namespace std;

// 使用定位放置new，既可以在堆栈(stack)上生成对象，也可以在堆(heap)上生成对象
// 本例是在栈上生成一个对象

class A
{
	int num;
public:
	A() { cout << "A" << endl; }
	~A() { cout << "~A" << endl; }
	void show() { cout << num << endl; }
};

int main()
{
	char memory[100] = {0};
	memory[0] = 'a';
	memory[1] = 0;
	memory[2] = 0;
	memory[3] = 0;
	cout << (void*)memory << endl;

	// 定位生成对象时，会自动调用类的构造函数，但由于对象的空间不会自动释放
	// 所以必须显示的调用类的析构函数
	// 万不得已时才使用placement new语法，只有当你真的在意对象在内存中的特定
	// 位置时才使用它，例如你的硬件有一个内存映像的I/O计时器设备，并且你想
	// 放置一个Clock对象在那个内存位置
	A *p = new(memory) A;
	cout << p << endl;
	p->show();
	p->~A();

	system("pause");
	return 0;
}