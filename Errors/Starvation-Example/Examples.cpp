#include "Examples.h"

#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>

namespace Example1
{

std::mutex resource_mutex;
int shared_resource = 0;

void worker(int id, int priority_work)
{
    for (int i = 0; i < priority_work; ++i)
    {
        std::lock_guard<std::mutex> lock(resource_mutex);

        // Длительная работа с ресурсом
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        shared_resource++;
        std::cout << "Thread " << id << " incremented to " << shared_resource << std::endl;
    }
}

void test()
{
    // Поток 1 делает много работы, поток 2 может "голодать", т.е. слишком много времени простаивает, хотя
    // мог бы освободиться раньше
    std::thread t1(worker, 1, 100); // Много работы
    std::thread t2(worker, 2, 10);  // Мало работы

    t1.join();
    t2.join();
}

} // namespace Example1

namespace Example2
{

std::mutex high_priority_mutex;
std::atomic<bool> high_priority_done(false);

void highPriorityWorker()
{
    while (!high_priority_done)
    {
        std::lock_guard<std::mutex> lock(high_priority_mutex);
        // Постоянно занимает мьютекс
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << "High priority thread working..." << std::endl;
    }
}

void lowPriorityWorker()
{
    // Этот поток может никогда не получить мьютекс
    for (int i = 0; i < 5; ++i)
    {
        std::lock_guard<std::mutex> lock(high_priority_mutex);  // Может никогда не получить доступ
        std::cout << "Low priority thread working..." << std::endl;
    }
}

void test()
{
    std::thread t1(highPriorityWorker);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::thread t2(lowPriorityWorker);

    std::this_thread::sleep_for(std::chrono::seconds(2));
    high_priority_done = true;

    t1.join();
    t2.join();
}

} // namespace Example2


namespace Example3
{

std::shared_mutex rw_mutex;
int data = 0;

void writer(int id)
{
    for (int i = 0; i < 5; ++i)
    {
        std::unique_lock lock(rw_mutex);  // Эксклюзивная блокировка
        data++;
        std::cout << "Writer " << id << " wrote: " << data << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Долгая запись
    }
}

void reader(int id)
{
    for (int i = 0; i < 10; ++i)
    {
        std::shared_lock lock(rw_mutex);  // Разделяемая блокировка

        std::cout << "Reader " << id << " read: " << data << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void test()
{
    std::vector<std::thread> writers;
    std::vector<std::thread> readers;

    // Много писателей могут блокировать читателей
    for (int i = 0; i < 3; ++i)
    {
        writers.emplace_back(writer, i);
    }

    for (int i = 0; i < 5; ++i)
    {
        readers.emplace_back(reader, i);
    }

    for (auto& w : writers)
    {
        w.join();
    }

    for (auto& r : readers)
    {
        r.join();
    }
}

} // namespace Example3
