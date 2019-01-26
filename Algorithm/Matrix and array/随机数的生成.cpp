#include"iostream"
#include"cmath"
#include"cstdlib"
#include"ctime"
using namespace std;
int main()
{
	double d;
	int i,n,seed;
	seed=time(0);   //以系统流逝时间为随机数发生器种子
	srand((unsigned int )seed);
	int a,b,c;
	a=rand(),b=rand(),c=rand();
	for(i=0;i<10;i++)
	{
		n=rand()%20;//产生0到20的随机整数
		d=rand()/(double)RAND_MAX;//产生0到1的随机整数
		cout<<n<<" "<<d<<endl;
	}
	cout<<"a="<<a<<",b="<<b<<",c="<<c<<endl;
	return 0;
}


#include"iostream"
#include"cmath"
#include"cstdlib"
#include"ctime"
using namespace std;
int main()
{
	double d;
	int i,n;//,seed;
	srand(3);
	//seed=time(0);
	//srand((unsigned int )seed);
	int a,b,c;
	a=rand(),b=rand(),c=rand();
	for(i=0;i<10;i++)
	{
		n=rand()%20;
		d=rand()/(double)RAND_MAX;
		cout<<n<<" "<<d<<endl;
	}
	cout<<"a="<<a<<",b="<<b<<",c="<<c<<endl;
	return 0;
}