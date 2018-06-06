#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// simple function object that prints the passed argument
class PrintInt{
public:
    void operator()(int elem) const {
        cout << elem << ' ';
    }
};

int main()
{
    vector<int> coll;

    for(int i=1;i<=9;++i){
        coll.push_back(i);
    }

    // print
    for_each(coll.begin(),coll.end(),
             PrintInt());

    return 0;
}


// for_each() 算法大致如下:
// namespace std{
//    template<class Iterator,class Operation>
//    Operation for_each(Iterator act,Iterator End,Operation op)
//    {
//       while(act != End){
//            op(*act);
//           ++act;
//        }
//        return op;
//    }
//}

// 仿函数是"smart functions"(智能型函数)
// 每个仿函数都有自己的型别
// 仿函数通常比一般的函数速度快
