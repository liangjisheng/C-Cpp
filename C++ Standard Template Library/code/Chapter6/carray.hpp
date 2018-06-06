
// 将数组STL化，在数组之外包装一层常用的容器界面

#ifndef _STL_CARRAY_H_
#define _STL_CARRAY_H_

#include <cstddef>

template<class T, std::size_t thesize>
class carray
{
private:
	T v[thesize];	// fixed-size array of element of type T
public:
	// type definitions
	typedef T				value_type;
	typedef T*				iterator;
	typedef const T*		const_iterator;
	typedef T&				reference;
	typedef const T&		const_reference;
	typedef std::size_t		size_type;
	typedef std::ptrdiff_t	difference_type;

	// iterator support
	iterator begin() { return v; }
	const_iterator begin() const { return v; }
	iterator end() { return v + thesize; }
	const_iterator end() const { return v + thesize; }

	// direct element access
	reference operator[](std::size_t i) { return v[i]; }
	const_reference operator[] (std::size_t i) const { return v[i]; }

	// size is constant
	size_type size() const { return thesize; }
	size_type max_size() const { return thesize; }

	// conversion to ordinary array
	T* as_array() { return v; }
};

#endif // _STL_CARRAY_H_
