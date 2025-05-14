#pragma once

#include <thread>
#include <iostream>

namespace Example2 {

volatile bool ready = false;

void worker() {
    // Выполнение некоторых операций
    ready = true; // Изменение переменной
}

void test1()
{
    std::thread t(worker);

    while (!ready) {
        std::cout << "waiting..."<< std::endl; // Ожидание, пока worker не установит ready в true
    }

    std::cout << "Worker is ready!" << std::endl;
    t.join();
}

} // namespace Example2
