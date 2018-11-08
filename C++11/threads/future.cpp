#include <iostream>
#include <future>
#include <chrono>

// a non-optimized way of checking for prime numbers:
bool is_prime(int x)
{
    for (int i = 2; i <= x / 2; ++i)
        if (0 == x % i)
            return false;
    return true;
}

int main()
{
    // call function asynchronously:
    std::future<bool> fut = std::async(is_prime, 444444443);

    // do something while waiting for function to set future:
    std::cout << "checking, please wait";
    std::chrono::milliseconds span(100);
    // future关联的共享状态不是ready的话，wait_for()就会一直等待，直到超时
    while (fut.wait_for(span) == std::future_status::timeout)
        std::cout << '.';

    bool x = fut.get();
    std::cout << "\n444444443 " << (x ? "is": "is not") << " prime.\n";

    return 0;
}
