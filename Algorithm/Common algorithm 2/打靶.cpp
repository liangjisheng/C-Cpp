// 运动员打靶，靶共有10环，连开10抢打中90环的可能性有多少种
// 每次打靶时，共有11中可能，0-10环，0环为脱靶
#include"iostream"
using namespace std;
int sum;
int store[10];

void output()
{
	for(int i=9;i>=0;--i)
		cout<<store[i]<<' ';
	cout<<endl;
	++sum;
}

void Cumput(int score,int num)
{
	if(score<0 || score>(num+1)*10)
		return ;
	if(num==0) {
		store[num]=score;
		output();
		return;
	}
	for(int i=0;i<=10;i++) {
		store[num]=i;
		Cumput(score-i,num-1);
	}
}

int main()
{
	Cumput(90,9);
	cout<<"总数为:"<<sum<<endl;

	system("pause");
	return 0;
}