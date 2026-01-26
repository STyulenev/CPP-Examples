#include <iostream>

#include "Schedulers.h"

/*
 * Паттерн Scheduling (Планирование) в C++ является видоизменённым паттерном "Thread pool" для организации управления задачами,
 * очередями задач и их выполнением по расписанию или при определённых условиях.
 *
 * Планирование и организация может включать:
 * - Выставление приоритета для изменения последовательности выполнения задач
 * - Отсрочка выполнения
 * - Распределение задач по разным потокам
 *
 */
int main()
{
    /*{ // Простой пул потоков
        ThreadPoolScheduler scheduler(4);
        std::vector<std::future<int>> results;

        // Запускаем задачи
        for (int i = 0; i < 10; ++i)
        {
            results.emplace_back(scheduler.schedule([i]() {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                std::cout << "Task " << i << " executed by thread " << std::this_thread::get_id() << std::endl;
                return i * i;
            }));
        }

        // Ждем завершения всех задач
        scheduler.waitAll();

        // Получаем результаты
        for (auto& result : results)
        {
            std::cout << "Result: " << result.get() << std::endl;
        }
    }*/

    { // Пул потоков с добавлением приоритета и отсрочки выполнения
        PriorityScheduler scheduler;

        // Даем время на инициализацию
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        // Добавляем задачи в обратном порядке приоритетов

        scheduler.schedule(1, []() {
            std::cout << "[P1] Low Priority - Task 1\n";
        });

        scheduler.schedule(5, []() {
            std::cout << "[P5] Medium priority - task 2\n";
        });

        scheduler.schedule(10, []() {
            std::cout << "[P10] High Priority - Task 3\n";
        });

        // Отложенная задача
        std::cout << "\n4. Priority 7, delayed by 1 second\n";
        scheduler.scheduleAfter(7, std::chrono::seconds(1), []() {
            std::cout << "[P7] Delayed task (in 1 sec)\n";
        });

        // Ждем выполнения задач
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}
