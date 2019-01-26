#include"stdio.h"
int ga[50],gb[50];                           //存放因子
//friendnum
int friendnum(int a)
{
	int i,b=0,b1=0,j=0;
	for(i=0;i<50;i++)ga[i]=0,gb[i]=0;
	for(i=1;i<=a/2;i++)
	{if(a%i==0)ga[j++]=i,b+=i;}
	j=0;
	for(i=1;i<=b/2;i++)
	{if(b%i==0)gb[j++]=i,b1+=i;}
	if(b1==a&&a<b)return b;
	else return 0;
}
//main
void main()
{
	int i,n,b=0,j=1;
	printf("求从1到n的亲密数.\n");
	printf("input n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		b=friendnum(i);
		if(b!=0){
			printf("%d-%d是亲密数.\n",i,b);
			printf("%d=%d",i,ga[0]);
			while(ga[j]>0)
			{printf("+%d",ga[j]);j++;}
			printf("=%d\n",b);
			j=1;
			printf("%d=%d",b,gb[0]);
			while(gb[j]>0)
			{printf("+%d",gb[j]);j++;}
			printf("=%d\n",i);
		}
	}
}