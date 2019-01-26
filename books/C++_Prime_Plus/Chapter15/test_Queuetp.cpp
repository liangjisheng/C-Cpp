// test_Queuetp.cpp -- using Queuetp template class
#include"iostream"
#include"queuetp.h"
using std::cout;
using std::cin;
using std::endl;
#include"string"
using std::string;

int main() {
	Queue<string> qs(5);
	string temp;
	while(!qs.isfull()) {
		cout<<"input string:";
		std::getline(cin,temp);
		while(cin.get()!='\n')
			continue;
		qs.enqueue(temp);
	}
	cout<<"\nThe queue is full,process begin:\n";
	while(!qs.isempty()) {
		qs.dequeue(temp);
		cout<<temp<<endl;
	}
	cout<<"\nBye\n";
	return 0;
}