// random_shuffle.cpp
#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;

void Output(int n)
{ cout<<n<<' '; }

int main()
{
	vector<int> intVect;
	for(int i=0;i<10;i++)
		intVect.push_back(i);
	cout<<"intVect: ";
	for_each(intVect.begin(),intVect.end(),Output);
	random_shuffle(intVect.begin(),intVect.end());
	cout<<endl;
	cout<<"intVect: ";
	for_each(intVect.begin(),intVect.end(),Output);
	cout<<endl;

	system("pause");
	return 0;
}