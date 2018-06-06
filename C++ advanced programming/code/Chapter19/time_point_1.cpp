#include <iostream>
#include <chrono>
#include <ratio>

using namespace std;
using namespace std::chrono;

int main()
{
    // time_point��ʾһ��ʱ��㣬������ȡ1970.1.1�����������͵�ǰ��
    // ʱ�䣬time_from_epoch()�������1970.1.1��time_pointʱ�侭����
    // duration.
    // ������㵱ǰʱ�����1970.1.1�ж�����,����Сʱ�����ٷ��ӣ�������

    typedef duration<int, ratio<60 * 60 * 24> > days_type;
    time_point<system_clock, days_type> today =
        time_point_cast<days_type>(system_clock::now());
    time_point<system_clock, hours> toHours =
        time_point_cast<hours>(system_clock::now());
    time_point<system_clock, minutes> tominutes =
        time_point_cast<minutes>(system_clock::now());
    time_point<system_clock, seconds> toseconds =
        time_point_cast<seconds>(system_clock::now());

    cout << today.time_since_epoch().count()
        << " days since epoch" << endl;
    cout << toHours.time_since_epoch().count()
        << " hours since epoch" << endl;
    cout << tominutes.time_since_epoch().count()
        << " minutes since epoch" << endl;
    cout << toseconds.time_since_epoch().count()
        << " seconds since epoch" << endl;

    return 0;
}
