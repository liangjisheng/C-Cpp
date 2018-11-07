#include <iostream>
#include <thread>
#include <mutex>

class MyMutex : public std::mutex
{
    int _id;
public:
    MyMutex (int id) : _id(id) {}
    int id() { return _id; }
};

MyMutex mtx(101);

void print_ids (int id)
{
    std::unique_lock<MyMutex> lck(mtx);
    // lck.mutex()返回所管理mutex对象的指针
    std::cout << "thread #" << id << " locked mutex " << lck.mutex()->id() << '\n';
}

int main()
{
    std::thread ths[10];
    for (int i=0; i<10; ++i)
        ths[i] = std::thread(print_ids, i+1);
    for (auto& th : ths)
        th.join();

    return 0;
}
