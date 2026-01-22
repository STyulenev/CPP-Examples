#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>

class ProducerConsumer
{
private:
    std::queue<int> data_queue;
    std::mutex mtx;
    std::condition_variable cv;
    std::atomic<bool> done{false};
    const size_t max_size = 10;

public:
    void producer(int id);
    void consumer(int id);
    void setDone();

};
