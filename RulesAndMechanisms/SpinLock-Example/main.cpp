#include <iostream>
#include <thread>

#include "SpinLock.h"

/*
 * Spinlock в C++ — это эффективная альтернатива традиционным методам/механизмам синхронизации, таким как мьютексы и семафоры.
 * В частности, он более эффективен, если блокировка нужна потоку на короткий промежуток времени. Например, если потоку
 * нужно внести незначительные изменения в глобальную структуру или изменить состояние программы в синхронизированном режиме.
 */

SpinLock lock1;
SimpleSpinLock lock2;

void increment_counter1(int& counter, int operations)
{
    for (int i = 0; i < operations; i++) {
        lock1.lock();
        counter++;
        lock1.unlock();
    }
}

void increment_counter2(int& counter, int operations)
{
    for (int i = 0; i < operations; i++) {
        lock2.lock();
        counter++;
        lock2.unlock();
    }
}

/*
 * Тест SpinLock
 */
void test1()
{
    const int numThreads = 10;
    const int opsPerThread = 100;

    int counter = 0;

    std::thread threads[numThreads];

    for (int i = 0; i < numThreads; i++) {
        threads[i] = std::thread(increment_counter1, std::ref(counter), opsPerThread);
    }

    for (int i = 0; i < numThreads; i++) {
        threads[i].join();
    }

    std::cout << "Counter value: " << counter << std::endl;

    if (counter != numThreads * opsPerThread) {
        std::cerr << "Error. Counter value is false." << std::endl;
        return;
    }

    std::cout << "Counter value is true." << std::endl;
}

/*
 * Тест SimpleSpinLock
 */
void test2()
{
    const int numThreads = 10;
    const int opsPerThread = 100;

    int counter = 0;

    std::thread threads[numThreads];

    for (int i = 0; i < numThreads; i++) {
        threads[i] = std::thread(increment_counter2, std::ref(counter), opsPerThread);
    }

    for (int i = 0; i < numThreads; i++) {
        threads[i].join();
    }

    std::cout << "Counter value: " << counter << std::endl;

    if (counter != numThreads * opsPerThread) {
        std::cerr << "Error. Counter value is false." << std::endl;
        return;
    }

    std::cout << "Counter value is true." << std::endl;
}

int main()
{
    // test1();
    test2();

    return 0;
}
