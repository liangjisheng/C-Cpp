#include"stdio.h"
#define n 5
void main()
{
	int i;
	float a[n],sum=0.0,aver;
	printf("input the a[n]:\n");
	for(i=0;i<n;i++)
		scanf("%f",&a[i]);
	for(i=0;i<n;i++)
		sum+=a[i];
	aver=sum/n;
	printf("the average is:%.4f\n",aver);
	float var,sum1=0;
	for(i=0;i<n;i++)
		sum1+=(a[i]-aver)*(a[i]-aver);
	var=sum1/n;
	printf("the var is:%.4f\n",var);
}




#include"iostream"
using namespace std;
int main()
{
	double x[1000],aver,s=0,xi,sum=0;
	int i=0,count;
	cout<<"input the number(exit for 1000):";
	while(1)
	{
		cin>>xi;
		if(xi==1000)break;
		x[i]=xi;
		i++;
		cout<<"input the number(exit for 1000):";
	}
	count=i;
	for(i=0;i<count;i++)
		sum=sum+x[i];
	aver=sum/count;
	cout<<"aver="<<aver<<endl;
	for(i=0;i<count;i++)
		s+=(x[i]-aver)*(x[i]-aver);
	cout<<"s="<<s<<endl;
	return 0;
}