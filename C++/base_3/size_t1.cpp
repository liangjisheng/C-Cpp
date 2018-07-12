#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int i;
	size_t size=sizeof(i);
	cout << "sizeof(int) = " << size << endl; 
	i=(int)size;				//size_t类型的值可以转化为int类型的值
	cout << "i = " << i << endl;
	char c='a';
	wchar_t wc=L'a';			//注意'a'表示字符a，L'a'表示宽字符a
	
	int arr[]={1,2,3,4,5};
	int* p1=&arr[0];			//取得数组中元素的地址，赋值给指针
	int* p2=&arr[3];
	ptrdiff_t diff=p2-p1;		//指针的减法可以计算两个指针之间相隔的元素个数
	cout << diff << endl;
	i=(int)diff;				//ptrdiff_t类型的值可以转化为int类型的值
	cout << "i= " << i << endl;
	
	return 0;
}
