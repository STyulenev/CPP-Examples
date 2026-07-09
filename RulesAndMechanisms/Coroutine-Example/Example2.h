#pragma once

#include <iostream>
#include <coroutine>
#include <thread>
#include <chrono>

/*
 * Пример корутины c дополнительными класами-обёртками
 */

namespace Example2
{

// Структура для хранения результата задачи
struct Result
{
    int value;
};

// Класс, представляющий асинхронную задачу, реализующую корутину
struct AsyncTask
{
    // promise_type — тип обещания корутины, управляет её состоянием
    struct promise_type
    {
        Result result_; // Хранит результат корутины

        // Создает объект задачи из промиса
        auto get_return_object()
        {
            // Возвращает объект AsyncTask, связанный с этим промисом
            return AsyncTask{ std::coroutine_handle<promise_type>::from_promise(*this) };
        }

        // Первоначальная точка приостановки — suspend_always, чтобы управлять запуском вручную
        auto initial_suspend()
        {
            return std::suspend_always{};
        }

        // Конечная точка приостановки — тоже suspend_always, чтобы контролировать завершение
        auto final_suspend() noexcept
        {
            return std::suspend_always{};
        }

        // Устанавливает результат, когда корутина завершена
        void return_value(Result res)
        {
            result_ = res;
        }

        // Обработка исключений (завершение программы при ошибке)
        void unhandled_exception()
        {
            std::terminate();
        }
    };

    // Хендл на корутину
    std::coroutine_handle<promise_type> handle;

    // Конструктор
    explicit AsyncTask(std::coroutine_handle<promise_type> h) : handle(h)
    {

    }

    // Деструктор — уничтожает корутину, если она еще активна
    ~AsyncTask()
    {
        if (handle)
        {
            handle.destroy();
        }
    }

    // Метод, который запускает корутину и ждет её завершения
    // Может не понадобится, если в RequestAwaitable::await_suspend сделать
    // синхронный код вместо нового потока или передать управление далее обработчику,
    // который вернёт резёльтат
    Result run()
    {
        handle.resume(); // Запускаем корутину с первым вызовом

        // Ожидаем завершения корутины
        while (!handle.done())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        // После завершения извлекаем результат
        auto res = handle.promise().result_;
        // Освобождаем ресурсы корутины
        handle.destroy();
        handle = nullptr;
        return res;
    }
};

// Класс, реализующий задержку (имитацию асинхронной задержки)
struct RequestAwaitable
{
    std::chrono::milliseconds duration; // Время задержки
    Result result;

    RequestAwaitable(std::chrono::milliseconds d) :
        duration(d),
        result(Result{})
    {

    }

    // Метод, вызываемый при ожидании: возвращает false, чтобы корутина приостановилась
    bool await_ready() const noexcept { return false; }

    // Метод, который вызывается при приостановке корутины
    void await_suspend(std::coroutine_handle<> h)
    {
        // Запускаем отдельный поток, который спит и затем возобновляет корутину
        std::thread([h, this]() {
            this->result = Result{42};
            std::this_thread::sleep_for(duration);
            h.resume(); // Возобновляем выполнение корутины после задержки
        }).detach();
    }

    // Метод, вызываемый при возобновлении корутины
    Result await_resume() const noexcept
    {
        // Возвращает результат после задержки
        return this->result;
    }
};

// Асинхронная функция, которая создает корутину и управляет её выполнением
AsyncTask doTask()
{
    // Ожидаем задержку и получаем результат
    Result info = co_await RequestAwaitable{std::chrono::milliseconds(500)};
    // Возвращаем результат как завершение корутины
    co_return info;
}

void test()
{
    // Создаем задачу
    auto task = doTask();

    // Запускаем корутину и ждем её завершения, получая результат
    auto result = task.run();

    // Выводим полученный результат
    std::cout << "Result value: " << result.value << std::endl;
}

} // namespace Example2
