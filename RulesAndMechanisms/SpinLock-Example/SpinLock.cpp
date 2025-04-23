#include "SpinLock.h"

#include <thread>

void SimpleSpinLock::lock()
{
    while (lock_.exchange(true));
}

void SimpleSpinLock::unlock()
{
    lock_.store(false);
}

SpinLock::SpinLock()
{

}

SpinLock::~SpinLock()
{

}

void SpinLock::lock()
{
    retries = 0;

    while (flag.test_and_set(std::memory_order_acquire)) {
        // spin until the lock is released
        backoff();
        retries++;
    }
}

void SpinLock::unlock()
{
    flag.clear(std::memory_order_release);
}

void SpinLock::backoff()
{
    const int max_retries = 8;

    if (retries < max_retries) {
        std::this_thread::yield();
    } else {
        auto delay = std::chrono::microseconds(1 << (retries - max_retries));
        std::this_thread::sleep_for(delay);
    }
}
