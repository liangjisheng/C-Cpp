
/***********************************************************
 * @name: MemFuncThreadFunc.cpp
 * @brief: 将类的一个成员函数作为线程函数使用
 * @author: 梁基圣
 * @date: 2018/7/22 11:40:13
 * @version: 1.0
 **********************************************************/

// WaitForSingleObject, WaitForMultipleObjects
// Windows下创建的Object都会被赋予一个状态量。如果Object被激活了，或者正在使用，
// 那么该Object就是无信号，也就是不可用；另一方面，如果Object可用了，那么它就恢复有信号了
// 这两个函数的优点是它们在等待的过程中会进入一个非常高效沉睡状态，
// 只占用极少的CPU时间片。（这两个函数都是在内核状态下等待内核对象，
// 不切换到用户模式下，因而效率很高）

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class student
{
public:
	student()
	{
		m_handle = NULL;
		age = 13;
		name = "Member fun is ThreadFun.";
	}

	void printInfo(LPVOID pvParam);
	void startUp();

private:
	HANDLE m_handle;
	int age;
	string name;
};

// 联合类，用于转换类成员方法指针到普通函数指针
union
{
	void(*ThreadProc)(LPVOID pvParam);
	void (student::*MemberProc)(LPVOID pvParam);
}Proc;

void student::printInfo(LPVOID pvParam)
{
	student *ps = (student *)pvParam;

	// 线程每隔一段时间执行(5秒)
	while (WaitForSingleObject(ps->m_handle, 5000) != WAIT_OBJECT_0)
	{
		cout << "age = " << ps->age << endl;
		cout << "name = " << ps->name << endl;
	}
}

void student::startUp()
{
	// 指向成员函数
	Proc.MemberProc = &student::printInfo;
	// ThreadProc和MemberProc在共联体类中，所以也间接指向成员函数
	m_handle = CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(Proc.ThreadProc), this, 0, 0);
}


int main()
{
	student s1;
	s1.startUp();

	system("pause");
	_CrtDumpMemoryLeaks();

	return 0;
}
