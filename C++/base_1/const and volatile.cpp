// const 对象只能调用cosnt函数，不能调用volatile函数。
//而volatile对象只能调用volatile函数，不能调用const函数。
//: VOLATILE.CPP--The volatile keyword

#include"iostream.h"

class comm{
	const volatile unsigned char byte;
	volatile unsigned char flag;
	enum {bufsize=100};
	unsigned char buf[bufsize];
	int index;
public:
	comm();
	void isr()volatile;
	char read(int index)const;
};

comm::comm():index(0),byte(0),flag(0){}

//Only a demo;won't actually work
//As an interrupt service routine:
void comm::isr()volatile{
	if(flag)flag=0;
	buf[index++]=byte;
	//Wrap to begining of buffer
	if(index>=bufsize)index=0;
}

char comm::read(int index)const{
	if(index<0||index>=bufsize)return 0;
	return buf[index];
}

int main(int argc,char* argv[])
{
	volatile comm Port;
	Port.isr();		//OK
	//! Port.read(0); //Not OK;
}