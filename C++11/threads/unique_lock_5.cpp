#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_star()
{
    std::unique_lock<std::mutex> lck(mtx,std::try_to_lock);
    // print '*' if successfully locked, 'x' otherwise:
    // owns_lock()返回当前unique_lock对象是否获得了锁

    // std::unique_lock::operator bool()
    // 与owns_lock()一样返回当前unique_lock对象是否获得了锁
    // 重载了bool，所以unique_lock可以隐式转换为bool类型
    if (lck.owns_lock())    // equal to if (lck)
      std::cout << '*';
    else
      std::cout << 'x';
}

int main()
{
    std::vector<std::thread> ths;
    for (int i=0; i<10; ++i)
        ths.emplace_back(print_star);
    for (auto& th : ths)
        th.join();

    return 0;
}
