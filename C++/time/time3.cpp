//获得当前的计数频率，即每秒进行多少次计数
// QueryPerformanceFrequency(&limtp);

//获得当前计数次数，基于cpu级的
//QueryPreformanceCounter(&limtp);

#include"ctime"
#include"iostream"
using namespace std;

int main() {
	time_t s,e,time;
	s=clock();
	for(int i=0;i<50000;i++)
		cout<<i<<" ";
	cout<<endl;
	e=clock();
	time=e-s;
	cout<<endl<<"time:"<<time<<endl;
	system("pause");

	return 0;
}