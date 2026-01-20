#pragma once

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

/*
 * =======================================================================================================================================================================
 *                                                                        Condition variables
 * =======================================================================================================================================================================
 *
 * Условная переменная — это примитив синхронизации, который позволяет нескольким потокам общаться друг с другом. Она позволяет некоторому количеству
 * потоков ждать (возможно, с тайм-аутом) уведомления от другого потока о том, что они могут продолжить. Условная переменная всегда связана с мьютексом.
 *
 * Mutual exclusion:
 * - condition_variable
 * - condition_variable_any
 * - notify_all_at_thread_exit
 * - cv_status
 *
 */

namespace Example7 {

namespace CV1 { // ------------------------------------ condition_variable

std::mutex m;
std::condition_variable cv;
bool ready = false;

void func()
{
    std::cout << "Thread id (func): " << std::this_thread::get_id() << std::endl;

    // Ожидание разрешение на продолжение
    std::unique_lock lk(m); // condition_variable работает только с unique_lock
    cv.wait(lk, []{ return ready; }); // Ожидание до уведомления

    // Продолжение работы
    std::cout << "Thread id (func): " << std::this_thread::get_id() << " is ready" << std::endl;

    // ...

    lk.unlock();
}

void test()
{
    std::thread t(func);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    // ...

    {
        std::lock_guard lk(m);
        // Разрешаем выполнение потока
        ready = true;
        std::cout << "Thread id (test_1): " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }

    // После уведомления поток t продолжит выполнение
    cv.notify_one();   // Один поток
    //cv.notify_all(); // Все потоки

    t.join();
}

} // namespace CV1



namespace CV1_1 { // ------------------------------------ condition_variable

std::queue<int> data_queue;
std::mutex queue_mutex;
std::condition_variable queue_cv;
bool production_complete = false;

void producer(int items_count) {
    for (int i = 0; i < items_count; ++i) {
        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            data_queue.push(i);
            std::cout << "Producer: added element " << i << std::endl;
        }
        queue_cv.notify_one();  // Уведомляем одного потребителя
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    {
        std::lock_guard<std::mutex> lock(queue_mutex);
        production_complete = true;
        std::cout << "Producer: finish work" << std::endl;
    }
    queue_cv.notify_all();  // Уведомляем всех потребителей
}

void consumer(int consumer_id) {
    while (true) {
        std::unique_lock<std::mutex> lock(queue_mutex);

        // Ждем, пока появятся данные или производство завершится
        queue_cv.wait(lock, []() {
            return !data_queue.empty() || production_complete;
        });

        // Если очередь пуста и производство завершено - выходим
        if (data_queue.empty() && production_complete) {
            std::cout << "Consumer " << consumer_id << ": finish work" << std::endl;
            break;
        }

        // Берем данные из очереди
        if (!data_queue.empty()) {
            int item = data_queue.front();
            data_queue.pop();
            lock.unlock();  // Освобождаем мьютекс раньше

            // Обрабатываем элемент
            std::cout << "Consumer " << consumer_id << ": processed element " << item << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }
    }
}

void test()
{
    const int items_count = 10;
    const int consumers_count = 3;

    std::thread prod(producer, items_count);
    std::vector<std::thread> consumers;

    for (int i = 0; i < consumers_count; ++i) {
        consumers.emplace_back(consumer, i + 1);
    }

    prod.join();

    for (auto& t : consumers) {
        t.join();
    }

    std::cout << "End" << std::endl;
}

} // namespace CV1_1

namespace CV2 { // ------------------------------------ condition_variable_any

std::mutex m;
std::condition_variable_any cva;
bool ready = false;

void func()
{
    std::cout << "Thread id (func): " << std::this_thread::get_id() << std::endl;

    m.lock();
    // Ожидание разрешение на продолжение
    cva.wait(m, []{ return ready; }); // Ожидание до уведомления

    // Продолжение работы
    std::cout << "Thread id (func): " << std::this_thread::get_id() << " is ready" << std::endl;

    m.unlock();
}

void test()
{
    std::thread t(func);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    // ...

    {
        std::lock_guard lk(m);
        // Разрешаем выполнение потока
        ready = true;
        std::cout << "Thread id (test_1): " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }

    // После уведомления поток t продолжит выполнение
    cva.notify_one();   // Один поток
    //cv.notify_all(); // Все потоки

    t.join();
}

} // namespace CV2

} // namespace Example7
