// stackp1.h -- modified Stack template
#ifndef STACKP1_H_
#define STACKP1_H_

template<class Type>
class Stack {
private:
	enum { SIZE =10 };
	int stacksize;
	Type * items;
	int top;
public:
	explicit Stack(int sz = SIZE);
	Stack(const Stack &);
	Stack & operator =(const Stack &);
	virtual ~Stack() { delete []items; }
	bool isempty() { return top==0; }
	bool isfull() { return top==SIZE; }
	bool push(const Type &);
	bool pop(Type &);
};

template<class Type>
Stack<Type>::Stack(int sz) {
	stacksize=sz;
	top=0;
	items=new Type[sz];
}

template<class Type>
Stack<Type>::Stack(const Stack<Type> & st) {
	int i;
	top=st.top;
	stacksize=st.stacksize;
	items=new Type[stacksize];
	for(i=0;i<top;i++)
		items[i]=st.items[i];
}

template<class Type>
Stack<Type> & Stack<Type>::operator =(const Stack<Type> & st) {
	if(this==&st)
		return *this;
	delete []items;
	top=st.top;
	stacksize=st.stacksize;
	items=new Type[stacksize];
	for(int i=0;i<top;i++)
		items[i]=st.items[i];
	return *this;
}

template<class Type>
bool Stack<Type>::pop(Type & item) {
	if(isempty())
		return false;
	else {
		item=items[--top];
		return true;
	}
}

template<class Type>
bool Stack<Type>::push(const Type & item) {
	if(isfull())
		return false;
	else {
		items[top++]=item;
		return true;
	}
}

#endif