#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<char> coll;

    for(char c='a';c<='z';c++)
        coll.push_back(c);

    // print all elements
    // while there are elements print and remove the first element
    while(!coll.empty())
    {
        cout<<coll.front()<<' ';
        coll.pop_front();           // remove the first element
    }
    cout<<endl;

    return 0;
}
