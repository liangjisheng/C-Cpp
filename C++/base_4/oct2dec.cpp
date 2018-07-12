//八进制转换为十进制
//C++版本
/*#include"iostream"
using namespace std;
int main(int argc,char *argv[])
{
	int num;
	cout<<"input a number(oct):";
	cin>>oct>>num;
	cout<<dec<<num<<endl;
	return 0;
}*/
//C版本
#include"stdio.h"
int main(int argc,char *argv[])
{
	int num;
	printf("input a number(oct):");
	scanf("%o",&num);
	printf("%d\n",num);
	return 0;
}