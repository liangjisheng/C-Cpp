#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<float> coll;

    for(int i=1;i<=6;i++)
        coll.push_front(i*1.1);

    // print
    for(uint32_t i=0;i<coll.size();i++)
        cout<<coll[i]<<' ';
    cout<<endl;

    return 0;
}
