#include"stdio.h"
int comb(int n,int m)
{
	if(n==m||m==0)
		return 1;
	else 
		return comb(n-1,m-1)+comb(n-1,m);
}
void main()
{
	int m,n,re;
	printf("input the n and m:");
	scanf("%d%d",&n,&m);
	if(m>n)
		printf("error please renew input!\n");
	else
		re=comb(n,m);
	printf("comb(%d,%d)=%d\n",n,m,re);
}


#include"iostream"
using namespace std;
int fun(int n)
{
	if(n==1||n==0)return 1;
	else return n*fun(n-1);
}
int main()
{
	int m,n;
	cout<<"input C(m,n):";
	cin>>m>>n;
	cout<<"C(m,n)="<<fun(n)/(fun(m)*fun(n-m))<<endl;
	return 0;
}