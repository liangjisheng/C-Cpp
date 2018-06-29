//成倍增长的内存分配
#include"iostream"
#include"vector"
using namespace std;
int main()
{
	vector<long double> v;
	cout<<v.capacity()<<" "<<v.size()<<endl;
	for(int i=1;i<=1000;i++){
		if(i%7==0)cout<<endl;
		v.push_back(i);cout<<v.capacity()<<' '<<v.size()<<' ';
	}
	cout<<endl;
	return 0;
}