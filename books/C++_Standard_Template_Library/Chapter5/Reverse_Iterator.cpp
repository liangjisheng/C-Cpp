
// Reverse_Iterator ���������
// ��������������ͨ��rbegin()��rend()������reverse iterator
// rbegin()ָ�����һ��Ԫ�أ�rend()ָ���һ��Ԫ�ص�ǰһ��λ��

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    vector<int> coll;

    // insert elements from 1 to 9
    for(int i=1;i<=9;i++)
        coll.push_back(i);

    // print with C++11
    for(const auto& iter : coll)
        cout << iter << ' ';
    cout << endl;

    // print all element in reverse order
    copy(coll.rbegin(),coll.rend(),           // source
         ostream_iterator<int>{cout," "});  // destination
    cout << endl;

    return 0;
}
