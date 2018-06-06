
/***********************************************************************
 * Stack.hpp
 * safer and more convenient stack class
***********************************************************************/

#ifndef __STACK_HPP
#define __STACK_HPP

#include <deque>
#include <exception>

template<class T>
class Stack
{
protected:
	std::deque<T> c;	// container for the elements

public:
	// exception class fro pop() and top() with empty stack
	class ReadEmptyStack : public std::exception
	{
	public:
		virtual const char* what() const throw() { return "read empty stack"; }
	};

	// number of elements
	typename std::deque<T>::size_type size() const { return c.size(); }

	// is stack empty?
	bool empty() { return c.empty(); }

	// push element into the stack
	void push(const T& elem) { c.push_back(elem); }

	// pop element out of the stack and return its value
	T pop()
	{
		if (c.empty())
			throw ReadEmptyStack();

		T elem(c.back());
		c.pop_back();
		return elem;
	}

	// return value of next element
	T& top()
	{
		if (c.empty())
			throw ReadEmptyStack();
		return c.back();
	}
};

#endif  //__STACK_HPP