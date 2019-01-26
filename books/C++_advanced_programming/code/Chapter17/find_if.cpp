#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool greaterThan(int num)
{
    return num >= 100;
}

int main()
{
    int num;
    vector<int> IntVec;
    while(true)
    {
        cout << "Enter a test score to add (0 to stop): ";
        cin >> num;
        if(0 == num)
            break;
        IntVec.push_back(num);
    }

    // find_if() 会对每个元素调用greaterThan，知道返回true为止
    // 但STL没有提供find_all()或等效算法来返回匹配谓词的所有实例
    //auto it = find_if(IntVec.begin(),IntVec.end(),greaterThan);

    // 也可以使用 lambda 表示式,与使用函数相同的效果
    auto it = find_if(IntVec.cbegin(),IntVec.cend(),
                      [](int i){ return i >= 100; });

    if(it == IntVec.end()){
        cout << "No numbers greater than 100." << endl;
    }
    else{
        cout << *it << endl;
        cout << "Found number greater than 100." << endl;
    }

    return 0;
}
