#include"iostream"
#include"ctime"
using namespace std;
int main()
{
	cout<<"总共有100座山，每次搬山的个数不超过5个，人先开始。"<<endl;
	int n=100,com,people;
	cout<<"Please input(0-5):";cin>>people;
	int seed;
	seed=time(0);
	srand(seed);
	com=rand()%5;
	while(n>0)
	{
		n=n-people;
		if(n<=0)
		{cout<<"人搬完了最后一座山，人输了。"<<endl;break;}
		n=n-com;
		if(n<=0)
		{cout<<"电脑搬完了最后一座山，电脑输了。"<<endl;break;}
		cout<<"剩余"<<n<<"座山"<<endl;
		cout<<"Please input(3-5):";cin>>people;
		com=rand()%5;
	}
	return 0;
}