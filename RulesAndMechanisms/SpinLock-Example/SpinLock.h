#pragma once

#include <atomic>

class ILock
{
public:
    virtual ~ILock() = default;

    virtual void lock() = 0;
    virtual void unlock() = 0;

};

/*
 * Простой SpinLock
 */
class SimpleSpinLock : public ILock
{
private:
    std::atomic<bool> lock_ = {false};

public:
    void lock() override;
    void unlock() override;

};

/*
 * SpinLock с экспоненциальной выдержкой
 */
class SpinLock : public ILock
{
public:
    SpinLock();
    ~SpinLock();

    void lock() override;
    void unlock() override;

private:
    void backoff();

    std::atomic_flag flag = ATOMIC_FLAG_INIT;
    int retries{0};

};
