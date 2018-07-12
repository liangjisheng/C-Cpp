#include"stdio.h"
int mul(int num1,int num2)
{
	if(num2==1)
		return num1;
	else
		return num1+mul(num1,num2-1);
}
void main()
{
	int num1,num2,result;
	printf("input the num1:");
	scanf("%d",&num1);
	printf("input the num2:");
	scanf("%d",&num2);
	result=mul(num1,num2);
	printf("%d*%d=%d\n",num1,num2,result);
}
