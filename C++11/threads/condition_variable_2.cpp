#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>   // std::cv_status

using std::cout;
using std::endl;

std::condition_variable cv;
int value;

void do_read_value()
{
    std::cin >> value;
    // 唤醒某个等待(wait)线程，如果当前没有等待线程，则该函数什么也不做，
    // 如果同时存在多个等待线程，则唤醒某个线程是不确定的
    cv.notify_one();
}


int main()
{
    cout << "Please, enter an integer (I'll be printing dots): \n";
    std::thread th(do_read_value);

    std::mutex mtx;
    std::unique_lock<std::mutex> lck(mtx);
    while (cv.wait_for(lck, std::chrono::seconds(1)) == std::cv_status::timeout)
    {
        cout << '.';
        cout.flush();
    }

    cout << "You entered: " << value << endl;
    th.join();

    return 0;
}
