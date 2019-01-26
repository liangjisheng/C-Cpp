// placenew1.cpp -- new, placenew, no delete
#include"iostream"
#include"string"
#include"new"
//#include"JustTesting.h"
using namespace std;
const int BUF=512;

class JustTesting {
	string words;
	int number;
public:
	JustTesting(const string & str="JustTesting",int n=0) 
	{ words=str; number=n; cout<<words<<" constructed\n"; }
	~JustTesting() { cout<<words<<" destroyed\n"; }
	//friend std::ostream & operator <<(std::ostream & os,
	//	const JustTesting & jt);
	void Show() const { cout<<words<<","<<number<<endl; }
};

int main() {
	char * buffer=new char[BUF];
	JustTesting *pc1,*pc2;

	pc1=new (buffer)JustTesting;		// place object in buffer
	pc2=new JustTesting("lishuyu",20);	// place object on heap

	cout<<"Memory block addresses:\n"
		<<"buffer: "<<(void*)buffer
		<<"\nheap: "<<pc2<<endl;
	cout<<"Memory contents:\n";
	cout<<pc1<<":";
	pc1->Show();
	cout<<pc2<<":";
	pc2->Show();

	JustTesting *pc3,*pc4;
	pc3=new (buffer+sizeof(JustTesting))JustTesting("Bad Idea",6);
	pc4=new JustTesting("heap2",10);

	cout<<"Memory contents:\n";
	cout<<"buffer:"<<(void*)buffer<<endl;
	cout<<buffer<<endl;
	cout<<"pc1:"<<pc1<<":";
	pc1->Show();
	cout<<"length(JustTesting):"<<sizeof(JustTesting)<<endl;
	cout<<"pc2:"<<pc2<<":";
	pc2->Show();

	cout<<"pc4:"<<pc4<<":";
	pc4->Show();

	delete []buffer;
	delete pc2;
	delete pc4;

	return 0;
}