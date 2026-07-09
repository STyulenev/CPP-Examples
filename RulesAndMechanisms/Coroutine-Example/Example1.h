#pragma once

#include <iostream>
#include <coroutine>

/*
 * Простой пример корутины
 */

namespace Example1
{

// Определяем структуру Task, которая представляет корутину
struct Task
{
    // promise_type управляет состоянием корутины
    struct promise_type
    {
        // Создаем объект Task при запуске корутины
        Task get_return_object()
        {
            // Получаем handle на корутину из promise
            return Task{std::coroutine_handle<promise_type>::from_promise(*this)};
        }

        // При начальной приостановке корутина сразу приостанавливается
        std::suspend_always initial_suspend()
        {
            return {};
        }

        // При завершении корутины она также приостанавливается
        std::suspend_always final_suspend() noexcept
        {
            return {};
        }

        // Для функции, которая ничего не возвращает (void)
        void return_void()
        {

        }

        // Если есть возврат значения
        // void return_value(type value)
        // {
        //     result = value;
        // }

        // Обработка исключений (завершение программы при ошибке)
        void unhandled_exception()
        {
            std::terminate();
        }
    };

    // Handle на корутину (используется для управления выполнением)
    std::coroutine_handle<promise_type> handle;

    // Конструктор для инициализации handle
    Task(std::coroutine_handle<promise_type> h) : handle(h)
    {

    }

    // Деструктор — уничтожает handle, если он есть
    ~Task()
    {
        if (handle)
        {
            handle.destroy();
        }
    }

    // Метод для возобновления выполнения корутины
    void resume()
    {
        handle.resume();
    }

    // Метод для проверки, завершена ли корутина
    bool done() const
    {
        return handle.done();
    }
};

// Определение корутины
Task simple_coroutine()
{
    std::cout << "Start\n";

    // Приостанавливаем выполнение корутины здесь
    co_await std::suspend_always{};

    std::cout << "Continue\n";
}

void test()
{
    // Создаем объект корутины, запуск ее выполнения
    auto task = simple_coroutine();

    // Первая остановка: корутина приостановилась после первого вывода
    task.resume();

    // Проверяем, завершена ли корутина
    if (!task.done())
    {
        std::cout << "End\n";
    }

    // Возобновляем выполнение корутины
    task.resume();

    // После этого корутина завершена
}

} // namespace Example1
