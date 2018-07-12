#include"iostream"
#include"ctime"
using namespace std;
int main()
{
	int n,seed,number,i=0;
	seed=time(0);
	srand((unsigned int)seed);
	n=rand()%100;
	cout<<"已经生成1到100之内的随机数"<<endl;
	while(i<5)
	{cout<<"Please input the number:";cin>>number;
	if(n>number)cout<<"number is smaller than n."<<endl;
	else if(n<number)cout<<"number is larger than n."<<endl;
	else {cout<<"Right,number is equal with n."<<endl;break;}
	i++;
	}
	cout<<"the game is over."<<endl;
	cout<<"n="<<n<<endl;
	return 0;
}