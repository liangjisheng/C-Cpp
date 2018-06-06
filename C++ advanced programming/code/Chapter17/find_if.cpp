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

    // find_if() ���ÿ��Ԫ�ص���greaterThan��֪������trueΪֹ
    // ��STLû���ṩfind_all()���Ч�㷨������ƥ��ν�ʵ�����ʵ��
    //auto it = find_if(IntVec.begin(),IntVec.end(),greaterThan);

    // Ҳ����ʹ�� lambda ��ʾʽ,��ʹ�ú�����ͬ��Ч��
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
