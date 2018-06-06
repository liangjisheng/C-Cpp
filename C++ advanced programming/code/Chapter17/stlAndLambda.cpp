#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    int value = 3;
    // ���vec��ֵ����3��Ԫ�صĸ���
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
    // generate() �㷨��Ҫһ����������Χ���Ѹ÷�Χ��ֵ�滻Ϊ�Ӻ������ص�ֵ
    // ����Ϊ����������
    vector<int> coll(10);
    int val = 1;
    generate(coll.begin(),coll.end(),
             [&val]{ val *= 2; return val;} );
    for(const auto& i : coll)
        cout << i << ' ';
    cout << endl;

    return 0;
}
