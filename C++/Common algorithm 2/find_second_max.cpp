// 找出整数数组中第二大的数
#include"iostream"
using namespace std;

int find_second_max(int data[],int num)
{
	int max_1=data[0];
	int max_2;
	if(data[1]>max_1)
	{ max_1=data[1]; max_2=data[0]; }
	else
		max_2=data[1];

	for(int i=2;i<num;i++) {
		if(data[i]>max_1)
		{ max_2=max_1; max_1=data[i]; }
		else if(data[i]<max_1 && data[i]>max_2)
		{ max_2=data[i]; }
	}
	return max_2;
}

int main()
{
	int max_2=0;
	int data[]={6,5,4,3,2,1,0,11,10,9,8,7};
	int n=sizeof(data)/sizeof(int);
	cout<<"总共有"<<n<<"个数"<<endl;
	max_2=find_second_max(data,n);
	cout<<"数组中第二大的数是"<<max_2<<endl;

	system("pause");
	return 0;
}