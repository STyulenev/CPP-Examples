#include <iostream>

#include "ActiveObject.h"

/*
 *
 * Паттерн проектирования «активный объект» отделяет выполнение методов от вызова методов для объектов, каждый из которых находится
 * в собственном потоке управления. Цель состоит в том, чтобы обеспечить параллелизм, используя асинхронный вызов методов и
 * планировщик для обработки запросов.
 *
 * Преимущества паттерна Active Object:
 * - Инкапсуляция многопоточности — клиенты не знают о внутренней реализации
 * - Thread safety — все вызовы автоматически синхронизированы
 * - Асинхронность — не блокирует вызывающий поток
 * - Очередь задач — гарантирует порядок выполнения
 * - Масштабируемость — можно легко добавить пул потоков
 *
 * Типичные use cases:
 * - GUI приложения (чтобы не блокировать UI поток)
 * - Сетевое программирование
 * - Обработка событий
 * - Вычислительные задачи с долгими операциями
 *
 */

int main()
{
    {
        ActiveObject obj;

        // Асинхронное выполнение
        auto future1 = obj.execute([]() {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return 42;
        });

        auto future2 = obj.execute([](int a, int b) {
            return a + b;
        }, 10, 20);

        std::cout << "Result 1: " << future1.get() << std::endl;
        std::cout << "Result 2: " << future2.get() << std::endl;
    }

    std::cout << "\n\n\n";

    {
        PriorityActiveObject active_obj;

        // Отправляем задачи с разными приоритетами
        auto low_task = active_obj.send(Priority::LOW, []() {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << "Low priority task completed" << std::endl;
            return 1;
        });

        auto normal_task = active_obj.send(Priority::NORMAL, []() {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            std::cout << "Normal priority task completed" << std::endl;
            return 2;
        });

        auto high_task = active_obj.send(Priority::HIGH, []() {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            std::cout << "High priority task completed" << std::endl;
            return 3;
        });

        // Ждем завершения
        std::cout << "High task result: " << high_task.get() << std::endl;
        std::cout << "Normal task result: " << normal_task.get() << std::endl;
        std::cout << "Low task result: " << low_task.get() << std::endl;
    }

    return 0;
}
