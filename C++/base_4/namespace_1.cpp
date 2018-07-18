
/***********************************************************
 * @name: namespace_1.cpp
 * @brief: namespace
 * @author: Jisheng Liang
 * @date: 2018/7/11 17:10:11
 * @version: 1.0
 **********************************************************/

#include <iostream>

using namespace std;

namespace OutPut 
{
	const int MAXLEN = 128;
	int ivar = 10;
	void PutText(const char *pchdata)
	{
		if (pchdata != NULL)
			cout << pchdata << endl;
	}
}

namespace Windows {
	typedef unsigned int UINT;
	void PutText(const char *pchdata)
	{
		if (pchdata != NULL)
			cout << pchdata << endl;
	}
}

int main(int argc, char* argv[])
{
	OutPut::PutText("Welcome to Beijing.");
	Windows::PutText("Welcome to GHINA.");

	getchar();
	return 0;
}
