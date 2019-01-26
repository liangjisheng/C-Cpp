
// Inerator Traits(����������)������STL��̼����Ĺؼ���traits����C++�ĸ߼�Ӧ��
// ���Ը��ݲ�ͬ�ĵ��������ͣ���������Ϊ����
// C++�ṩ��һ�������template�ṹ��������ν�ĵ���������(iterator traits)
// T��ʾ����������
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

// �����д�Զ���ĵ�����������һ������ʽ������insert������

#ifndef __ASSOITER_H__
#define __ASSOITER_H__

#include <iterator>

// template class for insert iterator for associative containers
// ͬ���е�ouput������һ����Ԫ�����ͺ;������Ͷ���void
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
// ����asso_inserter()�����򻯵����������ɶ����ͳ�ʼ������
template<class Container>
inline asso_insert_iterator<Container> asso_inserter(Container& c)
{
	return asso_insert_iterator<Container>(c);
}

#endif  //__ASSOITER_H__