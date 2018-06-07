// sayings.cpp use pointer to objects
#include"iostream"
#include"cstdlib"
#include"ctime"
#include"String.h"
const int ArSize=10;
const int MaxLen=81;

int main() {
	using namespace std;
	String name;
	cout<<"Hi,What's your name?";
	cin>>name;
	cout<<name<<", please enter up to "<<ArSize
		<<" short sayings <empty line to quit>:\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i;
	for(i=0;i<ArSize;i++) {
		cout<<i+1<<": ";
		cin.get(temp,MaxLen);
		while(cin && cin.get()!='\n')
			continue;
		if(!cin || temp[0]=='\n')
			break;
		else
			sayings[i]=temp;
	}

	int total=i;
	if(total>0) {
		cout<<"Here are your sayings: \n";
		for(i=0;i<total;i++)
			cout<<sayings[i]<<endl;

		// use pointer to keep track of shortest ,first strings
		String * shortest=&sayings[0];
		String * first=&sayings[0];
		for(i=0;i<total;i++) {
			if(sayings[i].length()<shortest->length())
				shortest=&sayings[i];
			if(sayings[i]< *first)
				first=&sayings[i];
		}

		cout<<"shortest saying:\n"<<*shortest<<endl;
		cout<<"First alphabetically:\n"<<*first<<endl;

		srand(time(0));
		int choice=rand()%total;
		String *favorite=&sayings[choice];
		cout<<"My favorite saying1: \n"<<*favorite<<endl;
		choice=rand()%total;
		String *pf=new String(sayings[choice]);
		cout<<"My favorite saying2: \n"<<*favorite<<endl;
	}
	else 
		cout<<"No much to say,en?\n";
	cout<<"Bye!\n";

	return 0;
}