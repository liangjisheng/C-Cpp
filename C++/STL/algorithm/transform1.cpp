#include"iostream"
#include"string"
#include"algorithm"
char op(char);

int main() {
	using namespace std;

	string str="hello,word";
	string str1=str;
	cout<<str<<endl;
	transform(str.begin(),str.end(),str.begin(),toupper);
	cout<<str<<endl;
	transform(str1.begin(),str1.end(),str1.begin(),op);
	cout<<str1<<endl;

	string first,second;
	cout<<"\ninput a string:";
	cin>>first;
	second.resize(first.size());
	transform(first.begin(),first.end(),second.begin(),toupper);
	cout<<second<<endl;
	transform(first.begin(),first.end(),second.begin(),op);
	cout<<second<<endl;

	string s="LISHUYU";
	cout<<endl<<s<<endl;
	transform(s.begin(),s.end(),s.begin(),tolower);
	cout<<s<<endl;

	system("pause");
	return 0;
}

char op(char ch) {
	if(ch>='a' || ch<='z')
		return ch-32;
	else 
		return ch;
}