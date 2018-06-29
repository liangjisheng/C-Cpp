//向量vector
#include"iostream"
#include"vector"
using namespace std;
int main()
{
	vector<int>v1,v2;
	int a[]={1949,10,1},i;
	vector<int>::iterator It;
	v1.assign(a,a+3);
	v2.assign(3,10);
	for(i=1;i<=5;i++)
		v1.push_back(i);
	v1.pop_back();
	v1.front()-=v1.back();
	for(It=v1.begin();It<v1.end();It++)
		v2.push_back(*It);
	v2.insert(v2.begin(),2,300);
	v2.erase(v2.begin()+5);
	cout<<"v1=";
	for(i=0;i<v1.size();i++)
		cout<<v1[i]<<" ";
	cout<<endl;
	cout<<"v2=";
	for(i=0;i<v2.size();i++)
		cout<<v2[i]<<" ";
	cout<<endl;
	return 0;
}