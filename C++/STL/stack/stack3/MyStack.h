// 借助于模板的模板参数，可以只指定容器的类型，
// 而不需要指定所含元素的类型 Stack<int,std::vector> vStack;
// STL容器都有第二个默认的模板参数:分配器
#ifndef STACK_HPP
#define STACK_HPP

#include"deque"
#include"stdexcept"
#include"memory"
using namespace std;

template<typename T,
		template<typename ELEM,typename alloc=allocator<ELEM> > class CONT=deque>
class Stack{
	CONT<T> elems;
public:
	void push(T const&);
	void pop();
	T top() const;
	bool empty() const 
	{ return elems.empty(); }
	// 使用元素类型为T2的栈对原栈赋值
	template<typename T2,
		template<typename ELEM2,typename alloc2=allocator<ELEM2> > class CONT2>
	Stack<T,CONT>& operator=(Stack<T2,CONT2> const&);
};

template<typename T,template<typename,typename> class CONT>
void Stack<T,CONT>::push(T const& elem)
{ elems.push_back(elem); }

template<typename T,template<typename,typename> class CONT>
void Stack<T,CONT>::pop()
{
	if(elems.empty()) {
		throw out_of_range("Stack<>::pop():empty stack");
	}
	elems.pop_back();
}

template<typename T,template<typename,typename> class CONT>
T Stack<T,CONT>::top() const
{
	if(elems.empty()) {
		throw out_of_range("Stack<>::top():empty stack");
	}
	return elems.back();
}

template<typename T,template<typename,typename> class CONT>
template<typename T2,template<typename,typename> class CONT2>
Stack<T,CONT>& Stack<T,CONT>::operator=(Stack<T2,CONT2> const& op2)
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

#endif	// STACK_HPP
