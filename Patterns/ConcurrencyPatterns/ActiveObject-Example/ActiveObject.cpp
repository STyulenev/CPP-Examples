#include "ActiveObject.h"

ActiveObject::ActiveObject() : worker(&ActiveObject::run, this)
{
    // ...
}

ActiveObject::~ActiveObject()
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        stop = true;
    }

    cv.notify_one();
    worker.join();
}

void ActiveObject::run()
{
    while (true)
    {
        std::function<void()> task;

        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() {
                return !tasks.empty() || stop;
            });

            if (stop && tasks.empty())
            {
                return;
            }

            task = std::move(tasks.front());
            tasks.pop();
        }

        task();
    }
}

PriorityActiveObject::PriorityActiveObject() : worker(&PriorityActiveObject::run, this)
{
    // ...
}

PriorityActiveObject::~PriorityActiveObject()
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        stop = true;
    }
    cv.notify_one();
    worker.join();
}

size_t PriorityActiveObject::pending_tasks() const
{
    std::lock_guard<std::mutex> lock(mtx);
    return tasks.size();
}

void PriorityActiveObject::run()
{
    while (true)
    {
        PriorityTask task;

        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return !tasks.empty() || stop; });

            if (stop && tasks.empty())
            {
                return;
            }

            task = std::move(tasks.top());
            tasks.pop();
        }

        if (task.task)
        {
            task.task();
        }
    }
}
