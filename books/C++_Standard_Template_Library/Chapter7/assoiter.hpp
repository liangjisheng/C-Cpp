
// Inerator Traits(迭代器特性)是掌握STL编程技术的关键，traits更是C++的高级应用
// 可以根据不同的迭代器类型，将操作行为重载
// C++提供了一种特殊的template结构来定义所谓的迭代器特性(iterator traits)
// T表示迭代器类型
//namespace std{
//	template<class T>
//	struct iterator_traits{
//		typedef typename T::value_type				value_type;
//		typedef typename T::difference_type			difference_type;
//		typedef typename T::iterator_category		iterator_category;
//		typedef typename T::pointer					pointer;
//		typedef typename T::reference				reference;
//	};
//}

// 下面编写自定义的迭代器，这是一个关联式容器的insert迭代器

#ifndef __ASSOITER_H__
#define __ASSOITER_H__

#include <iterator>

// template class for insert iterator for associative containers
// 同所有的ouput迭代器一样，元素类型和距离类型都是void
template<class Container>
class asso_insert_iterator
	: public std::iterator<std::output_iterator_tag, void, void, void ,void>
{
protected:
	Container& container;		// container in which elements are inserted

public:
	// constructor
	explicit asso_insert_iterator(Container& c) : container(c) {}

	// assignment operator
	// insert a value into the container
	asso_insert_iterator<Container>& 
		operator= (const typename Container::value_type& value)
	{
		container.insert(value);
		return *this;
	}

	// dereferencing is a no-op that returns the iterator itself
	asso_insert_iterator<Container>& operator* () { return *this; }

	// increment operation is a no-op that returns the iterator itself
	asso_insert_iterator<Container>& operator++ () { return *this; }

	asso_insert_iterator<Container>& operator++(int) { return *this; }
};

// convenience function to create the inserter
// 函数asso_inserter()用来简化迭代器的生成动作和初始化动作
template<class Container>
inline asso_insert_iterator<Container> asso_inserter(Container& c)
{
	return asso_insert_iterator<Container>(c);
}

#endif  //__ASSOITER_H__