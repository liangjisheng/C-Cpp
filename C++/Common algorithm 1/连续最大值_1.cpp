// 数组a[n],元素不是为-1就是为1,找出a[i]到a[j]中连续数最大的部分
#include"iostream"
using namespace std;

int main()
{
	int a[]={1,-1,-1,1,1,-1,1,1,1,1,-1,-1,-1,1,1,1,1,1,-1};
	int n=sizeof(a)/sizeof(int);
	int i,begin,end,sum=0,len,index;
	int result=0;
	for(i=0;i<n;) {
		if(a[i]==-1) i++;
		else {
			sum=0;
			begin=i;
			while(a[i]!=-1) {
				sum=sum+a[i];
				i++;}
			end=i;
			if(result<sum)
				result=sum,len=end-begin,index=begin;
		}
	}
	cout<<"index is:"<<index+1<<endl;
	cout<<"sum is:"<<result<<endl;

	system("pause");
	return 0;
}