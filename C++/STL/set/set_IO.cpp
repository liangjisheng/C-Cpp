#include <iostream>
#include <set>

// using namespace std;

int main()
{
    typedef std::set<int> IntSet;
    typedef std::multiset<int> IntMultiSet;

    IntSet coll;
    IntMultiSet MultiColl;

    coll.insert(3);
    coll.insert(1);
    coll.insert(5);
    coll.insert(4);
    coll.insert(1);
    coll.insert(6);
    coll.insert(2);
    coll.insert(6);

    MultiColl.insert(3);
    MultiColl.insert(1);
    MultiColl.insert(5);
    MultiColl.insert(4);
    MultiColl.insert(1);
    MultiColl.insert(6);
    MultiColl.insert(2);
    MultiColl.insert(6);

    // print
    IntSet::const_iterator pos;
    for(pos=coll.begin();pos!=coll.end();++pos)
        std::cout<<*pos<<' ';
    std::cout<<std::endl;

    IntMultiSet::const_iterator pos1;
    for(pos1=MultiColl.begin();pos1!=MultiColl.end();++pos1)
        std::cout<<*pos1<<' ';
    std::cout<<std::endl;

    return 0;
}
