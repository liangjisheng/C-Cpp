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


// for_each() �㷨��������:
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

// �º�����"smart functions"(�����ͺ���)
// ÿ���º��������Լ����ͱ�
// �º���ͨ����һ��ĺ����ٶȿ�
