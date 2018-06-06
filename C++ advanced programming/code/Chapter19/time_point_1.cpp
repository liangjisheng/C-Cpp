#include <iostream>
#include <chrono>
#include <ratio>

using namespace std;
using namespace std::chrono;

int main()
{
    // time_point表示一个时间点，用来获取1970.1.1以来的秒数和当前的
    // 时间，time_from_epoch()用来获得1970.1.1到time_point时间经过的
    // duration.
    // 下面计算当前时间距离1970.1.1有多少天,多少小时，多少分钟，多少秒

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
