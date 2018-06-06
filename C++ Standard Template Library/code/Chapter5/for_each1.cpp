
// 一些算法可以接受用户定义的辅助性函数，由此提高其灵活性和
// 能力，这些函数将在算法内部被调用

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int elem){
    cout << elem << ' ';
}

int main()
{
    vector<int> coll;

    for(int i=1;i<=9;++i){
        coll.push_back(i);
    }

    // print
    for_each(coll.begin(),coll.end()        // range
             ,print);                       // operation
    cout << endl;

    return 0;
}
