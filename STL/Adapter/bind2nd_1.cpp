#include"iostream"
#include"tchar.h"
#include"vector"
#include"algorithm"
using namespace std;

void print(int n) { cout<<n<<' '; }

int _tmain(int argc,_TCHAR* argv[]) {
	vector<int> vec;
	vec.push_back(6);
	vec.push_back(9);
	vec.push_back(78);
	vec.push_back(60);
	vec.push_back(63);
	vec.push_back(45);
	vec.push_back(234);
	vec.push_back(1);
	
	cout<<"Data:"<<endl;
	for_each(vec.begin(),vec.end(),print);
	cout<<endl;
	
	// 找出大于60的数据个数 
	int nCount=count_if(vec.begin(),vec.end(),
		bind2nd(greater<int>(),60));
	cout<<"data greater 60 nCount=" <<nCount<<endl;

	system("pause");
	return 0;
}
