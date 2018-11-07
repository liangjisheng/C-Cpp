#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>
#include <mutex>

using namespace std;

std::mutex mtx;

void f1(int n)
{
    for (int i = 0; i < 5; ++i)
    {
        mtx.lock();
        cout << "Thread " << n << " executing." << endl;
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void f2(int &n)
{
    for (int i = 0; i < 5; ++i)
    {
        mtx.lock();
        cout << "Thread 2 executing." << endl;
        mtx.unlock();
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}


int main()
{
    int n = 0;
    thread t1;  // t1 is not a thread
    thread t2(f1, n + 1);   // pass by value
    thread t3(f2, std::ref(n)); // pass by reference
    thread t4(std::move(t3));   // t4 is now running f2(). t3 is no longer a thread

    t2.join();
    t4.join();
    cout << "Final value of n is " << n << endl;

    return 0;
}
