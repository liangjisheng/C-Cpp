#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

class Timer
{
public:
    Timer() : m_begin(high_resolution_clock::now()) {}
    void reset() { m_begin = high_resolution_clock::now(); }

    // 默认输出毫秒
    int64_t elapsed() const
    {
        return duration_cast<milliseconds>(high_resolution_clock::now() - m_begin).count();
    }

    // 微秒
    int64_t elapsed_micro() const
    {
        return duration_cast<microseconds>(high_resolution_clock::now() - m_begin).count();
    }

    // 纳秒
    int64_t elapsed_nano() const
    {
        return duration_cast<nanoseconds>(high_resolution_clock::now() - m_begin).count();
    }

    // 秒
    int64_t elapsed_seconds() const
    {
        return duration_cast<seconds>(high_resolution_clock::now() - m_begin).count();
    }

    // 分
    int64_t elapsed_minutes() const
    {
        return duration_cast<minutes>(high_resolution_clock::now() - m_begin).count();
    }

    // 时
    int64_t elapsed_hours() const
    {
        return duration_cast<hours>(high_resolution_clock::now() - m_begin).count();
    }

private:
    time_point<high_resolution_clock> m_begin;
};

double fun()
{
    double d = 0.0;
    for(int i = 0; i < 10000000; ++i)
        d += sqrt(sin(i) * cos(i));

    return d;
}

int main()
{
    Timer t;

    double d = fun();
    cout << "The result is :" << d << endl;

    cout << t.elapsed() << " ms" << endl;    // 默认毫秒
    cout << t.elapsed_micro() << " us" << endl;
    cout << t.elapsed_nano() << " ns" << endl;
    cout << t.elapsed_seconds() << " s" << endl;
    cout << t.elapsed_minutes() << " m" << endl;
    cout << t.elapsed_hours() << " h" << endl;

    return 0;
}
