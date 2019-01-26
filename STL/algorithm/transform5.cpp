// transform.cpp -- use function fo algorithm
#include"iostream"
#include"algorithm"
#include"cctype"
#include"string"

int main(int argc, char *argv[])
{
	using namespace std;
    string s("hello world");
	cout<<s<<endl;
    transform(s.begin(), s.end(), s.begin(), toupper);
    cout<<s<<endl;
   
    return 0;   
}