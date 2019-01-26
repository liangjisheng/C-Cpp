// output.cpp -- ostream istream wostream wistream
#include"iostream"
#include"cstdlib"

int main()
{
	using namespace std;
	cout<<"input a char:";
	char ch1;
	if(cin>>ch1)
		clog<<"char input succeed\n";
	else {
		clog<<"char input failure\n";
		exit(EXIT_FAILURE);
	}
	while(cin.get()!='\n')
		continue;
	cout<<"input a wchar_t:";
	wchar_t wch1;
	if(wcin>>wch1)
		cerr<<"wchar_t input succeed\n";
	else {
		cerr<<"wchar_t input failure\n";
		exit(EXIT_FAILURE);
	}
	while(cin.get()!='\n')
		continue;
	cout<<"ch1="<<ch1<<endl;
	wcout<<"wch1="<<wch1<<endl;

	system("pause");
	//getchar();
	return 0;
}