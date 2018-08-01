#include <iostream>
#include <forward_list>
using namespace std;

void print(const forward_list<int>& src)
{
    for(const auto& i : src)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    forward_list<int> lst1 = {5,6};
    forward_list<int> lst2 = {1,2,3,4};
    forward_list<int> lst3 = {7,8,9};

    cout << "lst1 :";
    print(lst1);

    cout << "lst2 :";
    print(lst2);

    cout << "lst3 :";
    print(lst3);

    // Insert lst2 at the front fo lst1 using splice
    lst1.splice_after(lst1.before_begin(),lst2);

    cout << "lst1 insert lst2 at begin :";
    print(lst1);

    lst1.push_front(0);
    cout << "lst1 insert 0 at begin :";
    print(lst1);

    // Insert lst3 at the end of lst1.
    // For this,we first need an iterator to the last element
    // begin()之前的假想的一个元素，但不能解引用
    auto iter = lst1.before_begin();
    auto iterTemp = iter;
    while(++iterTemp != lst1.end()){
        ++iter;
    }
    lst1.insert_after(iter,lst3.cbegin(),lst3.cend());

    cout << "lst1 insert lst3 at the end :";
    print(lst1);

    return 0;
}
