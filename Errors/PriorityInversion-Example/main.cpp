#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>

/*
 * Priority inversion (инверсия приоритетов) — это ситуация в многопоточной системе, когда поток с высоким приоритетом вынужден
 * ждать выполнения другого потока с низким приоритетом, потому что тот держит ресурс, необходимый высокоприоритетному потоку.
 * Это может привести к ухудшению производительности и задержкам в системе.
 *
 * Что происходит при инверсии приоритетов?
 * - Поток с низким приоритетом захватывает ресурс (например, мютекс).
 * - Поток с высоким приоритетом пытается получить тот же ресурс и блокируется.
 * - Пока низкоприоритетный поток не освободит ресурс, поток с высоким приоритетом вынужден ждать.
 * - В результате, приоритеты "инвертируются": низкоприоритетный поток мешает выполнению высокоприоритетного.
 */

// Общий ресурс
std::mutex resource_mutex;

// Имитация приоритетов (низкий, высокий)
std::atomic<bool> high_priority_waiting(false);
std::atomic<int>  low_priority_task_running(0);

void low_priority_task()
{
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "[Low priority] Start\n";

        // Захватываем ресурс
        std::lock_guard<std::mutex> lock(resource_mutex);
        low_priority_task_running.store(1);
        std::cout << "[Low priority] Lock resource\n";

        // Держим ресурс некоторое время
        std::this_thread::sleep_for(std::chrono::seconds(5));

        std::cout << "[Low priority] Unlock resource\n";
        low_priority_task_running.store(0);
    }
}

void high_priority_task()
{
    for (int i = 0; i < 10; ++i)
    {
        // Имитация ожидания ресурса
        std::this_thread::sleep_for(std::chrono::seconds(1));
        high_priority_waiting.store(true);
        std::cout << "[High priority] Waiting resource\n";

        // В случае инверсии приоритетов, поток с низким приоритетом задержит высокий поток
        // В реальности ОС и планировщик управляют приоритетами, тут — логика
        resource_mutex.lock();
        std::cout << "[High priority] Lock resource\n";

        resource_mutex.unlock();
        high_priority_waiting.store(false);
        std::cout << "[High priority] Unlock resource\n";
    }
}

int main()
{
    std::thread low_thread(low_priority_task);
    std::thread high_thread(high_priority_task);

    low_thread.join();
    high_thread.join();

    return 0;
}
