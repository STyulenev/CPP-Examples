#include "SomeClass.h"

#include <iostream>
#include <thread>

void SomeClass::safePrint(const std::string &msg)
{
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << msg << std::endl;
}

void SomeClass::task1()
{
    while (!stop_simulation)
    {
        task1_wants_to_run = true;
        safePrint("Task 1: I need work");

        // Вежливо ждем, если если task 2 нужно работать
        while (task2_wants_to_run)
        {
            safePrint("Task 1: If task 2 needs work, then I skip it");
            task1_wants_to_run = false;

            // Имитация вежливого ожидания
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            task1_wants_to_run = true;
            safePrint("Task 1: I need work again ...");
        }

        // Выполняем задачу
        safePrint("Task 1: I'm working...");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        task1_wants_to_run = false;
        safePrint("Task 1: I have finished work");

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void SomeClass::task2()
{
    while (!stop_simulation)
    {
        task2_wants_to_run = true;
        safePrint("Task 2: I need work");

        // Вежливо ждем, если если task 1 нужно работать
        while (task1_wants_to_run)
        {
            safePrint("Task 2: If task 1 needs work, then I skip it");
            task2_wants_to_run = false;

            // Имитация вежливого ожидания
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            task2_wants_to_run = true;
            safePrint("Task 2: I need work again ...");
        }

        // Выполняем задачу
        safePrint("Task 1: I'm working...");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        task2_wants_to_run = false;
        safePrint("Task 1: I have finished work");

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void SomeClass::runSimulation(int duration_seconds)
{
    std::thread t1(&SomeClass::task1, this);
    std::thread t2(&SomeClass::task2, this);

    std::this_thread::sleep_for(std::chrono::seconds(duration_seconds));
    stop_simulation = true;

    t1.join();
    t2.join();
}
