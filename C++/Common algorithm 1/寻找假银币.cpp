#include"stdio.h"
#define maxnum 8
//flasecoin
int flasecoin(int coin[],int low,int high)
{
	int i,sum1,sum2,sum3,re;
	sum1=sum2=sum3=0;
	if(low+1==high){
		if(coin[low]<coin[high])return low+1;
		else return high+1;
	}
	if((high-low+1)%2==0){     //n是偶数
		for(i=low;i<=low+(high-low)/2;i++)
			sum1+=coin[i];
		for(i=low+(high-low)/2+1;i<=high;i++)
			sum2+=coin[i];
		if(sum1>sum2)
			return flasecoin(coin,low+(high-low)/2+1,high);
		else if(sum1<sum2)
			return flasecoin(coin,low,low+(high-low)/2);
		else {}
	}
	else{                    //n是奇数
		for(i=low;i<=low+(high-low)/2-1;i++)
			sum1+=coin[i];
		for(i=low+(high-low)/2+1;i<=high;i++)
			sum2+=coin[i];
		sum3=coin[low+(high-low)/2];
		if(sum1>sum2)
			return flasecoin(coin,low+(high-low)/2+1,high);
		else if(sum1<sum2)
			return flasecoin(coin,low,low+(high-low)/2-1);
		else
			return low+(high-low)/2+1;
	}
}
//main
int main()
{
	int coin[maxnum],i,n,weizhi;
	printf("寻找假银币问题求解.\n");
	printf("请输入银币总数:");
	scanf("%d",&n);
	printf("请输入银币的真假:");
	for(i=0;i<n;i++)
		scanf("%d",&coin[i]);
	weizhi=flasecoin(coin,0,n-1);
	printf("第%d个银币是假的.\n",weizhi);
	return 0;
}