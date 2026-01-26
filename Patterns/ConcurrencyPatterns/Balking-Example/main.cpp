#include <iostream>
#include <random>
#include <thread>

#include "Example.h"

/*
 * Паттерн "отказа от выполнения" (balking pattern) — это шаблон проектирования программного обеспечения, который используется
 * для предотвращения выполнения операции, если объект находится в некорректном состоянии или операция уже выполняется.
 *
 * Ключевые моменты реализации:
 * - Проверка состояния перед выполнением: Методы проверяют состояние объекта перед началом операции.
 * - Неблокирующее поведение: Если объект находится в неподходящем состоянии, операция немедленно прекращается.
 * - Потокобезопасность: Используются мьютексы для защиты разделяемых данных.
 *
 * Типичные случаи использования:
 * - Ленивая инициализация (инициализация только при первом использовании)
 * - Автосохранение (сохранение только при наличии изменений)
 * - Управление задачами (предотвращение повторного запуска уже выполняющейся задачи)
 *
 * Преимущества паттерна Balking:
 * - Предотвращает выполнение операций в некорректном состоянии
 * - Упрощает управление состоянием объекта
 * - Уменьшает конкуренцию в многопоточных приложениях
 *
 * Когда использовать:
 * - Когда операция должна выполняться только при определенных условиях
 * - Когда повторные вызовы операции должны игнорироваться
 * - Для реализации ленивой инициализации
 * - Для реализации механизмов автосохранения
 *
 */

// Функция для имитации работы потоков
void workerThread(int id, BalkingExample& example)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 3);

    for (int i = 0; i < 3; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(dis(gen) * 100));

        // Поток пытается установить данные
        if (example.setData(id * 10 + i)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));

            // Поток пытается начать обработку
            if (example.process()) {
                // Имитация обработки
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                example.finishProcessing();
            }
        }
    }
}

int main()
{
    {
        BalkingExample example;

        // Создаем несколько потоков
        std::thread threads[3];
        for (int i = 0; i < 3; ++i) {
            threads[i] = std::thread(workerThread, i + 1, std::ref(example));
        }

        // Ждём завершения потоков
        for (auto& t : threads) {
            t.join();
        }
    }

    { // Демонстрация ленивой инициализации
        LazyInitializer lazy;

        std::thread t1([&lazy]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            auto* res = lazy.getResource();
            std::cout << "Thread 1 got resource: " << (res ? *res : -1) << std::endl;
        });

        std::thread t2([&lazy]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            auto* res = lazy.getResource();
            std::cout << "Thread 2 got resource: " << (res ? *res : -1) << std::endl;
        });

        t1.join();
        t2.join();
    }

    { // Демонстрация автосохранения
        AutoSaveDocument doc;

        doc.modify("First version");

        // Несколько попыток автосохранения
        for (int i = 0; i < 3; ++i) {
            if (doc.autoSave()) {
                std::cout << "Autosave successful" << std::endl;
            } else {
                std::cout << "Autosave skipped (no changes)" << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        // Изменяем и снова пытаемся сохранить
        doc.modify("Second version");
        doc.autoSave();
    }

    return 0;
}
