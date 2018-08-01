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

    // 内部调用push_back()
    back_insert_iterator<vector<int> > inserter(vecTwo);

    // 为vecTwo填充来自vecOne的不等于100的所有元素
    //remove_copy_if(vecOne.cbegin(), vecOne.cend(), inserter,
    //               [](int i){ return i == 100; });

    // 下面一行的代码与上面一行的代码有相同的效果
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
