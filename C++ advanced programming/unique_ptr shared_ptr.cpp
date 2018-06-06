
// 使用new[]分配n个对象的数组时，实际上分配了n个连续的内存块，
// 每个对象的无参构造函数会自动调用

// 在C++11之前，老的标准库包含了一个智能指针的简单实现，称为auto_ptr.
// 遗憾的是auto_ptr存在缺点，缺点之一是在STL容器中(例如vector)使用时,
// auto_ptr不能正常工作。C++已经正式废弃了auto_ptr,代之以shared_ptr
// 和unique_ptr,
// shared_ptr和unique_ptr之间的区别在于shared_ptr是引用计数的智能指针，
// 而unique_ptr不是，这意味着，可以有多个shared_ptr实例指向同一块动态分配
// 的内存，当最后一个shared_ptr离开作用域时，才释放这块内存。shared_ptr
// 也是线程安全的。
// 另一方面unique_ptr意味着所有权。单个unique_ptr离开作用域时，会释放底层
// 的内存。默认的智能指针是unique_ptr,只有需要共享资源时，才使用shared_ptr
// #include <memory>

#include <iostream>
#include <memory>
#include <stdio.h>

using std::cout;
using std::cerr;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using std::make_unique;
using std::make_shared;

class Simple
{
public:
	Simple() { cout << "Simple constructor called." << endl; }
	virtual ~Simple() { cout << "Simple destructor called." << endl; }
};


// unique_ptr默认使用表标准的new和delete运算符来分配和释放
// 内存，可以修改这个行为，
int* malloc_int(int value)
{
	int* p = (int*)malloc(sizeof(int));
	*p = value;
	return p;
}


// shared_ptr默认使用表标准的new和delete运算符来分配和释放
// 内存，可以修改这个行为，
void CloseFile(FILE* filePtr)
{
	if (nullptr == filePtr)
		return;
	fclose(filePtr);
	cout << "File closed." << endl;
}


int main()
{
	/*Simple* pSimple = new Simple[4];

	cout << endl;
	delete[] pSimple;
	pSimple = nullptr;*/

	unique_ptr<Simple> mySimpleSmartPtr(new Simple);

	// unique_ptr保存动态分配，包含10个整数的C风格数组
	auto myVariableSizedArray = make_unique<int[]>(10);

	
	// 修改unique_ptr的释放器
	auto deleter = [](int* p) { free(p); };
	unique_ptr<int, decltype(deleter)> myIntSmartPtr(malloc_int(42), deleter);


	// 总是使用make_shared创建shared_ptr
	auto mySimpleSmartPtr_1 = make_shared<Simple>();


	// 修改shared_ptr的释放器
	FILE* f = nullptr;
	fopen_s(&f, "data.txt", "w");
	shared_ptr<FILE> filePtr(f, CloseFile);
	if (nullptr == filePtr)
		cerr << "Error opening file." << endl;
	else
	{
		cout << "File opened." << endl;
		// Use filePtr
	}

	system("pause");
	return 0;
}