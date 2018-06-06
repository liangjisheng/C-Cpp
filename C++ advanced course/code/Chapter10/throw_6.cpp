
// 传递参数和传递异常最后一点差别是：catch子句匹配顺序总是取决于他们在程序中
// 出现的顺序.因此一个派生类异常可能被处理其基类异常的catch子句捕获,即使同时
// 存在有能处理该派生类异常的catch子句与相同的try块相对应

#include <iostream>

using namespace std;

class stuff
{
	int n;
	char c;
public:
	stuff() { n = c = 0; }
};

class SpecialStuff : public stuff
{
	double d;
public:
	SpecialStuff() { d = 0.0; }
};


int main()
{
	SpecialStuff localStuff;
	try{
		throw localStuff;
	}
	catch(stuff &){
		cout << "stuff catched" << endl;
	}
	catch(SpecialStuff&){
		cout << "SpecialStuff catched" << endl;
	}

	system("pause");
	return 0;
}
