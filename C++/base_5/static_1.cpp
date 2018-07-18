
/***********************************************************
 * @name: static_1.cpp
 * @brief: static
 * @author: Jisheng Liang
 * @date: 2018/7/11 17:26:38
 * @version: 1.0
 **********************************************************/

#include <iostream>

using namespace std;

class Data 
{
private:
	int level;
public:
	static int count;
	int maxlevel;
	Data(int i = 0, int max = 0) :level(i), maxlevel(max) {}
};

//静态成员分配内存并初始化
int Data::count = 0;

int main(int argc, char *argv[])
{
	cout << "static count=" << Data::count << endl;
	Data::count = 10;
	cout << "static count=" << Data::count << endl;
	Data d, *p = &d, &r = d;
	cout << "d.count=" << d.count << ",d.maxlevel=" << d.maxlevel << endl;
	cout << "p->count=" << p->count
		<< ",p->maxlevel=" << p->maxlevel << endl;
	cout << "r.count=" << r.count << ",r.maxlevel=" << r.maxlevel << endl;

	getchar();
	return 0;
}
