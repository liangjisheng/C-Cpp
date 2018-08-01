#include"deque"
#include"stdexcept"
using namespace std;

// 第二个模板参数试图改变内部容器类型 
template<typename T,typename CONT=deque<T> >
class Stack {
	CONT elems;
public:
	void push(T const&);
	void pop();
	T top() const;
	bool empty() const 
	{ return elems.empty(); }
	// 使用元素为T2的栈进行赋值
	template<typename T2,typename CONT2>
	Stack<T,CONT>& operator=(Stack<T2,CONT2> const&);
};

template<typename T,typename CONT>
void Stack<T,CONT>::push(T const& elem)
{ elems.push_back(elem); }

template<typename T,typename CONT>
void Stack<T,CONT>::pop()
{
	if(elems.empty()) {
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	elems.pop_back();
}

template<typename T,typename CONT>
T Stack<T,CONT>::top() const
{
	if(elems.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}
	return elems.back();
}

template<typename T,typename CONT>
template<typename T2,typename CONT2>
Stack<T,CONT>& Stack<T,CONT>::operator =
				(Stack<T2,CONT2> const& op2)
{
	if((void*)this==(void*)&op2)
		return *this;
	Stack<T2,CONT2> tmp(op2);
	elems.clear();
	while(!tmp.empty()) {
		elems.push_front(tmp.top());
		tmp.pop();
	}
	return *this;
}
