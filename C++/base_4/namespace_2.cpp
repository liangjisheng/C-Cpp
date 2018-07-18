
/***********************************************************
 * @name: namespace_2.cpp
 * @brief: namespace
 * @author: Jisheng Liang
 * @date: 2018/7/11 17:12:16
 * @version: 1.0
 **********************************************************/

#include <iostream>

using namespace std;

namespace OutPut0 
{
	int ivar = 0;
	void put0(const char *ch)
	{
		cout << ch << endl;
	}
}

namespace OutPut1 
{
	int ivar = 1;
	void put1(const char *ch)
	{
		cout << ch << endl;
	}
}

int ivar = 10;

int main(int argc, char *argv[])
{
	cout << "ivar=" << ivar << endl;
	using namespace OutPut0;
	using namespace OutPut1;
	int ivar = 20;
	cout << "ivar=" << ivar << endl;
	cout << "OutPut0 ivar=" << OutPut0::ivar << endl;
	cout << "OutPut1 ivar=" << OutPut1::ivar << endl;
	put0("Welcome to Biejing.");
	put1("welcome to Heilongjiang.");
	OutPut0::put0("Welcome to Biejing.");
	OutPut1::put1("welcome to Heilongjiang.");

	getchar();
	return 0;
}
