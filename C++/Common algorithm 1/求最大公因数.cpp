递归求最大公因数
#include"stdio.h"
int gcd(int num1,int num2)
{
	if(num2==0)
		return num1;
	else
		return gcd(num2,num1%num2);
}
void main()
{
	int num1,num2,result;
	printf("input the num1 and num2:");
	scanf("%d%d",&num1,&num2);
	if(num1<num2)
	{result=num1;num1=num2;num2=result;}
	result=gcd(num1,num2);
	printf("%d和%d的最大公因数是:%d\n",num1,num2,result);
}

非递归求最大公因数
#include"stdio.h"
void main()
{
	int num1,num2,re,m,n;
	printf("input the num1 and num2:");
	scanf("%d%d",&num1,&num2);
	m=num1;n=num2;
	if(m<n)
	{re=m;m=n;n=re;}
	while(n!=0)
	{
		re=m%n;
		m=n;
		n=re;
	}
	printf("%d和%d的最大公因数是%d\n",num1,num2,m);
}

//gcd
int gcd(int a,int b)
{
	int m,n;
	if(a>b)m=a,n=b;
	else m=b,n=a;
	if(n==0)return m;
	if(m%2==0&&n%2==0)
		return 2*gcd(m/2,n/2);
	if(m%2==0)return gcd(m/2,n);
	if(n%2==0)return gcd(m,n/2);
	return gcd((m+n)/2,(m-n)/2);
}