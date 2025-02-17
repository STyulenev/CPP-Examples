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

namespace T1 { // ------------------------------------ Умный указатель с уникальной семантикой владения объектом (unique_ptr)

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

    t.join();
}

// Пример с функцией в параллельном потоке (без ожидания потока)
void test_2()
{
    std::thread t(func, 5);

    std::cout << "Thread id (test_1): " << std::this_thread::get_id() << std::endl;

    // ...

    t.detach();

    // В потоке произойдёт std::terminate, если t будет уничтожено раньше завершения вычисления
    //std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Задержка
}

void test()
{
    test_1();
    test_2();
}

} // namespace T1

} // namespace Example1
