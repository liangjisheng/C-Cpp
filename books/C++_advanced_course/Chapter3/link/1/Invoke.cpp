
#include <iostream>

using std::cout;
using std::endl;

// ����extern "C"������������Ӵ���
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
