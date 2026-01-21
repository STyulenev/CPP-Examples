#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <future>

/*
 *
 * Реализация активного объекта с очередью без приоритета
 *
 */

class ActiveObject
{
private:
    std::thread worker;
    std::queue<std::function<void()>> tasks;
    std::mutex mtx;
    std::condition_variable cv;
    bool stop = false;

public:
    ActiveObject();
    ~ActiveObject();

    template<typename Func, typename... Args>
    auto execute(Func&& func, Args&&... args) -> std::future<decltype(func(args...))> {
        using ReturnType = decltype(func(args...));

        auto task = std::make_shared<std::packaged_task<ReturnType()>>(
            std::bind(std::forward<Func>(func), std::forward<Args>(args)...)
            );

        std::future<ReturnType> result = task->get_future();

        {
            std::lock_guard<std::mutex> lock(mtx);
            tasks.emplace([task]() { (*task)(); });
        }

        cv.notify_one();
        return result;
    }

private:
    void run();

};

/*
 *
 * Реализация активного объекта как очереди с приоритетами выполнения поставленных задач
 *
 */

enum class Priority {
    LOW,
    NORMAL,
    HIGH,
    CRITICAL
};

class PriorityActiveObject {
private:
    struct PriorityTask {
        std::function<void()> task;
        Priority priority;
        uint64_t sequence;

        bool operator<(const PriorityTask& other) const {
            if (priority != other.priority) {
                return static_cast<int>(priority) < static_cast<int>(other.priority);
            }
            return sequence > other.sequence;  // FIFO для одинакового приоритета
        }
    };

    std::thread worker;
    std::priority_queue<PriorityTask> tasks;
    mutable std::mutex mtx;
    std::condition_variable cv;
    bool stop = false;
    uint64_t sequence_counter = 0;

public:
    PriorityActiveObject();
    ~PriorityActiveObject();

    template<typename Func, typename... Args>
    auto send(Priority priority, Func&& func, Args&&... args)
        -> std::future<decltype(func(args...))> {

        using ReturnType = decltype(func(args...));

        auto task = std::make_shared<std::packaged_task<ReturnType()>>(
            std::bind(std::forward<Func>(func), std::forward<Args>(args)...)
            );

        std::future<ReturnType> result = task->get_future();

        {
            std::lock_guard<std::mutex> lock(mtx);
            tasks.push({
                [task]() { (*task)(); },
                priority,
                ++sequence_counter
            });
        }

        cv.notify_one();
        return result;
    }

    size_t pending_tasks() const;

private:
    void run();

};
