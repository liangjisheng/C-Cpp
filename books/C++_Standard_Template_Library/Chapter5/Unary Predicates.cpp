
// 判断式(Predicates)
// 所谓predicates，就是返回bool型的函数，它们通常被用来指定
// 排序准则和搜寻准则。
// STL要求，面对相同的值，predicates必须得出相同的结果，这条
// 戒律将那些“被调用时，会改变自己内部状态”的函数清除出场

#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>      // for abs()
#include <iterator>
using namespace std;

// predicate,which returns whether an integer is a prime number
bool isPrime(int number){
    // ignore negative sign
    number = abs(number);

    // 0 and 1 are prime numbers
    if(0 == number || 1 == number)
        return true;

    // find divisor that divides without a remainder
    int divisor;
    for(divisor = number/2;number%divisor !=0;--divisor){
        ;
    }

    // if no divisor greater than 1 is found,it is a prime number
    return divisor == 1;
}

int main()
{
    list<int> coll;

    for(int i=24;i<=30;i++){
        coll.push_back(i);
    }

    // print
    cout << "values: ";
    copy(coll.begin(),coll.end(),
         ostream_iterator<int>(cout," "));
    cout << endl;

    // search for prime number
    list<int>::iterator pos;
    pos = find_if(coll.begin(),coll.end(),  // range
                  isPrime);                 // predicate
    if(pos != coll.end())
        cout << *pos << " is first prime number found" << endl;
    else
        cout << "no prime number found" << endl;

    return 0;
}
