
// 透过一些特殊的函数配接器，可以将预先定义的仿函数和其它数值
// 组合在一起，或使用特殊状况

#include <iostream>
#include <set>
#include <deque>
#include <algorithm>
#include "print.hpp"
using namespace std;

int main()
{
    set<int,greater<int> > coll1;
    deque<int> coll2;

    for(int i=1;i<=9;++i)
        coll1.insert(i);

    PRINT_ELEMENTS(coll1,"initialized: ");

    // transform all element into coll2 by multiplying 10
    transform(coll1.begin(),coll1.end(),        // source
              back_inserter(coll2),             // destination
              bind2nd(multiplies<int>(),10));   // operation
    // 使用配接器bind2nd,是的进行multiples<int>运算时，
    // 以源群集(source collection)的元素作为第一参数，
    // 10作为第二参数
    PRINT_ELEMENTS(coll2,"transformed: ");

    // replace value equal to 70 with 42
    replace_if(coll2.begin(),coll2.end(),       // range
               bind2nd(equal_to<int>(),70),     // replace criterion
               42);                             // new value

    PRINT_ELEMENTS(coll2,"replaced: ");

    // remove all elements with values less than 50
    coll2.erase(remove_if(coll2.begin(),coll2.end(),
                          bind2nd(less<int>(),50)),
                coll2.end());

    PRINT_ELEMENTS(coll2,"removed: ");

    return 0;
}
