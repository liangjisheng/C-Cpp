#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_fifty(char c)
{
    std::unique_lock<std::mutex> lck;   // 默认构造，没有管理任何互斥量对象
    lck = std::unique_lock<std::mutex>(mtx);    // move-assigned
    for (int i=0; i<50; ++i)
        std::cout << c;
    std::cout << '\n';
}

int main()
{
    std::thread th1 (print_fifty,'*');
    std::thread th2 (print_fifty,'$');

    th1.join();
    th2.join();

    return 0;
}
