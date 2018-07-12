//: AUTOCC.CPP--Automatic copy-constructor
#include"iostream.h"
#include"string.h"

class withCC{	//With copy-constructor
public:
	//Explicit default constructor required:
	withCC(){}
	withCC(const withCC&){
		cout<<"withCC(withCC&)"<<endl;
	}
};

class woCC{		//Without copy-constructor
	enum { bsz=30 };
	char buf[bsz];
public:
	woCC(const char* msg=0){
		memset(buf,0,bsz);
		if(msg) strncpy(buf,msg,bsz);
	}
	void print(const char* msg=0)const{
		if(msg) cout<<msg<<":";
		cout<<buf<<endl;
	}
};

class composite{
	withCC WITHCC;		//Embeded objects
	woCC WOCC;
public:
	composite():WOCC("compostite()"){}
	void print(const char* msg=0){
		WOCC.print(msg);
	}
};

int main(int argc,char* argv[])
{
	composite c;
	c.print("contents of c");
	cout<<"calling composite copy-constructor"<<endl;
	composite c2=c;		//Call copy-constructor
	c2.print("contents of c2");
	return 0;
}