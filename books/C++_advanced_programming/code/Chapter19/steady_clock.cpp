#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

int main()
{
    using namespace std::chrono;

    steady_clock::time_point t1 = steady_clock::now();

    double d = 0.0;
    for(int i = 0; i < 1000000; ++i)
        d += sqrt(sin(i) * cos(i));

    steady_clock::time_point t2 = steady_clock::now();

    cout << (t2 - t1).count() << " us tick count" << endl;

    // ����ת��Ϊ����ʱ������
    cout << duration_cast<microseconds>(t2 - t1).count()
        << " ms tick count" << endl;

    // �������0�����ʾ�������޴��󣬳�������ʱ��û�е���һ��ʱ������
    // ������С��λ����ms��us��ʾ
    cout << duration_cast<seconds>(t2 - t1).count()
        << " s tick count" << endl;

    return 0;
}
