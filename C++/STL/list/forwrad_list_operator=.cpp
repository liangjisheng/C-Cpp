#include <iostream>
#include <forward_list>
using std::cout;
using std::endl;
using std::forward_list;

template<typename Container>
Container by_two(const Container& x)
{
    Container temp(x);
    for(auto& i : temp)
        i *= 2;
    return temp;
}

void print(const forward_list<int>& src)
{
    for(const auto& i : src)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    forward_list<int> first(4);         // 4 ints
    forward_list<int> second(3,5);      // 3 ints with value 5
    print(first);
    print(second);

    first = second;
    print(first);

    second = by_two(first);
    print(second);

    cout << endl;
    forward_list<int> mylist = {20,30,40,50};
    print(mylist);
    mylist.insert_after(mylist.before_begin(),10);
    print(mylist);

    cout << endl;
    first.assign(4,15);
    print(first);
    second.assign(first.begin(),first.end());
    print(second);
    first.assign({1,2,3,4,5});  // Initializer_list
    print(first);

    return 0;
}
