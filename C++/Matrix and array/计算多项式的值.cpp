#include"iostream"
using namespace std;
#define n 5
int main()
{
	cout<<"计算x*x*x+3*x*x+1多项式的值."<<endl;
	double a[n+1]={1,0,0,3,0,1},b0=a[0],b1,x;
	int i;
	cout<<"input x:";cin>>x;
	for(i=0;i<n;i++){
		b1=x*b0+a[i+1];
		b0=b1;
	}
	cout<<"the result is:"<<b1<<endl;
	return 0;
}