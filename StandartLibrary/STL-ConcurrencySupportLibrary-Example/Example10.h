#pragma once

#include <iostream>
#include <thread>
#include <future>
/*
 * =======================================================================================================================================================================
 *                                                                           Futures
 * =======================================================================================================================================================================
 *
 * Futures:
 * - promise
 * - packaged_task
 * - future
 * - shared_future
 * - async
 * - launch
 * - future_status
 *
 * Future errors:
 * - future_error
 * - future_category
 * - future_errc
 *
 */

namespace Example10 {

namespace F1 { // ------------------------------------ Простой пример ассинхронности (promise и future)

int add(int a, int b)
{
    return a + b;
}

void test()
{
    // Создаём обещание и связанное с ним будущее
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    // Запускаем ассинхронный поток и устанавливаем результат обещания
    std::thread([&promise]() {
        int result = add(2, 3);
        promise.set_value(result);
    }).detach();

    // Ожидание ассинхронного потока
    int result = future.get();

    std::cout << "Result: " << result << std::endl;
}

} // namespace F1



namespace F2 { // ------------------------------------ Простой пример ассинхронности 2 (выброс ошибки)

int divide(int a, int b)
{
    if (b == 0) {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

void test()
{
    // Создаём обещание и связанное с ним будущее
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    // Запускаем ассинхронный поток и устанавливаем результат обещания
    std::thread([&promise]() {
        try {
            int result = divide(10, 0);
            promise.set_value(result);
        } catch (const std::exception& e) {
            // Пробрасываем исключение
            promise.set_exception(std::current_exception());
        }
    }).detach();

    // Ожидание ассинхронного потока
    try {
        int result = future.get();
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

} // namespace F2



namespace F3 { // ------------------------------------ Простой пример ассинхронности 3 (std::async)

int add(int a, int b)
{
    std::cout << "Thread id (add): " << std::this_thread::get_id() << std::endl;

    return a + b;
}

void test()
{
    // Сокращенный вызов ассинхронного потока
    std::future<int> future = std::async(std::launch::async, add, 2, 3);

    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    std::cout << "Thread id (test): " << std::this_thread::get_id() << std::endl;

    // Ожидание ассинхронного потока
    int result = future.get();

    std::cout << "Result: " << result << std::endl;
}

} // namespace F3



namespace F4 { // ------------------------------------ Простой пример ассинхронности 4 (std::async + исключение)

int divide(int a, int b)
{
    if (b == 0) {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

void test()
{
    auto asthread = std::async(divide, 2, 0);

    try {
        asthread.get();
    } catch(const std::exception& error) {
        std::cout << error.what() << std::endl;
    }
}

} // namespace F4



namespace F5 { // ------------------------------------ Простой пример ассинхронности 5 (std::launch)

int add(int a, int b)
{
    std::cout << "Thread id (add): " << std::this_thread::get_id() << std::endl;

    return a + b;
}

void test()
{
    /*
     * std::launch::async - вызов функции в новом потоке сразу
     * std::launch::deferred - ожидание вызыва до wait() или get()
     * std::launch::async | std::launch::deferred - по умолчанию, выбор предоставлен реализации
     */
    {
        auto asthread = std::async(std::launch::async, add, 2, 2);

        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        std::cout << "Thread id (test): " << std::this_thread::get_id() << std::endl;

        int result = asthread.get();
        std::cout << "Result: " << result << std::endl;
    }

    {
        auto asthread = std::async(std::launch::deferred, add, 2, 2);

        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        std::cout << "Thread id (test): " << std::this_thread::get_id() << std::endl;

        int result = asthread.get();
        std::cout << "Result: " << result << std::endl;
    }

    {
        auto asthread = std::async(std::launch::async | std::launch::deferred, add, 2, 2);

        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        std::cout << "Thread id (test): " << std::this_thread::get_id() << std::endl;

        int result = asthread.get();
        std::cout << "Result: " << result << std::endl;
    }
}

} // namespace F5

} // namespace Example10
