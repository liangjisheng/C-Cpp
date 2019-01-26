#include <iostream>
#include <forward_list>

using std::cout;
using std::endl;
using std::forward_list;

void print(const forward_list<int>& src)
{
    for(const int& x : src)
        cout << x << " ";
    cout << endl;
}

int main()
{
    forward_list<int> first;
    cout << "first :";
    print(first);

    forward_list<int> second(4);
    cout << "second :";
    print(second);

    forward_list<int> third(3,77);
    cout << "third :";
    print(third);

    forward_list<int> fourth(third.begin(),third.end());
    cout << "fourth :";
    print(fourth);

    forward_list<int> fifth(fourth);
    cout << "fifth :";
    print(fifth);

    forward_list<int> sixth(std::move(fifth));
    cout << "sixth :";
    print(sixth);
    print(fifth);   // fifth 已经没有元素了，不能输出

    forward_list<int> seventh = {3,52,25,90};
    cout << "seventh :";
    print(seventh);

    return 0;
}
