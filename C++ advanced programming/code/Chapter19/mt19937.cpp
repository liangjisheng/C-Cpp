#include <iostream>
#include <random>
#include <functional>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    // �����������֮ǰ������Ҫ����һ������ʵ�������ʹ��һ��
    // ������������棬����Ҫ����ֲ���
    // ���ʽ��srand()/rand()������һ�����������������Ҳ��Ҫ
    // ʹ�����ӽ��г�ʼ����srand()�����ӳ����ǵ�ǰʱ�䡣
    // ���ִ�C++�У����鲻ʹ���κλ���ʱ������ӣ���ʹ��
    // random_device����һ������
    random_device rndDevice;
    mt19937 eng(rndDevice());
    // ����������ֲ���ʹ�÷�Χ��1-99֮��ľ��ȷֲ�
    uniform_int_distribution<int> dist(1, 99);

    // ������Ϊ�ֲ����Ƶĺ���������������Ϊ�������룬�Ϳ���
    // �����������
    cout << dist(eng) << endl;

    auto gen = bind(dist, eng);
    vector<int> vec(10);
    // ����ص�����gen,���൱��dist(gen)
    generate(vec.begin(), vec.end(), gen);

    // print
    copy(vec.cbegin(), vec.cend(),
         ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
