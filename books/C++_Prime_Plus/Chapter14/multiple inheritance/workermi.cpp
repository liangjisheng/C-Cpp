// workermi.cpp -- working class mithods with MI
#include"iostream"
using namespace std;
#include"workermi.h"
//using std::cout;
//using std::cin;
//using std::endl;

// worker methods
//Worker::~Worker() {}

;void Worker::Data() const {
	cout<<"Name: "<<fullname<<endl;
	cout<<"ID: "<<id<<endl;
}

void Worker::Get() {
	std::getline(cin,fullname);
	cout<<"Enter worker's ID: ";
	cin>>id;
	while(cin.get()!='\n')
		continue;
}

// Waiter methods
void Waiter::Set() {
	Worker::Get();
	Get();
}

void Waiter::Show() const {
	Worker::Data();
	Data();
}

void Waiter::Data() const
{ cout<<"panache rating: "<<panache<<endl; }

void Waiter::Get() {
	cout<<"Enter waiter's panache rating: ";
	cin>>panache;
	while(cin.get()!='\n')
		continue;
}

// Singer methods
char * Singer::pv[7]={ "other","alto","contralto",
					"soprano","bass","baritone","tenor"};

void Singer::Set() {
	Worker::Get();
	Get();
}

void Singer::Show() const {
	Worker::Data();
	Data();
}

void Singer::Data() const
{ cout<<"Vocal range: "<<pv[voice]<<endl; }

void Singer::Get() {
	cout<<"Enter number for singer's vocal range: \n";
	int i;
	for(i=0;i<Vtypes;i++) {
		cout<<i<<":"<<pv[i]<<' ';
		if(i%4==3) cout<<endl;
	}
	if(i%4!=0) cout<<endl;
	cin>>voice;
	while(cin.get()!='\n')
		continue;
}

// SingerWaiter methods
void SingerWaiter::Data() const {
	Singer::Data();
	Waiter::Data();
}

void SingerWaiter::Get() {
	Waiter::Get();
	Singer::Get();
}

void SingerWaiter::Set() {
	cout<<"Enter singing waiter's name: ";
	Worker::Get();
	Get();
}

void SingerWaiter::Show() const {
	Worker::Data();
	Data();
}
