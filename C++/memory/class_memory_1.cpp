
// 使用new/new[]操作时自动调用类的构造函数, 构造函数调用顺序是从基类
// 到子类逐层调用，成员变量可在构造函数主题执行前初始化，编译器会
// 自动安插基类构造函数调用代码，如需要传递参数，则需要显示的调用
// 基类的构造函数。
// 由于基类和子类的构造函数调用存在先后顺序，这意味着新对象的内存空间
// 初始化会因为构造函数的调用顺序儿呈现不同的状态: 即这个对象内存块
// 是一部分一部分初始化
// 构造函数中要避免调用虚函数，析构函数中要避免抛出异常


// 尽可能多的使用const修饰符
// 声明即初始化：变量、对象声明时就初始化
// 结构、类等实例变量都已指针变量方式使用
// 始终在使用前检测指针变量的有效性
// 指针和标量类型使用值传递，其它都使用指针和引用传递
// 多用智能指针: auto_ptr, shared_ptr,少用原始指针
// 多用new/delete/new[]/delete[]，少用malloc/free/realloc;
// 多用只读常量、局部变量,少用全局变量、静态变量
// 识别无符号和有符号的应用场景并正确选择数据类型
// 重视并修复编译器警告

#include <iostream>

using namespace std;


class Base
{
public:
	Base() : m_IntData(0) { Initialize(); }
	virtual ~Base() {}
	virtual void Initialize() { m_IntData = 10; }
private:
	int m_IntData;
};


class Derived : public Base
{
public:
	Derived() { m_pBuffer = malloc(4096); }
	virtual ~Derived() { free(m_pBuffer); }
	virtual void Initialize()
	{ strncpy((char*)m_pBuffer, "Testing...", _TRUNCATE); }
private:
	void* m_pBuffer;
};


void test_type_transform()
{
	short i = -3;
	unsigned short u = 0;
	cout << (u = i) << endl;

	i = 0;
	u = 65533;
	cout << (i = u) << endl;
}


int main()
{
	//Derived *pDerived = new Derived;
	//Base *pBase = dynamic_cast<Base*>(pDerived);
	//// 析构函数必须是virtual下面的这句话才能正确释放了内存，
	//// 首先调用基类的虚析构函数，然后调用子类的虚析构函数
	//delete pBase;
	//pBase = NULL;
	//pDerived = NULL;


	test_type_transform();

	system("pause");
	return 0;
}


