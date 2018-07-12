#include"iostream"
#include"cstdlib"
#include"string.h"
using namespace std;

class student {
	char *pName;
public:
	student();
	student(const char*);
	student(student&);
	~student();
	student& operator=(student&);
};

student::student()
{ pName=0;cout<<"Constructor默认"<<endl; }

student::student(const char* name) {
	if(name) {
		pName=new char[strlen(name)+1];
		strcpy(pName,name);
		cout<<"one parament constructor "<<pName<<endl;
	}
	else pName=0;
}

student::student(student& re) {
	if(re.pName) {
		pName=new char[strlen(re.pName)+1];
		strcpy(pName,re.pName);
	}
	else pName=0;
	cout<<"copy constructor "<<pName<<endl;
}

student::~student() {
	cout<<"~student()"<<endl;
	delete pName; 
}

student& student::operator =(student& re) {
	if(pName) delete pName;
	if(re.pName) {
		pName=new char[strlen(re.pName)+1];
		strcpy(pName,re.pName);
	}
	else pName=0;
	cout<<"copy Assignment operator "<<pName<<endl;
	return *this;
}

int main() {
	char *p="liangjisheng";
	student s1;
	student s2(p);
	student s3(s2);
	student s4=s2,s5;
	s5=s2;
	s1=s2;
	return 0;
}