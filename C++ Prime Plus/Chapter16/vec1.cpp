// vec1.cpp -- introducing the vector template
#include"iostream"
#include"vector"
#include"string"
const int NUM=5;

int main()
{
	using std::string;
	using std::cout;
	using std::cin;
	using std::endl;
	using std::vector;

	vector<int> ratings(NUM);
	vector<string> titles(NUM);
	cout<<"vector input:\n";
	int i;
	for(i=0;i<NUM;i++) {
		cout<<"\nInput a string:";
		std::getline(cin,titles[i],'\n');
		cout<<"Input a integer:";
		cin>>ratings[i];
		while(cin.get()!='\n')
			continue;
	}
	cout<<"\nvector output:\n";
	for(i=0;i<NUM;i++)
		cout<<ratings[i]<<":"<<titles[i]<<endl;

	return 0;
}