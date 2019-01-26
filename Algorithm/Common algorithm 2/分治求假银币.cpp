#include"stdio.h"
#define maxnum 30
//false_coin
int false_coin(int coin[],int low,int high)
{
	int i,sum1,sum2,sum3,re;
	sum1=sum2=sum3=0;
	if(low+1==high)
	{
		if(coin[low]<coin[high]){re=low+1;return re;}
		else {re=high+1;return re;}
	}
	if((high-low+1)%2==0)
	{
		for(i=low;i<=low+(high-low+1)/2;i++)      //前半段和
			sum1+=coin[i];
		for(i=low+(high-low)/2+1;i<=high;i++)     //后半段和
			sum2+=coin[i];
		if(sum1>sum2){re=false_coin(coin,low+(high-low)/2+1,high);return re;}
		else if(sum1<sum2){re=false_coin(coin,low,low+(high-low)/2);return re;}
		else{}
	}
	else
	{
		for(i=low;i<=low+(high-low)/2-1;i++)
			sum1+=coin[i];
		for(i=low+(high-low)/2+1;i<=high;i++)
			sum2+=coin[i];
		sum3=coin[low+(high-low)/2];
		if(sum1>sum2){re=false_coin(coin,low+(high-low)/2+1,high);return re;}
		else if(sum1<sum2){re=false_coin(coin,low,low+(high-low)/2-1);return re;}
		else {}
		if(sum1+sum3==sum2+sum3){re=low+(high-low)/2+1;return re;}
	}
}
//main
void main()
{
	int coin[maxnum],i,n,weizhi;
	printf("分治方法求解假银币问题.\n");
	printf("Please input the number of coin:");
	scanf("%d",&n);
	printf("请输入银币的真假:");
	for(i=0;i<n;i++)
		scanf("%d",&coin[i]);
	weizhi=false_coin(coin,0,n-1);
	printf("在上述%d个银币中,第%d个银币是假的!\n",n,weizhi);
}