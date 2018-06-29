#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<char> coll;

    for(char c='a';c<='z';++c)
        coll.push_back(c);

    // iterator over all elements
    list<char>::const_iterator iter;
    for(iter=coll.begin();iter!=coll.end();++iter)
        cout<<*iter<<' ';
    cout<<endl;

    return 0;
}
