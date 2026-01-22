#pragma once

#include <atomic>
#include <mutex>
#include <string>

class SomeClass
{
private:
    std::atomic<bool> task1_wants_to_run{false};
    std::atomic<bool> task2_wants_to_run{false};
    std::atomic<bool> stop_simulation{false};
    std::mutex cout_mutex;

    void safePrint(const std::string& msg);

public:
    // Поток 1: слишком вежливый
    void task1();

    // Поток 2: тоже слишком вежливый
    void task2();

    void runSimulation(int duration_seconds);
};
