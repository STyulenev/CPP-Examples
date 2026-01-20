#pragma once

#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>

/*
 * =======================================================================================================================================================================
 *                                                                           Mutual exclusion
 * =======================================================================================================================================================================
 *
 * Mutual exclusion:
 * - mutex
 * - timed_mutex
 * - recursive_mutex
 * - recursive_timed_mutex
 * - shared_mutex
 * - shared_timed_mutex
 *
 * Generic mutex management:
 * - lock_guard
 * - scoped_lock
 * - unique_lock
 * - shared_lock
 * - defer_lock
 * - try_to_lock
 * - adopt_lock
 * - defer_lock_t
 * - try_to_lock_t
 * - adopt_lock_t
 *
 * Generic locking algorithms:
 * - try_lock
 * - lock
 *
 * Call once:
 * - once_flag
 * - call_once
 *
 */

namespace Example5 {

namespace MX1 { // ------------------------------------ mutex

std::mutex mutex;

// Рабочая функция
void func1()
{
    mutex.lock();

    std::cout << "Thread id (func): " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    mutex.unlock(); // Если забыть, то будет вечная блокировка других потоков
}

// Функция с deadlock
void func2()
{
    mutex.lock();
    mutex.lock(); // deadlock

    std::cout << "Thread id (func): " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    mutex.unlock();
}

// Пример блокировки через mutex
void test_1()
{
    std::thread t1(func1);
    std::thread t2(func1);

    std::cout << "Thread id (test_1): " << std::this_thread::get_id() << std::endl;

    t1.join();
    t2.join();
}

// Пример deadlock
void test_2()
{
    std::thread t1(func2);
    std::thread t2(func2);

    std::cout << "Thread id (test_1): " << std::this_thread::get_id() << std::endl;

    t1.join();
    t2.join();
}

void test()
{
    test_1();
    test_2();
}

} // namespace MX1

namespace MX2 { // ------------------------------------ timed_mutex

std::timed_mutex mutex;

void func()
{
    // Все потоки будут ждать по 20 мс
    if (mutex.try_lock_for(std::chrono::milliseconds(20))) {
        std::cout << "Thread id (func): " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        mutex.unlock(); // Если забыть, то будет вечная блокировка других потоков
    }
}

// Пример блокировки через timed_mutex
void test_1()
{
    std::thread t1(func);
    std::thread t2(func);

    std::cout << "Thread id (test_1): " << std::this_thread::get_id() << std::endl;

    t1.join();
    t2.join();
}

void test()
{
    test_1();
}

} // namespace MX2



namespace MX3 { // ------------------------------------ recursive_mutex

std::recursive_mutex mutex;

void func1(int num)
{
    std::lock_guard<std::recursive_mutex> lk(mutex);
    std::cout << "funс1(), num = " << num << std::endl;
}

void func2(int num)
{
    std::lock_guard<std::recursive_mutex> lk(mutex);
    std::cout << "funс2(), num = " << num << std::endl;

    func1(num);

    std::cout << "funс2(), num = " << num << std::endl;
}

void test()
{
    std::thread t1(func1, 1);
    std::thread t2(func2, 2);

    t1.join();
    t2.join();
}

} // namespace MX3



namespace MX4 { // ------------------------------------ recursive_timed_mutex

std::recursive_timed_mutex rtm;
int shared_resource = 0;

void recursive_function(int depth, int thread_id)
{
    if (depth <= 0) return;

    // Пытаемся захватить мьютекс на 100 мс
    std::cout << "Thread " << thread_id << ": try to lock mutex (depth " << depth << ")..." << std::endl;

    if (rtm.try_lock_for(std::chrono::milliseconds(100)))
    {
        std::cout << "Thread " << thread_id << ": mutes was captured (depth " << depth << ")" << std::endl;

        ++shared_resource;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        // Рекурсивный вызов
        recursive_function(depth - 1, thread_id);

        rtm.unlock();
        std::cout << "Thread " << thread_id << ": mutex was free (depth " << depth << ")" << std::endl;
    }
    else
    {
        std::cout << "Thread " << thread_id << ": mutes wasn't captured on 100ms (depth " << depth << ")" << std::endl;
    }
}

void test()
{
    std::thread t1(recursive_function, 3, 1);
    std::thread t2(recursive_function, 2, 2);

    t1.join();
    t2.join();

    std::cout << "\nResult: " << shared_resource << std::endl;
}

} // namespace MX4



namespace MX5 { // ------------------------------------ shared_mutex

/*
 * std::shared_mutex позволяет реализовать паттерн "множество читателей/один писатель" (multiple readers/single writer)
 *
 * - Если один поток получил эксклюзивную блокировку (через lock , try_lock), то никакие другие потоки не могут получить эту
 * блокировку (включая разделяемую).
 * - Если один поток получил разделяемую блокировку (через lock_shared , try_lock_shared), то ни один другой поток не может
 * получить эксклюзивную блокировку, но может получить разделяемую блокировку.
 * - Только когда эксклюзивная блокировка не была получена ни одним потоком, разделяемая блокировка может быть получена
 * несколькими потоками.
 *
 */

class ThreadSafeData {
private:
    std::shared_mutex mutex_;
    int data_ = 0;

public:
    // Чтение данных (множество потоков может читать одновременно)
    int read() {
        std::shared_lock lock(mutex_);  // Разделяемая блокировка
        // Имитация длительного чтения
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        return data_;
    }

    // Запись данных (только один поток может писать)
    void write(int value) {
        std::unique_lock lock(mutex_);  // Эксклюзивная блокировка
        // Имитация длительной записи
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        data_ = value;
        std::cout << "New value: " << value << std::endl;
    }

    // Инкремент (также требует эксклюзивной блокировки)
    void increment() {
        std::unique_lock lock(mutex_);
        ++data_;
        std::cout << "Increment, new value: " << data_ << std::endl;
    }
};

void reader(ThreadSafeData& data, int reader_id) {
    for (int i = 0; i < 3; ++i) {
        int value = data.read();
        std::cout << "Reader " << reader_id << ": read data "
                  << value << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

void writer(ThreadSafeData& data, int writer_id, int start_value) {
    for (int i = 0; i < 2; ++i) {
        data.write(start_value + i);
        std::cout << "Writer " << writer_id << ": write data " << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void test()
{
    ThreadSafeData data;
    std::vector<std::thread> threads;

    // Создаем читателей
    for (int i = 1; i <= 5; ++i) {
        threads.emplace_back(reader, std::ref(data), i);
    }

    // Создаем писателей
    for (int i = 1; i <= 2; ++i) {
        threads.emplace_back(writer, std::ref(data), i, i * 100);
    }

    // Добавляем еще читателей
    for (int i = 6; i <= 8; ++i) {
        threads.emplace_back(reader, std::ref(data), i);
    }

    // Ждем завершения всех потоков
    for (auto& t : threads) {
        t.join();
    }
}

} // namespace MX5



namespace CO { // ------------------------------------ Call once: once_flag, call_once

std::once_flag flag;

void func()
{
    std::cout << "Call once" << std::endl;
}

void test()
{
    std::call_once(flag, func /* args */);
    std::call_once(flag, func /* args */);
    std::call_once(flag, func /* args */);
    std::call_once(flag, func /* args */);
    std::call_once(flag, func /* args */);
    std::call_once(flag, func /* args */);
}

} // namespace CO

} // namespace Example5
