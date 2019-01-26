#include <iostream>
// PRINT_ELEMENTS()
// prints optional C-string optcstr followed by
// all elements of the collection coll
// separated by spaces

template <typename T>
inline void PRINT_ELEMENTS(const T& coll,const char* optcstr = "")
{
    // typename���Ա���const_iterator���ͱ�T�������һ���ͱ�
    // ������һ���ͱ�ΪT��ֵ
    typename T::const_iterator pos;

    std::cout << optcstr;
    for(pos = coll.begin();pos!=coll.end();++pos){
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}
