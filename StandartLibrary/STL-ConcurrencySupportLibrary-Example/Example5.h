#pragma once

#include <iostream>
#include <mutex>
#include <thread>

/*
 * =======================================================================================================================================================================
 *                                                                           Mutual
 * exclusion
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
