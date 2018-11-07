#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void thread_task(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
    cout << "hello, thread " << std::this_thread::get_id()
         << " paused " << n << " seconds" << endl;
}


int main()
{
    std::thread ths[5];
    cout << "Spawing 5 threads..." << endl;
    for (int i = 0; i < 5; ++i)
        ths[i] = std::thread(thread_task, i + 1);
    cout << "Done spawing threads! Now wait for them to join." << endl;
    for (auto& t : ths)
        t.join();
    cout << "All threads joined." << endl;

    return 0;
}
