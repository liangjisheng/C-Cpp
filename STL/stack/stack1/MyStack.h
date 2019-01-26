#include"deque"
#include"stdexcept"
using namespace std;

template<typename T>
class Stack {
	deque<T> elems;
public:
	void push(T const&);
	void pop();
	T top() const;
	bool empty() const 
	{ return elems.empty(); }
	// 使用元素为T2的栈进行赋值
	template<typename T2>
	Stack<T>& operator=(Stack<T2> const&);
};

template<typename T>
void Stack<T>::push(T const& elem)
{ elems.push_back(elem); }

template<typename T>
void Stack<T>::pop()
{
	if(elems.empty()) {
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	elems.pop_back();
}

template<typename T>
T Stack<T>::top() const
{
	if(elems.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}
	return elems.back();
}

template<typename T>
template<typename T2>
Stack<T>& Stack<T>::operator =(Stack<T2> const& op2)
{
	if((void*)this==(void*)&op2)
		return *this;
	Stack<T2> tmp(op2);
	elems.clear();
	while(!tmp.empty()) {
		elems.push_front(tmp.top());
		tmp.pop();
	}
	return *this;
}
