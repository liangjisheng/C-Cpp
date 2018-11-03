#include <iostream>
#include <atomic>
#include <vector>
#include <thread>
#include <sstream>

using namespace std;

// atomic_flag是一个原子的bool类型，支持两种原子操作
// test_and_set,如果atomic_flag对象被设置返回true,未被设置返回false
// clear:清除atomic_flag对象
std::atomic_flag lock = ATOMIC_FLAG_INIT;
std::stringstream stream;

void append_numer(int x)
{
    while (lock.test_and_set());
    stream << "thread#" << x << endl;
    lock.clear();
}


int main()
{
    vector<thread> ths;
    for (int i = 0; i < 10; i++)
        ths.push_back(thread(append_numer, i));
    for (int i = 0; i < 10; i++)
        ths[i].join();
    cout << stream.str();

    return 0;
}
