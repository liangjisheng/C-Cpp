#include <iostream>
#include <forward_list>
using std::cout;
using std::endl;
using std::forward_list;
using std::pair;

int main()
{
    forward_list<pair<int,char> > mylist;
    mylist.emplace_front(10,'a');
    mylist.emplace_front(20,'b');
    mylist.emplace_front(30,'c');

    cout << "mylist containers :" << endl;
    for(auto& i : mylist)
        cout << "(" << i.first << "," << i.second << ")" << endl;


    cout << endl;
    forward_list<pair<int,char> > lst1;
    auto it = lst1.before_begin();
    it = lst1.emplace_after(it,100,'x');
    it = lst1.emplace_after(it,200,'y');
    it = lst1.emplace_after(it,300,'z');

    cout << "lst1 containers :" << endl;
    for(auto& i : lst1)
        cout << "(" << i.first << "," << i.second << ")" << endl;

    return 0;
}
