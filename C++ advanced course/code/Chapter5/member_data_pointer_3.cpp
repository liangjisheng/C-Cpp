
// 成员数据指针访问的是类的公有成员，如果用成员数据指针指向类的私有成员，使用不当
// 会引发编译错误

#include <iostream>

using std::cout;
using std::endl;

class HaveTwoArray
{
	int arr1[5];
	int arr2[5];
public:
	HaveTwoArray()
	{
		for(int i = 0; i < 5; i++)
		{
			arr1[i] = i + 1;
			arr2[i] = i + 5;
		}
	}

	friend void PrintArray(HaveTwoArray &s, int i);
};

// pm指向的是HaveTwoArray类中的有5个int类型元素的数组指针,将这个函数设置成
// 类HaveTwoArray的友元函数是不行的，因为是在调用函数的时候访问了类的私有成员，
// 所以，可以定义一个调用了PrintArray()的友元函数，该函数的参数中并不需要传递
// 类HaveTwoArray的私有成员
void PrintArray(HaveTwoArray &s, int (HaveTwoArray::* pm)[5])
{
	int *p;
	p = s.*pm;
	for(int i = 0; i < 5; i++)
		cout << p[i] << " ";
}


void PrintArray(HaveTwoArray &s, int i)
{
	if(1 == i)
		PrintArray(s, &HaveTwoArray::arr1);
	else if(2 == i)
		PrintArray(s, &HaveTwoArray::arr2);
}


int main()
{
	HaveTwoArray me;

	// PrintArray(me, &HaveTwoArray::arr2);

	PrintArray(me, 1);
	cout << endl;
	PrintArray(me, 2);
	cout << endl;

	system("pause");
	return 0;
}