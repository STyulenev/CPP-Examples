#pragma once

#include <shared_mutex>

/*
 * Класс для блокировки чтения/записи
 */
class ReadWriteLock
{
public:
    void lock_read();
    void unlock_read();
    void lock_write();
    void unlock_write();

private:
    std::shared_mutex mutex_;
};

/*
 * Интерфейс для Read-Write Lock обёртки c ресурсом
 */
class IWRLockClass
{
public:
    virtual void reader(int reader_id) = 0;
    virtual void writer(int writer_id) = 0;
};

/*
 * Класс-обёртка, который объединяет блокировщик чтения/записи и ресурс для удобного использования
 */
class WRLockClass : public IWRLockClass
{
public:
    void reader(int reader_id) override;
    void writer(int writer_id) override;

    int getData();

private:
    ReadWriteLock rwLock; // Read-Write блокировщик
    int shared_data = 0;  // Общий ресурс для тестирования

};
