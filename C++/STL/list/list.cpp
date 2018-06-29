// list是使用
#include"iostream"
#include"list"
using namespace std;

int main() 
{
	char ch;
	list<char> charlist;
	for(int i=0;i<5;i++) {
		ch='a'+i;	// ASCII 值加i
		charlist.push_front(ch);
	}
	cout<<"list before:"<<endl;
	list<char>::iterator iter;
	for(iter=charlist.begin();iter!=charlist.end();iter++)
		cout<<*iter<<' ';
	cout<<endl;

	list<char>::iterator itstart=charlist.begin();
	charlist.insert(++itstart,2,'A');
	cout<<"\nlist after insert:"<<endl;
	for(iter=charlist.begin();iter!=charlist.end();iter++)
		cout<<*iter<<' ';
	cout<<endl;

	system("pause");
	return 0;
}