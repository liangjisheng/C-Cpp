#include"iostream"
#include"algorithm"
#include"vector"
using namespace std;

void print(int &elem) { cout<<elem<<' ';}
int op(int a,int b) { return a*b; }

int main()
{
	vector<int> v1,v2,vSum;
	int n,i;
	cout<<"input a number:";
	cin>>n;
	cout<<"\ninput the element:";
	for(i=0;i<n;i++) {
		int t;
		cin>>t;
		v1.push_back(t);
	}
	cout<<"\ninput the element:";
	for(i=0;i<n;i++) {
		int t;
		cin>>t;
		v2.push_back(t);
	}
	vSum.resize(n);
	transform(v1.begin(),v1.end(),v2.begin(),vSum.begin(),op);
	for_each(vSum.begin(),vSum.end(),print);
	cout<<endl;
	
	system("pause");
	return 0;
}