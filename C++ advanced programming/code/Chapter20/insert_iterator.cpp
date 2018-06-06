#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
    vector<int> vecOne, vecTwo;
    vecOne.push_back(100);
    vecOne.push_back(98);
    vecOne.push_back(99);
    vecOne.push_back(101);
    vecOne.push_back(102);

    copy(vecOne.cbegin(), vecOne.cend(),
         ostream_iterator<int>(cout, " "));
    cout << endl;

    // �ڲ�����push_back()
    back_insert_iterator<vector<int> > inserter(vecTwo);

    // ΪvecTwo�������vecOne�Ĳ�����100������Ԫ��
    //remove_copy_if(vecOne.cbegin(), vecOne.cend(), inserter,
    //               [](int i){ return i == 100; });

    // ����һ�еĴ���������һ�еĴ�������ͬ��Ч��
    remove_copy_if(vecOne.cbegin(), vecOne.cend(),
                   back_inserter(vecTwo),
                   [](int i){ return i == 100; });

    cout << endl;
    copy(vecTwo.cbegin(), vecTwo.cend(),
         ostream_iterator<int>(cout, " "));
    cout << endl;


    set<int> setOne;
    insert_iterator<set<int> > inserter1(setOne, setOne.begin());
    remove_copy_if(vecOne.cbegin(), vecOne.cend(), inserter1,
                   [](int i){ return i == 100; });

    cout << endl;
    copy(setOne.cbegin(), setOne.cend(),
         ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
