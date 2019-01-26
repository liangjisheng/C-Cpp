#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function template to populate(���) a container of ints.
// The container must support push_back().
template<typename Container>
void populateContainer(Container& cont)
{
    int num;
    while(true)
    {
        cout << "Enter a number (0 to quit): ";
        cin >> num;
        if(0 == num)
            break;
        cont.push_back(num);
    }
}

int main()
{
    // transform()�㷨��һ����Χ�е�ÿ��Ԫ��Ӧ�ûص��������ص�
    // ����һ����Ԫ�أ���������ָ����Ŀ�귶Χ�С�Դ��Χ��Ŀ�귶Χ
    // ������ͬһ��Χ
    vector<int> myVec;
    populateContainer(myVec);

    cout << "The vector contents are: " << endl;
    for(const auto& i : myVec)
        cout << i << " ";
    cout << endl;

    transform(myVec.begin(), myVec.end(), myVec.begin(),
              [](int i){ return i + 100; });

    cout << "The vector contents are: " << endl;
    for(const auto& i : myVec)
        cout << i << " ";
    cout << endl;



    // transform()������һ����ʽ�Է�Χ�е�Ԫ�ضԵ��ö�Ԫ������
    // ��Ҫ��һ����Χ����β���������ڶ�����Χ���׵�������ģ��
    // ��Χ���׵�������Ϊ������
    // ��������vector��Ȼ��ͨ��transform()����Ԫ�ضԵĺͣ�
    // �������������һ��vector��
    vector<int> vec1;
    cout << "Vector1: " << endl;
    populateContainer(vec1);

    vector<int> vec2;
    cout << "Vector2: " << endl;
    populateContainer(vec2);

    if(vec2.size() < vec1.size())
    {
        cout << "Vector2 should be at least the same size as vector1." << endl;
        return 1;
    }

    // Create a lambda to print a container
    auto printContainer = [](const vector<int>& container){
        for(auto& i : container)
            cout << i << ' ';
        cout << endl;
    };

    cout << "Vector1: ";
    printContainer(vec1);
    cout << "Vector2: ";
    printContainer(vec2);

    // ��һ���͵ڶ�������ָ����Դ��Χ������������ָ����Ŀ�귶Χ��
    // ���һ������ָ����Ҫ��ת���������������
    // transform()�������޸��㷨ͨ������һ��Ӧ��Ŀ�귶Χ���һ��ֵ
    // ��һ��λ��(past-the-end)�ĵ�����
    transform(vec1.begin(), vec1.end(), vec2.begin(), vec1.begin(),
              [](int a,int b){ return a + b;});

    cout << "Vector1: ";
    printContainer(vec1);
    cout << "Vector2: ";
    printContainer(vec2);

    return 0;
}
