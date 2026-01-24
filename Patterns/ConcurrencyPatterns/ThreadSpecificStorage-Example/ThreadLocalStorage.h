#pragma once

#include <mutex>
#include <thread>
#include <unordered_map>

/*
 * Шаблон для хранения данных по id потока
 */
template<typename T>
class ThreadLocalStorage {
private:
    std::unordered_map<std::thread::id, std::unique_ptr<T>> storage;
    mutable std::mutex mtx;

public:
    T& get() {
        auto tid = std::this_thread::get_id();

        {
            std::lock_guard<std::mutex> lock(mtx);
            auto it = storage.find(tid);
            if (it != storage.end()) {
                return *(it->second);
            }
        }

        // Создаем новый объект для потока
        auto new_obj = std::make_unique<T>();
        T* ptr = new_obj.get();

        {
            std::lock_guard<std::mutex> lock(mtx);
            storage[tid] = std::move(new_obj);
        }

        return *ptr;
    }

    void remove() {
        auto tid = std::this_thread::get_id();
        std::lock_guard<std::mutex> lock(mtx);
        storage.erase(tid);
    }

    size_t size() const {
        std::lock_guard<std::mutex> lock(mtx);
        return storage.size();
    }
};
