#include "ProducerConsumer.h"

#include <iostream>

void ProducerConsumer::producer(int id)
{
    // Каждый производитель создаёт 20-ть элементов для очереди
    for (int i = 0; i < 20; ++i)
    {
        std::unique_lock<std::mutex> lock(mtx);

        // Блокируем очередь, если нет места
        cv.wait(lock, [this]() {
            return data_queue.size() < max_size;
        });

        data_queue.push(i);
        std::cout << "Producer " << id << " produced: " << i << std::endl;

        lock.unlock();
        cv.notify_all();

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void ProducerConsumer::consumer(int id)
{
    while (!done || !data_queue.empty())
    {
        std::unique_lock<std::mutex> lock(mtx);

        // Если очередь имеет хоть один элемент, то притупаем к обработке
        // Иноче ждём
        if (cv.wait_for(lock, std::chrono::milliseconds(100), [this]() { return !data_queue.empty(); }))
        {

            int item = data_queue.front();
            data_queue.pop();

            lock.unlock();

            std::cout << "Consumer " << id << " consumed: " << item << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
}

void ProducerConsumer::setDone()
{
    done = true;

    cv.notify_all();
}
