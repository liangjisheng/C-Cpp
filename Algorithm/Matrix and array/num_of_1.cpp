#include"iostream"
using namespace std;

// 计算x中所含有1的个数
int fun(unsigned int x)
{
	int count=0;
	while(x) {
		x=x & (x-1);
		count++;
	}
	return count;
}

int main()
{
	unsigned int n=9999;
	for(int i=0;i<100;i++)
		cout<<i<<"中所含1的个数为:"<<fun(i)<<endl;

	system("pause");
	return 0;
}