#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    set<int> coll;

    // insert elements from 1 to 9
    for(int i=1;i<=9;i++){
        coll.insert(i);
    }

    // print
    cout << "pre: ";
    copy(coll.begin(),coll.end(),
         ostream_iterator<int>(cout," "));
    cout << endl;

    // �������㷨��ָ��Щ���Ƴ�remove,����resort,�޸�modifyԪ�ص�
    // �㷨�����ڹ���ʽ�����ϻ�����⡣����ʽ�������ܱ���������
    // Ŀ�꣬ԭ��ܼ򵥣�����������㷨���ڹ���ʽ�����ϣ���ı�
    // ĳλ���ϵ�ֵ�������ƻ�������(sorted)���ԣ��Ǿ��Ʒ��˹���ʽ
    // �����Ļ���ԭ�������ڵ�Ԫ�����Ǹ���ĳ������׼���Զ�����
    // ���ԣ�����ʹ���㷨��ֻ��ʹ�������ĳ�Ա����
    // Remove all elements with value 3,
    // algorithm remove() does not work
    // inserted member function erase() works

    // �ڽ�ֹ�ظ��������У�����sets,maps��ɾ��Ԫ�صĸ���ֻ����0��1
    int num = coll.erase(3);

    cout << "number of removed elements: " << num << endl;

    // print post
     cout << "post: ";
    copy(coll.begin(),coll.end(),
         ostream_iterator<int>(cout," "));
    cout << endl;

    return 0;
}
