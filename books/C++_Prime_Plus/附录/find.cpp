// find.cpp -- use STL function
#include"iostream"
#include"string"
#include"vector"
#include"algorithm"

int main()
{
	using namespace std;
	
	vector<string> input;
	string temp;
	cout<<"input a string(quit for quit):";
	while(cin>>temp && temp!="quit") {
		input.push_back(temp);
		cout<<"\ninput a string(quit for quit):";
	}
	cout<<"\nbefore modify the string :\n";
	vector<string>::iterator iter;
	for(iter=input.begin();iter!=input.end();iter++)
		cout<<*iter<<endl;
	vector<string>::iterator want=
		find(input.begin(),input.end(),string("li"));
	if(want!=input.end()) {
		vector<string>::reference r=*want;
		r="lishuyu";
	}
	cout<<"\nAfter modify the string :\n";
	for(iter=input.begin();iter!=input.end();iter++)
		cout<<*iter<<endl;

	vector<string>::value_type s1=input[0];	 // s1 is type string
	vector<string>::reference s2=input[1];	 // s2 is type string &
	cout<<"\ns1="<<s1
		<<"\ns2="<<s2<<endl;

	return 0;
}