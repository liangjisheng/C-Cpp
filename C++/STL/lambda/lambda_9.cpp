#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    int value = 3;
    // 获得vec中值大于3的元素的个数
    int cnt = count_if(vec.cbegin(),vec.cend(),
                       [value](int i) { return i > value;} );
    cout << "Found " << cnt << " numbers greater than 3" << endl;


    cout << endl;
    int cntlambdaCalled = 0;
    int cnt1 = count_if(vec.cbegin(),vec.cend(),
                        [value,&cntlambdaCalled](int i) { ++cntlambdaCalled; return i > value;} );
    cout << "The lambda expression was called " << cntlambdaCalled
        << " times." << endl;
    cout << "Found " << cnt1 << " values > " << value << endl;


    cout << endl;
    // generate() 算法需要一个迭代器范围，把该范围的值替换为从函数返回的值
    // 并作为第三个参数
    vector<int> coll(10);
    int val = 1;
    generate(coll.begin(),coll.end(),
             [&val]{ val *= 2; return val;} );
    for(const auto& i : coll)
        cout << i << ' ';
    cout << endl;

    return 0;
}
