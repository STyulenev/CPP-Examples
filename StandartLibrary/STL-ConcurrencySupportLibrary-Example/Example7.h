#pragma once

#include <condition_variable>
#include <iostream>
#include <mutex>
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
    std::unique_lock lk(m);
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

} // namespace Example7
