#include"iostream"
#include"string"
#include"vector"
#include"iterator"
#include"algorithm"
using namespace std;

int main()
{
	vector<string> vec;
	vec.push_back("Eraser");
	vec.push_back("Book");
	vec.push_back("Pen");
	string strGood="Pencil";
	vector<string>::iterator it=find(vec.begin(),
		vec.end(),strGood);
	if(it!=vec.end())
		cout<<strGood<<endl;
	else
		cout<<"no "<<strGood<<endl;
	
	system("pause");
	return 0;
}
