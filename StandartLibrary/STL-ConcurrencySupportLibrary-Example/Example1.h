#pragma once

#include <iostream>
#include <thread>

/*
 * =======================================================================================================================================================================
 *                                                                           Threads
 * =======================================================================================================================================================================
 *
 * Threads:
 * - thread
 * - jthread
 *
 * Functions managing the current thread:
 * - yield
 * - get_id
 * - sleep_for
 * - sleep_until

 *
 */

namespace Example1 {

namespace T1 { // ------------------------------------ thread

void func(int n)
{
    std::cout << "Thread id (func): " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

// Пример с функцией в параллельном потоке (с ожиданием потока)
void test_1()
{
    std::thread t(func, 5);

    std::cout << "Thread id (test_1): " << std::this_thread::get_id() << std::endl;

    // ...

    if (t.joinable())
        t.join();
}

// Пример с функцией в параллельном потоке (без ожидания потока)
void test_2()
{
    std::thread t(func, 5);

    std::cout << "Thread id (test_2): " << std::this_thread::get_id() << std::endl;

    // ...

    if (t.joinable())
        t.detach();

    // В потоке произойдёт std::terminate, если t будет уничтожено раньше завершения вычисления
    //std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Задержка
}

// Пример с функцией в параллельном потоке (с joinable == true)
void test_3()
{
    std::thread t(func, 5);

    std::cout << "Thread id (test_3): " << std::this_thread::get_id() << std::endl;

    // Будет std::terminate, т.к. ни join, ни detach не были вызваны.
}

void test()
{
    test_1();
    test_2();
    //test_3();
}

} // namespace T1



namespace T3 { // ------------------------------------ yield

void func(bool status, int id)
{
    if (status) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    } else {
        // Здесь поток приостановится и предоставит приоритет другим
        // на небольшой промежуток времени
        std::this_thread::yield();
    }

     std::cout << "Thread id (func): " << id << std::endl;
}

void test()
{
    std::thread t1(func, true,  1);
    std::thread t2(func, false, 2);
    std::thread t3(func, true,  3);

    t1.join();
    t2.join();
    t3.join();
}

} // namespace T3



namespace T4 { // ------------------------------------ get_id

void func()
{
    // Выводит id потока
    std::cout << "Thread id (func): " << std::this_thread::get_id() << std::endl;
}

void test()
{
    std::thread t1(func);
    std::thread t2(func);
    std::thread t3(func);

    t1.join();
    t2.join();
    t3.join();
}

} // namespace T4



namespace T5 { // ------------------------------------ sleep_for

void func()
{
    // Блокировка выполнения потока на 1000 мс
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void test()
{
    std::thread t(func);
    t.join();
}

} // namespace T5



namespace T6 { // ------------------------------------ sleep_until

void func()
{
    // Блокировка выполнения потока до определенного времени (текущее время + 1000 мс)
    std::this_thread::sleep_until( std::chrono::steady_clock::now() + std::chrono::milliseconds(1000));
}

void test()
{
    std::thread t(func);
    t.join();
}

} // namespace T6

} // namespace Example1
