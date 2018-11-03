#include <iostream>
#include <atomic>
#include <vector>
#include <thread>
#include <sstream>

using namespace std;

std::atomic<int> foo(0);

void set_foo(int x) { foo = x; }

void print_foo()
{
    while (0 == foo)
        this_thread::yield();
    cout << "x: " << foo << endl;
}

int main()
{
    thread print_th(print_foo);
    thread set_th(set_foo, 10);
    print_th.join();
    set_th.join();

    return 0;
}
