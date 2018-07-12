
// 将一个数组元素的所有排列方式列出，使用递归方法将所有元素的全排列
// 转化为一部分
// 例如：1 2 3 的全排列就是123,、132、213、231、312、321，用递归
// 方法就是1加上2,3全排列，然后1,2换位，2加上1,3的全排列，然后把
// 3换到最前面加上1,2的全排列。同样的如果是4个数就是第一位加上后
// 面的全排列，然后把每个数换到第一位，这样就可以把多位数的排列
// 转化为数比较少的排列，直到一个数的排列时打印

#include <iostream>

using namespace std;

void PrintArr(int *arr, int sz)
{
	for(int i = 0; i < sz; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// sz数组元素个数,n的代表除了前n位的全排列
void arrangement(int *arr, int sz, int n)
{
	if(n == sz)
	{
		PrintArr(arr, sz);
		return ;
	}

	for(int idx = n; idx < sz; ++idx)
	{
		std::swap(arr[n], arr[idx]);
		arrangement(arr, sz, n + 1);
		std::swap(arr[n], arr[idx]);
	}
}


int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	// 除了前两位的全排列
	arrangement(arr, 5, 3);

	system("pause");
	return 0;
}
