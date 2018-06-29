#include"iostream"
using namespace std;
#ifndef STACKT
#define STACKT
const int STACK_CAPACITY=16;
//类模板声明
template<typename StackElement>
class Stack{
public:
	Stack();
	bool empty()const;
	void push(const StackElement &value);
	void display(ostream &out)const;
	StackElement top()const;
	void pop();
	friend ostream & operator<<(ostream &out,const Stack<StackElement> & st);
private:
	StackElement myArray[STACK_CAPACITY];
	int myTop;
};
//定义类

template<typename StackElement>
inline Stack<StackElement>::Stack()
{myTop=-1;}

template<typename StackElement>
inline bool Stack<StackElement>::empty()const
{return myTop==-1;}

template<typename StackElement>
void Stack<StackElement>::push(const StackElement &value)
{
	if(myTop<STACK_CAPACITY-1)
		myArray[++myTop]=value;
	else 
		cerr<<"***Stack is full-can't add new value ***\n"
		<<"Must increase value of STACK_CAPACITY in STACK.h\n";
}

template<typename StackElement>
void Stack<StackElement>::display(ostream &out)const
{
	for(int i=myTop;i>=0;i--)
		cout<<myArray[i]<<" ";
	cout<<endl;
}

template<typename StackElement>
StackElement Stack<StackElement>::top()const
{
	if(myTop>=0)
		return myArray[myTop];
	else 
		cerr<<"***Stack is empty ***"<<endl;
}

template<typename StackElement>
void Stack<StackElement>::pop()
{
	if(myTop>=0)myTop--;
	else 
		cerr<<"***Stack is empty,can't remove a value ***"<<endl;
}

template<typename StackElement>
ostream &operator<<(ostream &out,const Stack<StackElement> &st)
{
	for(int i=myTop;i>=0;i--)
		cout<<myArray[i]<<" ";
	cout<<endl;
	return out;
}
#endif