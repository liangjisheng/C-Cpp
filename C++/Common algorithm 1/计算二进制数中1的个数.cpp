// 计算一个unsigned int 二进制中1的个数
#include"iostream"
using namespace std;
int main()
{
	int n,count=0,temp;
	cout<<"input n:";
	cin>>n;
	temp=n;
	while(n){
		count+= n & 0x0001;
		n>>=1;
	}
	cout<<temp<<"二进制格式中1的个数为:"<<count<<endl;
	return 0;
}