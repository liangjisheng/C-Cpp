#include <iostream>
// PRINT_ELEMENTS()
// prints optional C-string optcstr followed by
// all elements of the collection coll
// separated by spaces

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,const char* optcstr = "")
{
    // typename用以表明const_iterator是型别T所定义的一个型别，
    // 而不是一个型别为T的值
    typename T::const_iterator pos;

    std::cout << optcstr;
    for(pos = coll.begin();pos!=coll.end();++pos){
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}
