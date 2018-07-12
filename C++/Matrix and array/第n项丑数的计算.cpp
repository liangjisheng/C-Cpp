一个能被2或3或5或7整除的数称为Humble Number(简称丑数)
数列{1,2,3,4,5,6,7,8,9,10,12,14,15,16,18,......}是前15个丑数(把1也算作丑数)。
编程输入n(1<=n<=5842),输出这个数列的第n项。

#include"iostream"
using namespace std;
int main()
{
	int cnt=0,n,h=0,t;
	cout<<"Please input the n:";cin>>n;
	while(cnt<n)
	{
		h++;t=h;
		while(t%2==0)t=t/2;
		while(t%3==0)t=t/3;
		while(t%5==0)t=t/5;
		while(t%7==0)t=t/7;
		if(t==1)cnt++;
	}
	cout<<"第n项丑数为:"<<h<<endl;
	return 0;
}


#include"iostream"
using namespace std;
//求四个数最小值
int min(int a,int b,int c,int d)
{
	a=a>b?b:a;
	c=c>d?d:c;
	return a>c?c:a;
}
//main
int main()
{
	int i=1,j=1,k=1,m=1,n=1;
	int a[6000]={1,1};
	for(n=2;n<=5842;n++)
	{
		int t1,t2,t3,t4;
		t1=a[i]*2,t2=a[j]*3,t3=a[k]*5,t4=a[m]*7;
		a[n]=min(t1,t2,t3,t4);
		if(a[n]==t1)i++;
		if(a[n]==t2)j++;
		if(a[n]==t3)k++;
		if(a[n]==t4)m++;
	}
	cout<<"Please input the n:";cin>>n;
	cout<<"第n个丑数为:"<<a[n]<<endl;
	return 0;
}