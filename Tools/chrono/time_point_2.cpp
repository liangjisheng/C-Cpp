#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    using namespace std::chrono;

    system_clock::time_point now = system_clock::now();
    time_t last = system_clock::to_time_t(now - hours(24));
    time_t next = system_clock::to_time_t(now - hours(24));

    cout << "One day ago, the time was "
        << put_time(localtime(&last), "%F %T") << endl;

    return 0;
}
