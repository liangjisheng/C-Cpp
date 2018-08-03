
/***********************************************************
 * @name: GlobalThreadFunc.cpp
 * @brief: 全局线程函数
 * @author: 梁基圣
 * @date: 2018/7/22 10:54:32
 * @version: 1.0
 **********************************************************/

// 回调函数是用指针来调用的函数，最常使用的回调函数就是在创建线程时，
// 以一个函数指针以及传递给这个函数多个参数来调用线程函数来创建线程。
// 那么一般的类成员函数是不能用作回调函数的，因为库函数在使用回调函数时，
// 都会传递指定的符合回调函数声明的的参数给回调函数，而类成员函数隐式
// 包含一个this指针参数，所以把类成员函数当作回调函数编译时因为参数不匹配会出错

// 如果类内成员函数调用回调函数怎么实现呢？一般有两种方法:
// 1.回调函数声明在类外，全局的传类对象指针给回调函数即可使用类内成员，
// 因为回调函数是全局的所以影响了类的封装性
// 2.类内成员函数作为回调函数利用关键名static声明类内成员函数，因为
// 类静态成员函数只能操作类静态成员，所以函数若想访问类成员，只能通过
// 调用函数传递类对象指针给回调函数，或者在类内声明一个静态指针，
// 该指针指向类，然后在函数中调用该指针访问类成员

#include <iostream>
#include <windows.h>

using namespace std;

DWORD WINAPI TestFun(LPVOID lpParam);

class myThread 
{
public:
	myThread(int n, int m) : Num(n), Test(m), hThread(NULL) {}
	int Test;
	int Num;
	int ThreadNew();
	HANDLE hThread;
};

int myThread::ThreadNew()
{
	hThread = CreateThread(NULL, 0, TestFun, this, 0, NULL);
	return 0;
}

DWORD WINAPI TestFun(LPVOID lpParam)
{
	myThread *pThread = (myThread *)lpParam;
	cout << pThread->Num << " " << pThread->Test << endl;
	return 0;
}

int main()
{
	myThread TestData(1, 2);
	TestData.ThreadNew();

	WaitForSingleObject(TestData.hThread, INFINITE);
	CloseHandle(TestData.hThread);

	return 0;
}
