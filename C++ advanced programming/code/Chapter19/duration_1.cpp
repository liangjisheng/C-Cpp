#include <iostream>
#include <chrono>
#include <ratio>

using namespace std;
using namespace std::chrono;

int main()
{
    milliseconds ms{3};         // 3∫¡√Î
    microseconds us = 2 * ms;   // 6000Œ¢√Î

    duration<double, ratio<1, 30> > hz30(3.5);

    cout << "3ms duration has " << ms.count() << " ticks\n"
        << "6000us duration has " << us.count() << " ticks\n";


    minutes t1(10);     // 10 minutes
    seconds t2(60);     // 60 seconds
    seconds t3 = t1 - t2;   // 540 seconds
    cout << t3.count() << " seconds" << endl;

    // Convert
    cout << duration_cast<minutes>(t3).count() << " minutes" << endl;

    return 0;
}
