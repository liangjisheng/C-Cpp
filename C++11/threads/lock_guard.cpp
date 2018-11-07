#include <iostream>
#include <thread>
#include <mutex>            // std::mutex, std::lock_guard
#include <stdexcept>        // std::logic_error

std::mutex mtx;

void print_even(int x)
{
    if (0 == x % 2) std::cout << x << " is even\n";
    else throw (std::logic_error("not even"));
}

void print_thread_id(int id)
{
    try {
        // using a local lock_guard to lock mtx guarantee unlocking
        // on destruction / exception:
        std::lock_guard<std::mutex> lck(mtx);
        print_even(id);
    }
    catch (std::logic_error&) {
        std::cout << "[exception caught]\n";
    }
}

int main()
{
    std::thread ths[10];
    for (int i = 0; i < 10; ++i)
        ths[i] = std::thread(print_thread_id, i+1);
    for (auto& th : ths)
        th.join();

    return 0;
}
