// 单生产者单消费者

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <condition_variable>
#include <mutex>
#include <thread>

static const int kItemRepositorySize = 10;  // Item buffer size
static const int kItemsToProduce = 1000;    // How many item we plan to produce.

struct ItemRepository
{
    // 产品缓冲区，配合read_position 和 write_position模型环形队列
    int item_buffer[kItemRepositorySize];
    size_t read_position;   // 消费者读取产品位置
    size_t write_position;  // 生产者写入产品位置
    std::mutex mtx; // 互斥量
    std::condition_variable repo_not_full;  // 指示产品缓冲区不满
    std::condition_variable repo_not_empty; // 指示产品缓冲区不空
} gItemRepository;  // 产品库全局变量，生产者和消费者操作该变量

typedef struct ItemRepository ItemRepository;

void ProduceItem(ItemRepository *ir, int item)
{
    std::unique_lock<std::mutex> lck(ir->mtx);
    while (((ir->write_position + 1) % kItemRepositorySize) == ir->read_position)
    {
        std::cout << "Producer is waiting for an empty slot...\n";
        // 生产者当代"缓冲区不满"这一条件发生
        (ir->repo_not_full).wait(lck);
    }

    (ir->item_buffer)[ir->write_position] = item;   // 写入产品
    (ir->write_position)++; // 写入位置后移

    if (ir->write_position == kItemRepositorySize)
        ir->write_position = 0;

    (ir->repo_not_empty).notify_all();  // 通知消费者产品库不为空
    lck.unlock();
}

int ConsumeItem(ItemRepository *ir)
{
    int data;
    std::unique_lock<std::mutex> lck(ir->mtx);
    // item buffer si empty, just wait here.
    while (ir->write_position == ir->read_position)
    {
        std::cout << "Consumer is waiting for items...\n";
        // 消费者等待产品库不空者一个条件发生
        (ir->repo_not_empty).wait(lck);
    }

    data = (ir->item_buffer)[ir->read_position];
    (ir->read_position)++;

    if (ir->read_position >= kItemRepositorySize)
        ir->read_position = 0;

    (ir->repo_not_full).notify_all();
    lck.unlock();

    return data;
}

void ProducerTask()  // 生产者任务
{
    for (int i = 1; i <= kItemsToProduce; ++i)
    {
        std::cout << "Produce the " << i << "^th item..." << std::endl;
        ProduceItem(&gItemRepository, i);   // 循环生产kItemsToProduce个产品
    }
}

void ConsumerTask() // 消费者任务
{
    static int cnt = 0;
    while (1)
    {
        sleep(1);
        int item = ConsumeItem(&gItemRepository);   // 消费一个产品
        std::cout << "Consume the " << item << "^th item" << std::endl;
        // 如果产品消费个数为 kItemsToProduce, 则退出.
        if (++cnt == kItemsToProduce)
            break;
    }
}

void InitItemRepository(ItemRepository *ir)
{
    ir->write_position = 0; // 初始化产品写入位置
    ir->read_position = 0;  // 初始化产品读取位置
}


int main()
{
    InitItemRepository(&gItemRepository);
    std::thread producer(ProducerTask);
    std::thread consumer(ConsumerTask);
    producer.join();
    consumer.join();

    return 0;
}
