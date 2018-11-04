#include <iostream>
#include <future>
#include <chrono>

using namespace std;

bool is_prime(int x)
{
    if (x <= 1)
        return false;

    for (int i = 2; i < x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}


int main()
{
    int x = 700020007;
    // std::async会首先创建线程执行is_prime(700020007)，
    // 任务创建之后，std::async立即返回一个std::future对象
    std::future<bool> fut = std::async(is_prime, x);
    cout << "please wait";
    std::chrono::milliseconds span(100);
    while (fut.wait_for(span) != std::future_status::ready)
        cout << ".";
    cout << endl;

    bool ret = fut.get();
    if (ret)
        cout << x << " is a prime" << endl;
    else
        cout << x << " is not a prime" << endl;


    return 0;
}
