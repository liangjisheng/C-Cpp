
// 默认复制构造函数不会对类中的静态成员变量做任何改变，如果一个类中有
// 静态成员变量的话，需要我们显示写出类的复制构造函数

#include <iostream>

using std::cout;
using std::endl;

class myRect
{
private:
	int width;
	int height;
	static int count;
public:
	myRect() { count++; }
	~myRect() { count--; }
	static int getCount() { return count; }
};

int myRect::count = 0;


class myRect1
{
private:
	int width;
	int height;
	static int count;
public:
	myRect1() { count++; }
	myRect1(const myRect1 &r)
	{
		width = r.width;
		height = r.height;
		count++;
	}
	~myRect1() { count--; }
	static int getCount() { return count; }
};

int myRect1::count = 0;

int main()
{
	// 下面两次输出的结果都是1,但是确实有两个对象存在,因为默认的复制构造函数
	// 没有处理静态成员变量
	myRect r1;
	cout << "The count of myRect: " << myRect::getCount() << endl;
	myRect r2(r1);
	cout << "The count of myRect: " << myRect::getCount() << endl;
	cout << endl;

	// 自己处理复制构造函数的类,处理了静态成员变量
	myRect1 t1;
	cout << "The count of myRect1: " << myRect1::getCount() << endl;
	myRect1 t2(t1);
	cout << "The count of myRect1: " << myRect1::getCount() << endl;

	system("pause");
	return 0;
}