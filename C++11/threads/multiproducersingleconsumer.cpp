// 与单生产者和单消费者模型不同的是, 多生产者-单消费者模型中可以允许多个生产者同时向产品库中放入产品
// 所以除了保护产品库在多个读写线程下互斥之外，还需要维护生产者放入产品的计数器

#include <unistd.h>
#include <cstdlib>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

static const int kItemRepositorySize  = 4; // Item buffer size.
static const int kItemsToProduce  = 10;   // How many items we plan to produce.

struct ItemRepository
{
    int item_buffer[kItemRepositorySize];
    size_t read_position;
    size_t write_position;
    size_t item_counter;
    std::mutex mtx;
    std::mutex item_counter_mtx;
    std::condition_variable repo_not_full;
    std::condition_variable repo_not_empty;
} gItemRepository;

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

void ProducerTask()
{
    bool ready_to_exit = false;
    while (1)
    {
        sleep(1);
        std::unique_lock<std::mutex> lck(gItemRepository.item_counter_mtx);
        if (gItemRepository.item_counter < kItemsToProduce) // 生产者未生产完产品
        {
            ++(gItemRepository.item_counter);
            ProduceItem(&gItemRepository, gItemRepository.item_counter);;
            std::cout << "Producer thread " << std::this_thread::get_id()
                      << " is producing the " << gItemRepository.item_counter
                      << "^th item" << std::endl;
        }
        else
            ready_to_exit = true;

        lck.unlock();
        if (ready_to_exit)
            break;
    }
    std::cout << "Producer thread " << std::this_thread::get_id()
              << " is exiting..." << std::endl;
}

void ConsumerTask()
{
    static int item_consumed = 0;
    while (1)
    {
        sleep(1);
        ++item_consumed;
        if (item_consumed <= kItemsToProduce)   // 未消费完产品
        {
            int item = ConsumeItem(&gItemRepository);
            std::cout << "Consumer thread " << std::this_thread::get_id()
                      << " is consuming the " << item << "^th item" << std::endl;
        }
        else
            break;
    }

    std::cout << "Consumer thread " << std::this_thread::get_id()
              << " is exiting..." << std::endl;
}

void InitItemRepository(ItemRepository *ir)
{
    ir->write_position = 0;
    ir->read_position = 0;
    ir->item_counter = 0;
}


int main()
{
    InitItemRepository(&gItemRepository);
    std::thread producer1(ProducerTask);
    std::thread producer2(ProducerTask);
    std::thread producer3(ProducerTask);
    std::thread producer4(ProducerTask);
    std::thread consumer(ConsumerTask);

    producer1.join();
    producer2.join();
    producer3.join();
    producer4.join();
    consumer.join();

    return 0;
}
