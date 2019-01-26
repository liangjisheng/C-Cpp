#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void func(int num, const string& str)
{
    cout << "func(" << num << ", " << str << ")" << endl;
}

bool isEven(int num)
{
    return num % 2 == 0;
}

// process����һ����vector�����ú�std::function����vector�е�
// ÿ��Ԫ�ص���f, f���Կ�����һ���ص�
void process(const vector<int>& vec, function<void(int)> f)
{
    for(auto& i : vec)
        f(i);
}

void print(int num)
{
    cout << num << ' ';
}

int main()
{
    // std::function����������ָ�������������󡢻�lambda
    // ��ʾʽ�����ͣ��Ӹ�����˵����ָ���κοɵ��õĶ���
    // ����Ϊ��̬������װ�������Ե��ɺ���ָ��ʹ�ã�
    // ����������ʵ�ֻص��ĺ����Ĳ���
    // std::function<R(ArgTypes...)>
    // R�Ǻ����ķ������ͣ�ArgTypes�ǲ����б�

    // ��ͨ��f1����func()
    function<void(int, const string&)> f1 = func;
    f1(1, "test");

    // ʹ��auto�ؼ��֣�����Ҫָ�����������
    auto f2 = func;
    f2(2, "test");

    // ����std::function���͵���Ϊ�ͺ���ָ��һ�£���˿���
    // ���ݸ�STL�㷨
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    copy(vec.begin(), vec.end(),
         ostream_iterator<int>(cout, " "));
    cout << endl;

    function<bool(int)> f3 = isEven;
    int cnt = count_if(vec.cbegin(), vec.cend(), f3);
    cout << cnt << " even numbers" << endl;


    cout << endl;
    process(vec, print);
    cout << endl;

    int sum = 0;
    process(vec, [&sum](int num){ sum += num; });
    cout << "sum = " << sum << endl;

    return 0;
}
