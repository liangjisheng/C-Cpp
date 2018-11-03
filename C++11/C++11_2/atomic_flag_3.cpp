#include <iostream>
#include <cassert>
#include <atomic>
#include <vector>
#include <unistd.h>
#include <thread>
#include <sstream>

using namespace std;

std::atomic<int> foo(0);    // atomic<int>支持++和--的原子操作
std::atomic_flag lock = ATOMIC_FLAG_INIT;

void add_foo()
{
    while (1)
    {
        foo++;
        while (lock.test_and_set());
        cout << "add: " << foo << endl;
        lock.clear();
        usleep(1000);
    }
}

void sub_foo()
{
    while (1)
    {
        foo--;
        while (lock.test_and_set());
        cout << "sub: " << foo << endl;
        lock.clear();
        usleep(1000);
    }
}


int main()
{
    thread th2 = thread(add_foo);
    thread th1 = thread(sub_foo);
    th1.join();
    th2.join();

    return 0;
}
