#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    set<int> coll;

    // insert elements from 1 to 9
    for(int i=1;i<=9;i++){
        coll.insert(i);
    }

    // print
    cout << "pre: ";
    copy(coll.begin(),coll.end(),
         ostream_iterator<int>(cout," "));
    cout << endl;

    // 更易型算法，指那些会移除remove,重排resort,修改modify元素的
    // 算法，用于关联式容器上会出问题。关联式容器不能被当做操作
    // 目标，原因很简单：如果更易型算法用于关联式容器上，会改变
    // 某位置上的值，进而破坏其已序(sorted)特性，那就推翻了关联式
    // 容器的基本原则：容器内的元素总是根据某个排序准则自动排序
    // 所以，不能使用算法，只能使用容器的成员函数
    // Remove all elements with value 3,
    // algorithm remove() does not work
    // inserted member function erase() works

    // 在禁止重复的容器中，例如sets,maps，删除元素的个数只能是0或1
    int num = coll.erase(3);

    cout << "number of removed elements: " << num << endl;

    // print post
     cout << "post: ";
    copy(coll.begin(),coll.end(),
         ostream_iterator<int>(cout," "));
    cout << endl;

    return 0;
}
