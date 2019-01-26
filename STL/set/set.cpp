// set 
#include"iostream"
#include"set"
using namespace std;

int main()
{
	set<char> cSet;
	cSet.insert('E');
	cSet.insert('F');
	cSet.insert('G');
	cSet.insert('B');
	cSet.insert('C');
	cSet.insert('D');
	
	cout<<"old set:"<<endl;
	set<char>::iterator it;
	for(it=cSet.begin();it!=cSet.end();it++)
		cout<<*it<<' ';

	char ch;
	ch='D';
	it=cSet.find(ch);
	cout<<"\nstart find:"<<ch<<endl;
	if(it==cSet.end())
		cout<<"not found"<<endl;
	else
		cout<<"found"<<endl;
	ch='I';
	it=cSet.find(ch);
	cout<<"\nstart find:"<<ch<<endl;
	if(it==cSet.end())
		cout<<"not found"<<endl;
	else
		cout<<"found"<<endl;

	system("pause");
	return 0;
}