#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id(int id)
{
    unique_lock<mutex> lck(mtx);
    while (!ready) cv.wait(lck);

    cout << "thread " << id << endl;
}

void go()
{
    unique_lock<mutex> lck(mtx);
    ready = true;
    cv.notify_all();
}


int main()
{
    thread ths[10];
    for (int i = 0; i < 10; ++i)
        ths[i] = thread(print_id, i);

    cout << "10 threads ready to race..." << endl;
    go();

    for (auto& th :ths)
        th.join();

    return 0;
}
