#include <iostream>
#include <vld.h>
using namespace std;

int main()
{
	int array[5] = {1, 4, 3, 5, 2};
	for(int i = 0; i < 5; i++)
		cout << array[i] << " ";
	cout << endl;

	memset(array, 0, 5 * sizeof(int));
	for(int k = 0; k < 5; k++)
		cout << array[k] << " ";
	cout << endl;

	char *s = "GoldenGlobalView";
	//memset(s, 'G', 6);				//单步运行到这里会提示内存访问冲突
									//肯定会访问冲突，s指向的是不可写空间。
	printf("%s\n", s);

	system("pause");
	return 0;
}