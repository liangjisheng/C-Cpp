// 将函数指针应用到STL算法中
#include"iostream"
#include"tchar.h"
#include"vector"
#include"ctime"
#include"cstdlib"
#include"algorithm"
using namespace std;

bool countData(int n) { return n>100; }
bool countData1(int nStandard,int n) { return n>nStandard; }
void print(int n) { cout<<n<<' '; }

int _tmain(int argc,_TCHAR* argv[])
{
	int nStandard=80;
	srand(time(NULL));
	vector<int> vec;
	for(int i=0;i<10;i++) {
		int temp=rand()%100+50;
		vec.push_back(temp);
	}
	cout<<"Data:"<<endl;
	for_each(vec.begin(),vec.end(),print);
	cout<<endl;

	int nCount=count_if(vec.begin(),vec.end(),countData);
	cout<<"greater than 100="<<nCount<<endl;

	int nCount1=count_if(vec.begin(),vec.end(),
		bind1st(ptr_fun(countData1),nStandard));
	cout<<"greater than "<<nStandard<<"="<<nCount1<<endl;

	system("pause");
	return 0;
}
