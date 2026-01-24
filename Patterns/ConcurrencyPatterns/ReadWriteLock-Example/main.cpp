#include "WRLockClass.h"

#include <iostream>
#include <functional>
#include <thread>
#include <vector>

/*
 * Read-Write Lock (паттерн «читатель-запись») в C++ — это механизм синхронизации, который позволяет нескольким потокам читать
 * общий ресурс одновременно, но только один поток может записывать в него в любое время.
 * Этот паттерн полезен в сценариях, где операции чтения встречаются часто, а записи — редко, — он оптимизирует производительность
 * без ущерба для целостности данных. Например, в базах данных, системах кэширования.
 *
 * Принцип работы:
 * - В C++ для реализации паттерна Read-Write Lock используются, например, классы std::shared_mutex и std::unique_lock:
 * - std::shared_mutex позволяет нескольким читателям или одному писателю получать доступ к ресурсу.
 * - std::unique_lock обеспечивает эксклюзивный доступ для записи.
 *
 * В реальных приложениях часто сочетаются операции чтения и записи на общих ресурсах — в этом случае std::shared_mutex позволяет
 * комбинировать std::shared_lock для операций чтения и std::unique_lock для операций записи.
 *
 */

int main()
{
    WRLockClass rw_lock;

    std::vector<std::thread> threads;

    // Создаем несколько потоков читателей
    for (int i = 0; i < 3; ++i)
    {
        threads.emplace_back(std::bind(&WRLockClass::reader, &rw_lock, i + 1));
    }

    // Создаем несколько потоков писателей
    for (int i = 0; i < 2; ++i)
    {
        threads.emplace_back(std::bind(&WRLockClass::writer, &rw_lock, i + 1));
    }

    // Ждём завершения всех потоков
    for (auto& t : threads)
    {
        t.join();
    }

    std::cout << "Final shared_data = " << rw_lock.getData() << std::endl;

    return 0;
}
