#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_block(int n, char c)
{
    // critical section (exclusive access to std::cout signaled by lifetime of lck)
    std::unique_lock<std::mutex> lck(mtx);
    for (int i=0; i<n; ++i)
        std::cout << c;
    std::cout << '\n';
}

int main()
{
    std::thread th1(print_block, 50, '*');
    std::thread th2(print_block, 50, '$');

    th1.join();
    th2.join();

    return 0;
}
