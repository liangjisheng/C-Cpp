
// һЩ�㷨���Խ����û�����ĸ����Ժ������ɴ����������Ժ�
// ��������Щ���������㷨�ڲ�������

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
