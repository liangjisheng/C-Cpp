#include"vector"
#include"stdexcept"

template<typename T,typename CONT=vector<T> >
class Stack{
	private:
		CONT elems;
	public:
		void push(T const&);
		void pop();
		T top()const;
		bool empty()const
		{return elems.empty();}
};

template<typename T,typename CONT>
void Stack<T,CONT>::push(T const& elem)
{elems.push_back(elem);}

template<typename T,typename CONT>
void Stack<T,CONT>::pop()
{
	if(elems.empty())
		throw out_of_range("Stack<>::pop():empty stack");
	elems.pop_back();
}

template<typename T,typename CONT>
T Stack<T,CONT>::top()const
{
	if(elems.empty())
		throw out_of_range("Stack<>::pop():empty stack");
	return elems.back();
}