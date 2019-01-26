
// �ж�ʽ(Predicates)
// ��νpredicates�����Ƿ���bool�͵ĺ���������ͨ��������ָ��
// ����׼�����Ѱ׼��
// STLҪ�������ͬ��ֵ��predicates����ó���ͬ�Ľ��������
// ���ɽ���Щ��������ʱ����ı��Լ��ڲ�״̬���ĺ����������

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
