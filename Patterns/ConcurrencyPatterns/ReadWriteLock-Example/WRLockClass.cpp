#include "WRLockClass.h"

#include <iostream>
#include <thread>

void ReadWriteLock::lock_read()
{
    mutex_.lock_shared();
}

void ReadWriteLock::unlock_read()
{
    mutex_.unlock_shared();
}

void ReadWriteLock::lock_write()
{
    mutex_.lock();
}

void ReadWriteLock::unlock_write()
{
    mutex_.unlock();
}

void WRLockClass::reader(int reader_id)
{
    for (int i = 0; i < 5; ++i)
    {
        rwLock.lock_read();
        std::cout << "Reader " << reader_id << " reads shared_data = " << shared_data << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        rwLock.unlock_read();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void WRLockClass::writer(int writer_id)
{
    for (int i = 0; i < 5; ++i)
    {
        rwLock.lock_write();
        ++shared_data;
        std::cout << "Writer " << writer_id << " updates shared_data to " << shared_data << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        rwLock.unlock_write();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int WRLockClass::getData()
{
    rwLock.lock_read();
    const int temp = shared_data;
    rwLock.unlock_read();

    return temp;
}
