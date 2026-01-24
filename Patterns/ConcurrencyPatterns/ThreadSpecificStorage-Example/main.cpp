#include <iostream>
#include <vector>

#include "ThreadLocalStorage.h"

/*
 * Thread-Specific Storage (TSS) — паттерн в C++, который позволяет многопоточным приложениям использовать локальные данные через
 * глобальную точку доступа. Это позволяет функциям, выполняющимся в одном потоке, делиться данными, не мешая данным, которые используются
 * теми же функциями в других потоках.
 *
 * TSS позволяет:
 * - Эффективно получать данные, специфичные для потока, без необходимости синхронизировать доступ каждый раз.
 * - Упрощать программирование — разработчики могут использовать абстракцию данных или макросы, чтобы использовать TSS прозрачно
 * на уровне исходного кода.
 * - Делать приложения портативными — TSS доступен на большинстве многопоточных платформ ОС и может быть реализован на платформах,
 * где его нет.
 *
 * В паттерне TSS данные, специфичные для потока, хранятся в локальном хранилище. Каждый поток имеет свою копию этих данных.
 * Для доступа к данным используется глобальная точка доступа — например, ключ, который уникально идентифицирует хранилище.
 *
 */

// Класс для данных, которые нужно хранить в TSS
class ThreadContext
{
public:
    int thread_id;
    int counter = 0;
    std::string name;

    void increment() { ++counter; }
};

int main()
{
    ThreadLocalStorage<ThreadContext> tls;

    auto worker = [&tls](int id) {
        auto& context = tls.get();
        context.thread_id = id;
        context.name = "Worker_" + std::to_string(id);

        for (int i = 0; i < 5; ++i)
        {
            context.increment();
            std::cout << context.name << ": counter = " << context.counter << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    };

    std::vector<std::thread> threads;

    for (int i = 0; i < 3; ++i)
    {
        threads.emplace_back(worker, i + 1);
    }

    for (auto& t : threads)
    {
        t.join();
    }

    return 0;
}
