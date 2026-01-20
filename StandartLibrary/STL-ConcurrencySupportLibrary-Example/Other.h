#pragma once

#include <iostream>
#include <thread>
#include <future>

namespace Other {

// Простой пример использования нескольких потоков
namespace Ex1 {

void job1(int& result)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Имитация работы
    result = 50; // Получения результата
}

void job2(int& result)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Имитация работы
    result = 30; // Получения результата
}

void test()
{
    int result1 = 0;
    int result2 = 0;

    // Создаем потоки
    std::thread t1(job1, std::ref(result1));
    std::thread t2(job2, std::ref(result2));

    // Основная работа

    // Ждем завершения потоков
    t1.join();
    t2.join();

    std::cout << "Result: " << result1 + result2 << std::endl;
}

} // namespace Ex1



// Простой пример использования нескольких потоков с лямбдами
namespace Ex2 {

void test()
{
    int result1 = 0;
    int result2 = 0;

    auto job1 = [result = &result1]() mutable -> void
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Имитация работы
        *result = 50; // Получения результата
    };

    auto job2 = [result = &result2]() mutable -> void
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Имитация работы
        *result = 30; // Получения результата
    };

    // Создаем потоки
    std::thread t1(job1);
    std::thread t2(job2);

    // Основная работа

    // Ждем завершения потоков
    t1.join();
    t2.join();

    std::cout << "Result: " << result1 + result2 << std::endl;
}

} // namespace Ex2



// Простой пример использования нескольких ассинхронных потоков (высокоуровневый подход std::async + std::future)
namespace Ex3 {

int job1()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Имитация работы
    return 50; // Получения результата
}

int job2()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Имитация работы
    return 30; // Получения результата
}

void test()
{
    // Запускаем асинхронные задачи
    // std::launch::async - гарантирует запуск в отдельном потоке
    std::future<int> future1 = std::async(std::launch::async, job1);
    std::future<int> future2 = std::async(std::launch::async, job2);

    // Основная работа
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Получаем результаты (блокируем, если результат еще не готов)
    int result1 = future1.get();
    int result2 = future2.get();

    std::cout << "Result: " << result1 + result2 << std::endl;
}

} // namespace Ex3



// Простой пример использования нескольких ассинхронных потоков (низкоуровневый подход std::promise + std::future)
namespace Ex4 {

void job1(std::promise<int>&& promise)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Имитация работы
    promise.set_value(50); // Получения результата
}

void job2(std::promise<int>&& promise)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Имитация работы
    promise.set_value(30); // Получения результата
}

void test()
{
    std::promise<int> promise1;
    std::promise<int> promise2;
    std::future<int> future1 = promise1.get_future();
    std::future<int> future2 = promise2.get_future();

    std::thread worker1(job1, std::move(promise1));
    std::thread worker2(job2, std::move(promise2));

    // Основная работа
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Получаем результаты (блокируем, если результат еще не готов)
    int result1 = future1.get();
    int result2 = future2.get();

    worker1.join();
    worker2.join();

    std::cout << "Result: " << result1 + result2 << std::endl;
}

} // namespace Ex4

} // namespace Other
