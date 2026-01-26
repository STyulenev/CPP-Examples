#include "Schedulers.h"

ThreadPoolScheduler::ThreadPoolScheduler(size_t num_threads) :
    stop(false),
    active_tasks(0)
{
    for (size_t i = 0; i < num_threads; ++i)
    {
        workers.emplace_back([this] {
            while(true)
            {
                std::function<void()> task;

                {
                    std::unique_lock<std::mutex> lock(this->queue_mutex);
                    this->condition.wait(lock, [this] {
                        return this->stop || !this->tasks.empty();
                    });

                    if (this->stop && this->tasks.empty())
                        return;

                    task = std::move(this->tasks.front());
                    this->tasks.pop();

                    ++active_tasks;
                }

                task();

                {
                    std::unique_lock<std::mutex> lock(this->queue_mutex);

                    --active_tasks;

                    if (active_tasks == 0 && tasks.empty())
                    {
                        finished_condition.notify_all();
                    }
                }
            }
        });
    }
}

ThreadPoolScheduler::~ThreadPoolScheduler()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }

    condition.notify_all();

    for (std::thread &worker: workers)
    {
        worker.join();
    }
}

void ThreadPoolScheduler::waitAll()
{
    std::unique_lock<std::mutex> lock(queue_mutex);

    finished_condition.wait(lock, [this] {
        return tasks.empty() && active_tasks == 0;
    });
}

bool PriorityScheduler::TaskItem::operator<(const TaskItem &other) const
{
    if (priority != other.priority)
    {
        return priority < other.priority;
    }

    return scheduled_time > other.scheduled_time;
}

PriorityScheduler::PriorityScheduler() :
    stop(false)
{
    worker = std::thread([this] {
        run();
    });
}

PriorityScheduler::~PriorityScheduler()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }

    condition.notify_all();

    if (worker.joinable())
    {
        worker.join();
    }
}

void PriorityScheduler::run()
{
    while (true)
    {
        std::function<void()> task;

        {
            std::unique_lock<std::mutex> lock(queue_mutex);

            if (tasks.empty()) {
                condition.wait(lock, [this] {
                    return stop || !tasks.empty();
                });
            }

            if (stop && tasks.empty())
                return;

            auto now = std::chrono::steady_clock::now();
            auto& next_task = tasks.top();

            if (next_task.scheduled_time <= now)
            {
                task = next_task.task;
                tasks.pop();
            }
            else
            {
                condition.wait_until(lock, next_task.scheduled_time);
                continue;
            }
        }

        if (task)
            task();
    }
}
