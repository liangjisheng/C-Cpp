// 10个整数，有正有负，找出连续3个数之和最大的部分
#include"iostream"
using namespace std;

int main()
{
	int a[10]={-3,4,6,8,-9,7,10,-6,20,-9};
	int sum=a[0]+a[1]+a[2];
	int index=0;
	for(int i=1;i<8;i++) {
		if(sum<a[i]+a[i+1]+a[i+2]) {
			sum=a[i]+a[i+1]+a[i+2];
			index=i;
		}
	}
	cout<<"index is:"<<index+1<<endl;
	cout<<"sum="<<sum<<endl;

	system("pause");
	return 0;
}