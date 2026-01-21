#pragma once

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>

/*
 * Основной класс с пулом потоков.
 *
 * Ключевые компоненты
 * - Очередь задач (Task Queue) — потокобезопасная очередь, куда помещаются задачи (функции, лямбды, функторы).
 * - Воркеры (Worker Threads) — потоки, которые постоянно извлекают и выполняют задачи из очереди.
 * - Диспетчер (Manager/Interface) — интерфейс для добавления задач, управления пулом.
 * - Синхронизация — мьютексы, условные переменные для координации.
 *
 */

class ThreadPool
{
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex mtx;
    std::condition_variable cv;
    bool stop = false;

public:
    ThreadPool(size_t num_threads = std::thread::hardware_concurrency());
    ~ThreadPool();

    // Добавление задачи с возвратом результата
    template<typename Func, typename... Args>
    auto enqueue(Func&& func, Args&&... args) -> std::future<decltype(func(args...))>
    {
        using ReturnType = decltype(func(args...));

        // Создаём std::packaged_task для получения future
        auto task = std::make_shared<std::packaged_task<ReturnType()>>(
            std::bind(std::forward<Func>(func), std::forward<Args>(args)...)
            );

        std::future<ReturnType> result = task->get_future();

        {
            std::lock_guard<std::mutex> lock(mtx);

            // Нельзя добавлять задачи после остановки
            if (stop)
            {
                throw std::runtime_error("enqueue on stopped ThreadPool");
            }

            // Добавляем задачу в очередь
            tasks.emplace([task]() {
                (*task)();
            });
        }

        // Будим один ожидающий поток
        cv.notify_one();

        return result;
    }
};
