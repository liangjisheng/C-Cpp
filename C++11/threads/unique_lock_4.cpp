#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mtx;
int count = 0;

void print_count_and_unlock(std::mutex* p_mtx)
{
    std::cout << "count: " << count << '\n';
    p_mtx->unlock();
}

void task()
{
    std::unique_lock<std::mutex> lck(mtx);
    ++count;
    // lck.release()返回lck所管理的mutex对象的指针，并释放所有权
    print_count_and_unlock(lck.release());
}


int main()
{
    std::vector<std::thread> ths;
    for (int i=0; i<10; ++i)
        ths.emplace_back(task);
    for (auto& th : ths)
        th.join();

    return 0;
}
