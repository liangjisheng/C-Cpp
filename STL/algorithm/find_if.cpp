#include"iostream"
#include"algorithm"
#include"vector"
using namespace std;

bool ispass(int n) { return n>=60; }

int main()
{
	vector<int> vec;
	vec.push_back(72);
	vec.push_back(54);
	vec.push_back(87);
	vector<int>::iterator it=vec.begin();
	do{
		it=find_if(it,vec.end(),ispass);
		if(vec.end()!=it) {
			cout<<*it<<' ';
			it++;
		}
		else break;
	}while(1);
	cout<<endl;
	
	system("pause");
	return 0;
}
