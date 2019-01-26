#include"stdio.h"
#include"math.h"
void main()
{
	int i,count=0,n1,n2,k=1,j;
	printf("input the n1 and n2:");
	scanf("%d%d",&n1,&n2);
	printf("输出n1与n2之间素数:\n");
	for(i=n1;i<=n2;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i>2&&i%j==0)
			{k=0;break;}
		}
		if(k)
		{
			printf("%5d",i);
			count++;
			if(count%5==0)
				printf("\n");
		}
		k=1;
	}
	printf("\n在n1与n2之间的素数共有:%d个\n",count);
}



#include"iostream"
#include"cassert"
#include"bitset"
using namespace std;
int main()
{
	const int MAX_PRIME=1000;//长度n的上限
	int n;
	cout<<"This program finds primes in the range 2-n."<<endl
		<<"Enter positive integer n<="<<MAX_PRIME<<": ";
	cin>>n;
	assert(n>0&&n<=MAX_PRIME);//检测机制
	bitset<MAX_PRIME+1> sieve;//定义一个位集
	sieve.set();//将所有位设置为1
	//求在2-n之间的素数
	int prime=2;
	while(prime*prime<=n){
		for(int mult=2*prime;mult<=n;mult+=prime)
			sieve.reset(mult);//将第mult位设置为0
		do{prime++;}while(!sieve.test(prime));//若第prime位为0,则prime++
	}
	cout<<"\nPrimes in the range 2 through"<<n<<":\n";
	for(int i=2;i<=n;i++){
		if(sieve.test(i))
			cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}