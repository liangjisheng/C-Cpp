#include <iostream>
#include <ratio>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    //duration<long> d1;      // Ĭ������Ϊ1��
    // ratio<1> ��Ĭ�ϵĵδ����ڣ�������д����ͬ��
    //duration<long, ratio<1> > d1_equal;

    //duration<long, ratio<60> > d2;  // 60������
    //duration<double, ratio<1, 60> > d3; // 1/60������

    // ʹ��Ԥ���������������
    //duration<long long, milli> d4;  // ����Ϊ1����


    // test duration
    // 123������Ϊ60��ĳ���ʱ��(ʱ����)
    duration<long, ratio<60> > d1(123);
    // count()����ж��ٸ�����
    cout << d1.count() << endl;

    // Specify a duration represented by a double with each
    // tick equal to 1 second and assign the largest possible
    // duration to it.
    duration<double> d2;
    d2 = d2.max();
    cout << d2.count() << endl;

    duration<long, ratio<60> > d3(10);      // = 10 minutes
    duration<long, ratio<1> > d4(14);       // = 14 seconds
    // Compare both durations
    if(d3 > d4)
        cout << "10 minutes > 14 seconds." << endl;
    else
        cout << "10 minutes <= 14 seconds." << endl;

    // Increment d4 with 1 resulting 15 seconds
    ++d4;
    // Multiply d4 by 2 resulting in 30 seconds
    d4 *= 2;
    // Add both durations and store as minutes
    duration<double, ratio<60> > d5 = d3 + d4;
    // Add both durations and store as seconds
    duration<double, ratio<1> > d6 = d3 + d4;
    cout << d3.count() << " minutes + " << d4.count() << " seconds = "
        << d5.count() << " minutes or "
        << d6.count() << " seconds" << endl;

    // Create a duration of 30 seconds
    duration<long> d7(30);
    // Convert the seconds of d7 to minutes
    duration<double, ratio<60> > d8(d7);
    cout << d7.count() << " seconds = " << d8.count() << " minutes" << endl;


    auto t = hours(1) + minutes(23) + seconds(45);
    cout << seconds(t).count() << " seconds" << endl;

    return 0;
}
