// waiting.cpp -- using clock() in a time-delay loop
#include"iostream"
using namespace std;
#include"ctime"

int main()
{
	double secs;
	cout<<"Enter the delay time in second:";
	cin>>secs;
	clock_t delay=secs*CLOCKS_PER_SEC;
	cout<<"starting\a\n";
	clock_t start=clock();
	while(clock()-start<delay)
	{
		for(char ch='a';ch<='z';ch++)
			cout<<ch<<endl;
	}
	cout<<"done\a\n";

	return 0;
}