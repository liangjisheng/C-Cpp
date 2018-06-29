#include"iostream"
using namespace std;
#ifndef STACK
#define STACK
const int STACK_CAPACITY=16;
typedef int StackElement;
class Stack{
public:
	Stack();
	bool empty()const;
	void push(const StackElement &value);
	void display(ostream &out)const;
	StackElement top()const;
	void pop();
private:
	StackElement myArray[STACK_CAPACITY];
	int myTop;
};
#endif

inline Stack::Stack()
{myTop=-1;}

inline bool Stack::empty()const
{return (myTop==-1);}

void Stack::push(const StackElement &value)
{
	if(myTop<STACK_CAPACITY-1)
	{++myTop;myArray[myTop]=value;}
	else 
		cout<<"***Stack is full---can't add new value ***\n"
		    <<"Must increase value of STACK_CAPACITY in Stack.h\n";
}

void Stack::display(ostream &out)const
{
	for(int i=myTop;i>=0;i--)
		out<<myArray[i]<<" ";
	out<<endl;
}

StackElement Stack::top()const
{
	if(myTop!=-1)return myArray[myTop];
	cout<<"***Stack is empty***"<<endl;
}

void Stack::pop()
{
	if(myTop>=0)myTop--;
	else cout<<"***Stack is empty---can't remove a value ***"<<endl;
}