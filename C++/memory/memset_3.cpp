#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char a[5];
	memset(a, '1', 5);
	for(int i = 0; i < 5; i++)
		cout<< a[i] << " ";
	cout << endl;


	// 而aInt是整型的，使用 memset还是按字节赋值， 这样赋值完以后，
	// 每个数组元素的值实际上是0x01010101即十进制的16843009
	int aInt[5];
	memset(aInt, 1, 20);
	//也等价于memset(a,1,sizeof(a));.
	for(int i = 0; i < 5; i++)
		cout<<aInt[i]<<" ";
	cout << endl;

	system("pause");
	return 0;
}