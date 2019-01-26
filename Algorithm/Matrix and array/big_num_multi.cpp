// 两个超大数相乘算法
#include"iostream"
using namespace std;

int main()
{
	int a[30],b[30],c[60];
	int i,j;
	// 初始化
	for(i=0;i<30;i++) {
	 	a[i]=i%10;
	 	b[i]=i%10;
		c[2*i]=0;
		c[2*i+1]=0;
	}
	
	// 计算每一位的值
	for(i=0;i<30;i++) {
		for(j=0;j<30;j++)
			c[i+j]+=a[i]*b[j];
	}
	// 把每位大于10的数进位，每一位重新赋值
	for(i=0;i<59;i++) {
		c[i+1]+=c[i]/10;
		c[i]=c[i]%10;
	}

	// print
	for(i=0;i<30;i++)
		cout<<a[30-i-1];
	cout<<endl;
	for(i=0;i<30;i++)
		cout<<b[30-i-1];
	cout<<endl;
	for(i=0;i<60;i++)
		cout<<c[60-i-1];
	cout<<endl;

	system("pause");
	return 0;
}