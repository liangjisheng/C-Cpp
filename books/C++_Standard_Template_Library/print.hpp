
#ifndef _TEMPLATE_PRINT_H_
#define _TEMPLATE_PRINT_H_

#include <iostream>

/************************************************************************
 * PRINT_ELEMENTS()
 * - prints optional C-string optcstr followed by
 * - all elements of the collection coll
 * - separated by space
************************************************************************/
template<class T>
inline void PRINT_ELEMENTS(const T& coll, const char* optcstr = "")
{
	typename T::const_iterator pos;

	std::cout << optcstr;
	for (pos = coll.begin(); pos != coll.end(); ++pos)
		std::cout << *pos << ' ';
	std::cout << std::endl;
}

#endif // _TEMPLATE_PRINT_H_