
// !是一个一元操作符,通常用于表示bool,表示了逻辑取反，当在某个类中对!
// 操作符进行重载时，通常表明该类的对象出现了异常状况，例如可以对操作
// 符进行重载，以表明new生成的对象是否构造成功

#include <iostream>

using namespace std;

class A
{
	int m;
	char *str1;
	char *str2;
public:
	A(int n1, int n2, int n3)
	{
		str1 = new char[n1];
		str2 = new char[n2];
		m = n3;
	}

	~A()
	{
		delete []str1;
		str1 = NULL;
		delete []str2;
		str2 = NULL;
	}

	void show() { cout << m << endl; }
};

class A1
{
	int m;
	char *str1;
	char *str2;
public:
	A1(int n1, int n2, int n3)
	{
		str1 = new char[n1];
		str2 = new char[n2];
		m = n3;
	}

	~A1()
	{
		delete []str1;
		str1 = NULL;
		delete []str2;
		str2 = NULL;
	}

	void show() { cout << m << endl; }

	bool ObjOk()
	{
		if(str1 && str2) return true;
		else return false;
	}
};

// 通过对operator!操作符进行重载，可以判断一个类A2对象的数据成员是否存在问题
// (空间是否成功分配).这样普通的指针、文件指针、对象都可以统一地用operator!
// 来判断是否出现异常
class A2
{
	int m;
	char *str1;
	char *str2;
public:
	A2(int n1, int n2, int n3)
	{
		str1 = new char[n1];
		str2 = new char[n2];
		m = n3;
	}

	~A2()
	{
		delete []str1;
		str1 = NULL;
		delete []str2;
		str2 = NULL;
	}

	void show() { cout << m << endl; }

	// 重载operator!表示对象的建立是否有异常
	bool operator!()
	{
		if(str1 && str2) return false;
		return true;
	}
	// 可以作为类成员函数，也可以作为友元函数
	// friend bool operator!(const A2 &a);
};

//bool operator!(const A2 &a)
//{
//	if(a.str1 && a.str2) return false;
//	else return true;
//}


int main()
{
	// 在大多数情况下,类A的分配可以正常编译运行,但这样写下面的4行程序是
	// 存在缺陷的,因为用new操作在堆上申请空间,有可能会失败.因此,更为稳健
	// 的做法是对所有的new操作结果进行测试，已确保对象被成功的创建,修改后
	// 的类为类A1
	A *p = new A(4, 5, 6);
	p->show();
	delete p;
	p = NULL;

	// 像ObjOk()这样的程序调用带有浓厚的程序员的个人风格,通过重载该类的
	// operator!操作符，就可以将对象的检测工作统一表示:类A2
	A1 *p1 = new A1(4, 5, 6);
	if(p1 && p1->ObjOk())
		p1->show();
	delete p1;
	p1 = NULL;

	A2 *p2 = new A2(4, 5, 6);
	if(!p2 || !(*p2))
		cout << "new operator failed" << endl;
	else
		p2->show();
	delete p2;
	p2 = NULL;

	system("pause");
	return 0;
}