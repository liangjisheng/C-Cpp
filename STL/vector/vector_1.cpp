#include"iostream"
#include"vector"
using namespace std;

void print(vector<int>);
int sum(vector<int>);

int main()
{
	vector<int> vec;
	vec.push_back(34);
	vec.push_back(23);
	print(vec);
	cout<<"sum="<<sum(vec)<<endl<<endl;
	vector<int>::iterator p;
	p=vec.begin();
	*p=68;
	*(p+1)=69;
	print(vec);
	cout<<"sum="<<sum(vec)<<endl<<endl;
	vec.pop_back();
	print(vec);
	cout<<"sum="<<sum(vec)<<endl<<endl;
	vec.push_back(101);
	vec.push_back(102);
	print(vec);
	cout<<"sum="<<sum(vec)<<endl<<endl;

	vec[0]=1000;
	vec[1]=1001;
	vec[2]=1002;
	print(vec);
	cout<<"sum="<<sum(vec)<<endl<<endl;
	
	system("pause");
	return 0;
}

void print(vector<int> vec) 
{
	vector<int>::iterator p=vec.begin();
	while(p!=vec.end())
		cout<<*p++<<' ';
	cout<<endl;
}

int sum(vector<int> vec)
{
	int result=0;
	vector<int>::iterator p=vec.begin();
	while(p!=vec.end())
		result+=*p++;
	return result;
}