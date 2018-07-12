//: PMEM2.CPP -- Pointer to members
#include"iostream.h"

class widget{
	void f(int) const {cout<<"widget::f()\n";}
	void g(int) const {cout<<"widget::g()\n";}
	void h(int) const {cout<<"widget::h()\n";}
	void i(int) const {cout<<"widget::i()\n";}
	enum { count=4 };
	void (widget::*fptr[count])(int) const;		//定义成员函数指针
public:
	widget(){
		fptr[0]=&widget::f;
		fptr[1]=&widget::g;
		fptr[2]=&widget::h;
		fptr[3]=&widget::i;
	}
	void select(int I,int J){
		if(I<0||I>=count) return;
		(this->*fptr[I])(J);
	}
	int Count() { return count; }
};

int main(int argc,char* argv[])
{
	widget w;
	for(int i=0;i<w.Count();i++)
		w.select(i,47);
	return 0;
}