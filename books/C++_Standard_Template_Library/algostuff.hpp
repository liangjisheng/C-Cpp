
// Á½¸ö¸¨Öúº¯Êý

#ifndef __ALGOSTUFF_H__
#define __ALGOSTUFF_H__

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>

/**
 * PRINT_ELEMENTS()
 * prints optional C-string optcstr followed by
 * all elements of the collection coll
 * separated by space
*/
template<class T>
inline void PRINT_ELEMENTS(const T& coll, const char* optcstr = "")
{
	typename T::const_iterator pos;
	std::cout << optcstr;
	for (pos = coll.begin(); pos != coll.end(); ++pos)
		std::cout << *pos << ' ';
	std::cout << std::endl;
}

/**
 * INSERT_ELEMENTS(collection, first, last)
 * fill values from first to last into the collection
 * NOTE: No half-open range
*/
template<class T>
inline void INSERT_ELEMETNS(T& coll, int first, int last)
{
	for (int i = first; i <= last; ++i)
		coll.insert(coll.end(), i);
}

#endif  //__ALGOSTUFF_H__