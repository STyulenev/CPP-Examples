#pragma once

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>
#include <memory>
#include <chrono>

/*
 * Простая реализация паттерна Scheduling через классический пул потоков с общей очередью задач (ThreadPool)
 */
class ThreadPoolScheduler
{
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queue_mutex;
    std::condition_variable condition;
    std::condition_variable finished_condition;

    bool stop;
    size_t active_tasks;

public:
    ThreadPoolScheduler(size_t num_threads = std::thread::hardware_concurrency());
    ~ThreadPoolScheduler();

    template<class F, class... Args>
    auto schedule(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>
    {
        using return_type = typename std::result_of<F(Args...)>::type;

        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
            );

        std::future<return_type> res = task->get_future();

        {
            std::unique_lock<std::mutex> lock(queue_mutex);

            if (stop)
                throw std::runtime_error("schedule on stopped ThreadPool");

            tasks.emplace([task]() { (*task)(); });
        }

        condition.notify_one();
        return res;
    }

    void waitAll();

};

/*
 * Реализация паттерна Scheduling через пул потоков с приоритетом
 */
class PriorityScheduler
{
private:
    struct TaskItem
    {
        std::function<void()> task;
        int priority;
        std::chrono::steady_clock::time_point scheduled_time;

        bool operator<(const TaskItem& other) const;
    };

    std::thread worker;
    std::priority_queue<TaskItem> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;

public:
    PriorityScheduler();
    ~PriorityScheduler();

    void run();

    template<class F, class... Args>
    void schedule(int priority, F&& f, Args&&... args)
    {
        scheduleAfter(priority, std::chrono::seconds(0), std::forward<F>(f), std::forward<Args>(args)...);
    }

    template<class F, class... Args>
    void scheduleAfter(int priority, std::chrono::steady_clock::duration delay, F&& f, Args&&... args)
    {
        auto task = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
        auto scheduled_time = std::chrono::steady_clock::now() + delay;

        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            tasks.push({task, priority, scheduled_time});
        }

        condition.notify_one();
    }

};
