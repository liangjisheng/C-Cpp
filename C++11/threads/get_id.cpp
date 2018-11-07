#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;

void foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}


int main()
{
    std::thread t1(foo);
    std::thread::id t1_id = t1.get_id();

    std::thread t2(foo);
    std::thread::id t2_id = t2.get_id();

    cout << "t1's id: " << t1_id << endl;
    cout << "t2's id: " << t2_id << endl;

    t1.join();
    t2.join();

    return 0;
}
