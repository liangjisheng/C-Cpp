#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;

void print(int n) { cout<<n<<' '; }

int main()
{
	vector<int> vec;
	for(int i=0;i<10;i++)
		vec.push_back(i);

	cout<<"vec:"<<endl;
	for_each(vec.begin(),vec.end(),print);
	cout<<endl;

	vector<int>::iterator itmax=max_element(vec.begin(),vec.end());
	vector<int>::iterator itmin=min_element(vec.begin(),vec.end());
	cout<<"max="<<*itmax<<endl;
	cout<<"min="<<*itmin<<endl;

	system("pause");
	return 0;
}