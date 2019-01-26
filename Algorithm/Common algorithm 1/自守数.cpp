#include"stdio.h"
#include"math.h"
//zishounum
int zishounum(long n)
{
	long t,m,k=1;
	int count=0;
	while(k>0)
	{k=n-(long)pow(10,count);count++;}
	m=count-1;
	t=(n*n)%((long)pow(10,m));
	if(t==n)return 1;
	else return 0;
}
//main
void main()
{
	long i;
	for(i=2;i<1000;i++)
	{if(zishounum(i)==1)printf("%ld,",i);}
	printf("\n");
}

ийие2
//zishounum
int zishounum(long num)
{
	long fac,mod,n_mod,p_mod,t,n;
	fac=num;mod=1;
	do{
		mod*=10;
		fac/=10;
	}while(fac>0);
	p_mod=mod;
	fac=0;
	n_mod=10;
	while(mod>0){
		t=num%(mod*10);
		n=num%n_mod-num%(n_mod/10);
		t=t*n;
		fac=(fac+t)%p_mod;
		mod/=10;
		n_mod*=10;
	}
	if(num==fac)return 1;
	else return 0;
}