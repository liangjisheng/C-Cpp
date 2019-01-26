// strtype2.cpp -- assigning ,adding, and appending

#include"iostream"
using namespace std;
#include"string"

int main() 
{
	string s1="penguin",s2,s3;
	cout<<"s1="<<s1<<endl;
	s2=s1;
	cout<<"s2="<<s2<<endl;
	cout<<"s2=\"buzzard\"\n";
	s2="buzzard";
	cout<<"s2="<<s2<<endl;
	s3=s1+s2;
	cout<<"s3="<<s3<<endl;
	s2+="for a day";
	cout<<"s2="<<s2<<endl;
	return 0;
}