
#include <iostream>

using std::cout;
using std::endl;

// 加上extern "C"，不会出现链接错误
extern "C"
{
	int value();
};


int main() 
{
	cout << value() << endl; 

	system("pause");
	return 0;
}
