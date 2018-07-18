
/***********************************************************
 * @name: static_2.cpp
 * @brief: static
 * @author: Jisheng Liang
 * @date: 2018/7/11 17:28:08
 * @version: 1.0
 **********************************************************/

#include <iostream>

using namespace std;

class CTest 
{
private:
	static int s_total;
	int id;
public:
	CTest() 
	{
		s_total++; id = s_total;
		cout << "构造:" << id << " " << endl; 
	}
	~CTest() 
	{
		s_total--; 
		cout << "析构:" << id << " " << endl; 
	}

	static int gettotal() { return s_total; }
};

int CTest::s_total = 0;

int main(int argc, char *argv[])
{
	CTest a, b, c;
	CTest *p = new CTest;
	cout << "合计=" << CTest::gettotal() << endl;
	delete p;
	cout << "合计=" << CTest::gettotal() << endl;

	getchar();
	return 0;
}
