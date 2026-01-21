#include <iostream>

#include "ThreadPool.h"

/*
 * ThreadPool (пул потоков) — это набор заранее созданных (pre-spawned) потоков, которые ожидают задачи и выполняют их параллельно.
 * Вместо создания и уничтожения потока для каждой задачи (что дорого), мы переиспользуем фиксированное количество потоков.
 *
 * Основные цели:
 * - Снижение накладных расходов на создание/уничтожение потоков.
 * - Контроль над количеством потоков (предотвращение перегрузки системы).
 * - Упрощение управления асинхронными задачами.
 * - Очередь задач для балансировки нагрузки.
 *
 */

int main()
{
    std::vector<std::future<int>> results;

    {
        // Создаём очередь с потоками
        ThreadPool pool(4);

        // Загружаем задачи
        for (int i = 0; i < 8; ++i)
        {
            results.emplace_back(pool.enqueue([i]() {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                std::cout << "Task " << i << " completed in thread " << std::this_thread::get_id() << std::endl;
                return i * i;
            }));
        }

        // В конце блока очередь завершит все потоки и запишет результаты
    }

    std::cout << "\n\n\n";

    for (auto& result : results)
    {
        std::cout << "Result: " << result.get() << std::endl;
    }

    return 0;
}
