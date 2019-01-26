#include <iostream>
#include <chrono>
#include <ratio>        // for milli
#include <cmath>

using namespace std;
using namespace std::chrono;

int main()
{
    // 通过chrono库还可以计算一段代码执行所消耗的时间
    // Start 和 End的实际类型为system_clock::time_point
    // diff的实际类型为duration:

    // Get the start time
    auto Start = system_clock::now();
    // Execute code that you want to time
    double d = 0.0;
    for(int i = 0; i < 1000000; ++i)
        d+= sqrt(sin(i) * cos(i));

    // Get the end time and calculate the difference
    auto End = system_clock::now();
    auto diff = End - Start;
    // Convert the difference into milliseconds and print to the console
    cout << duration<double, milli>(diff).count() << " ms" << endl;
    cout << duration<double, micro>(diff).count() << " us" << endl;
    cout << duration<double, nano>(diff).count() << " ns" << endl;

    return 0;
}
