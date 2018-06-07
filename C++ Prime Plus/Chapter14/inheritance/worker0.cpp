// worker0.cpp -- working class methods
#include"worker0.h"
#include"iostream"
using std::cout;
using std::cin;
using std::endl;

// Worker methods
Worker::~Worker() {}

void Worker::Set() {
	cout<<"Enter worker's name: ";
	std::getline(cin,fullname);
	cout<<"Enter worker's ID: ";
	cin>>id;
	while(cin.get()!='\n')
		continue;
}

void Worker::Show() const {
	cout<<"Name: "<<fullname<<",ID: "<<id<<endl;
}

// Waiter methods
void Waiter::Set() {
	Worker::Set();
	cout<<"Enter panache: ";
	cin>>panache;
	while(cin.get()!='\n')
		continue;
}

void Waiter::Show() const {
	Worker::Show();
	cout<<"panache: "<<panache<<endl;
}

// Singer methods

char * Singer::pv[]={ "other","alto","contralto","soprano",
						"bass","baritone","tenor"};

void Singer::Set() {
	Worker::Set();
	cout<<"Enter number for singer's vocal range:\n";
	int i;
	for(i=0;i<Vtypes;i++) {
		cout<<i<<":"<<pv[i]<<' ';
		if(i%4==3) cout<<endl;
	}
	if(i%4==0) cout<<endl;
	cin>>voice;
	while(cin.get()!='\n')
		continue;
}

void Singer::Show() const {
	Worker::Show();
	cout<<"Vocal range: "<<pv[voice]<<endl;
}