
/***********************************************************
 * @name: recursion_1.cpp
 * @brief: recursion
 * @author: Jisheng Liang
 * @date: 2018/7/11 11:37:39
 * @version: 1.0
 **********************************************************/

#include <iostream>

using namespace std;

void fun1(char ch)
{
	if ('A' <= ch && ch <= 'H')
	{
		cout << ch << " "; 
		fun1(ch - 1);
	}
	else 
		cout << endl;
}

void fun2(char ch)
{
	if ('A' <= ch && ch <= 'H')
	{
		fun2(ch - 1);
		cout << ch << " ";
	}
	else
		cout << endl;
}

void fun3(char ch)
{
	if ('A' <= ch && ch <= 'H')
	{
		fun3(ch + 1);
		cout << ch << " ";
	}
	else 
		cout << endl;
}

void fun4(char ch)
{
	if ('A' <= ch && ch <= 'H')
	{
		cout << ch << " "; 
		fun4(ch + 1);
	}
	else
		cout << endl;
}

void fun5(char ch, int n)
{
	if (n <= 0)
		cout << endl;
	else {
		fun5(ch - 1, n - 1);
		cout << ch;
		fun5(ch + 1, n - 1);
	}
}

int main()
{
	//cout << "func1: ";
	//fun1('D');
	//cout << endl;
	//
	//cout << "func2: ";
	//fun2('D');
	//cout << endl;
	//
	//cout << "func3: ";
	//fun3('D');
	//cout << endl;
	//
	//cout << "func4: ";
	//fun4('D');
	//cout << endl;
	//cout << endl;

	cout << "func5: " << endl;
	fun5('M', 1);
	cout << "end" << endl;
	fun5('M', 2);
	cout << "end" << endl;
	fun5('M', 3);
	cout << "end" << endl;
	fun5('M', 4);
	cout << "end" << endl;

	getchar();
	return 0;
}
