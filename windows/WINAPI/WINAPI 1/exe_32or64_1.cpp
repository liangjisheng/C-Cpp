
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	void *pVoid = NULL;
	// 输出4就是32位的exe,输出8就是64位的exe
	cout << sizeof(pVoid) << endl;

	system("pause");
	return 0;
}