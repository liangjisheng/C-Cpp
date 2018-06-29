#include"iostream"
#include"vector"
#include"algorithm"
#include"cstdlib"
#include"ctime"
using namespace std;

void print(int n) { cout<<n<<' '; }
bool comp(int a,int b) { return a>b; }

int main()
{
	vector<int> vec;
	srand(time(NULL));
	int temp;
	for(int i=0;i<10;i++) {
		temp=rand()%100+1;
		vec.push_back(temp);
	}

	cout<<"Before sort:"<<endl;
	for_each(vec.begin(),vec.end(),print);
	cout<<endl;

	sort(vec.begin(),vec.end());
	cout<<"After sort:"<<endl;
	for_each(vec.begin(),vec.end(),print);
	cout<<endl;

	sort(vec.begin(),vec.end(),comp);
	cout<<"After sort:"<<endl;
	for_each(vec.begin(),vec.end(),print);
	cout<<endl;

	reverse(vec.begin(),vec.end());
	cout<<"reverse:"<<endl;
	for_each(vec.begin(),vec.end(),print);
	cout<<endl;

	system("pause");
	return 0;
}