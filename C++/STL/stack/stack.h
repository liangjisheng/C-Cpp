#include"iostream.h"

class stack {
	char * pstr;
	int max_size;
	int top;
public:
	stack(int size=10);
	~stack();
	void push(char);
	char pop();
	friend ostream& operator<< (ostream& os,stack& s);
};

stack::stack(int size) {
	top=0;
	if(size<0 || size>10000)
		pstr=new char[10],max_size=size;
	else 
		pstr=new char[size],max_size=size;
}

stack::~stack() { delete [] pstr; }

void stack::push(char ch) 
{
	if(top<max_size)
		pstr[top++]=ch;
	else 
		cout<<"栈满，不能入栈"<<endl;
}

char stack::pop()
{
	if(top>0) 
		return pstr[--top];
	else {
		cout<<"栈空，不能出栈"<<endl;
		return NULL;
	}
}

ostream& operator<< (ostream& os,stack& s)
{
	int temp=s.top;
	while(temp>0)
		cout<<s.pstr[--temp]<<' ';
	return os;
}