#include <iostream>
#include <thread>

#include "LazySingleton.h"
#include "SimpleSingleton.h"
#include "SafeSingleton.h"

/*
 * Порождающий паттерн «одиночка» (Singleton) — это шаблон проектирования, гарантирующий, что у класса будет только один экземпляр.
 * К этому экземпляру предоставляется глобальная, то есть доступная из любой части программы, точка доступа. Если попытаться создать
 * новый объект этого класса, то вернётся уже созданный существующий экземпляр.
 *
 * Виды:
 * - Ленивый (создание экземпляра при первом обращении);
 * - Простой (создание экземпляра при запуске);
 * - Потокобезопасный (для работы с несколькими потоками без коллизий).
 */

void testLazySingleton()
{
    std::cout << "Test LazySingleton" << std::endl;

    std::cout << LazySingleton::instance().getSomeData() << std::endl;
    LazySingleton::instance().setSomeData(5);
    std::cout << LazySingleton::instance().getSomeData() << std::endl << std::endl;
}

void testSimpleSingleton()
{
    std::cout << "Test SimpleSingleton" << std::endl;

#if IS_POINTER
    std::cout << SimpleSingleton::instance()->getSomeData() << std::endl;
    SimpleSingleton::instance()->setSomeData(5);
    std::cout << SimpleSingleton::instance()->getSomeData() << std::endl << std::endl;
#else
    std::cout << SimpleSingleton::instance().getSomeData() << std::endl;
    SimpleSingleton::instance().setSomeData(5);
    std::cout << SimpleSingleton::instance().getSomeData() << std::endl << std::endl;
#endif
}

void testSafeSingleton()
{
    std::cout << "Test SafeSingleton" << std::endl;

    std::thread thread1([]() -> void {
        std::cout << SafeSingleton::instance()->getSomeData() << std::endl;
        SafeSingleton::instance()->setSomeData(5);
        std::cout << SafeSingleton::instance()->getSomeData() << std::endl;
    });
    std::thread thread2([]() -> void {
        std::cout << SafeSingleton::instance()->getSomeData() << std::endl;
        SafeSingleton::instance()->setSomeData(4);
        std::cout << SafeSingleton::instance()->getSomeData() << std::endl;
    });

    thread1.join();
    thread2.join();
}

int main()
{
    testLazySingleton();
    testSimpleSingleton();
    testSafeSingleton();

    return 0;
}
