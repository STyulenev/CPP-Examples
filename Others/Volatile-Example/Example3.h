#pragma once

#include <signal.h>
#include <iostream>
#include <unistd.h>

namespace Example3 {

volatile sig_atomic_t signalReceived = 0;

void signalHandler(int signal) {
    signalReceived = 1; // Установка флага в обработчике сигнала
}

void test1()
{
    signal(SIGINT, signalHandler); // Регистрация обработчика сигнала

    // Чтобы прервать цикл, необходимо запустить проект в консольном режиме и нажать "Ctrl + C"
    while (!signalReceived) {
        // Ожидание сигнала
        std::cout << "Waiting for signal..." << std::endl;
        sleep(1);
    }

    std::cout << "Signal received!" << std::endl;
}

} // namespace Example3
