#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    typedef map<string,float> StringFloatMap;
    StringFloatMap coll;

    coll["VAT"] = 0.15;
    coll["PI"] = 3.1415;
    coll["an arbitrary number"] = 4983.223;
    coll["NULL"] = 0;

    // print
    StringFloatMap::iterator pos;
    for(pos=coll.begin();pos!=coll.end();++pos)
    {
        cout<<"key:\""<<pos->first<<"\" "
            <<"value: "<<pos->second<<endl;
    }

    // system("pause");
    return 0;
}
