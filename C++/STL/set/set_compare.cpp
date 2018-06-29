// set compare
#include"iostream"
#include"set"
using namespace std;

int main()
{
	set<char> cSet1;
	cSet1.insert('C');
	cSet1.insert('D');
	cSet1.insert('A');
	cSet1.insert('F');
	cout<<"cSet1:"<<endl;
	set<char>::iterator it;
	for(it=cSet1.begin();it!=cSet1.end();it++)
		cout<<*it<<' ';
	cout<<endl;

	set<char> cSet2;
	cSet2.insert('B');
	cSet2.insert('C');
	cSet2.insert('D');
	cSet2.insert('A');
	cSet2.insert('F');
	cout<<"cSet2:"<<endl;
	for(it=cSet2.begin();it!=cSet2.end();it++)
		cout<<*it<<' ';
	cout<<endl;

	if(cSet1==cSet2)
		cout<<"cSet1==cSet2"<<endl;
	else if(cSet1<cSet2)
		cout<<"cSet1<cSet2"<<endl;
	else 
		cout<<"cSet1>cSet2"<<endl;
	cout<<endl;

	system("pause");
	return 0;
}