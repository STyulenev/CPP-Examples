#pragma once

#include <iostream>
#include <cstdlib>
#include <new>

/*
 *
 * Пример перегрузки операторов работы с памятью:
 * - new
 * - new[]
 * - delete
 * - delete[]
 */

namespace Example4 {

// Простой пример, без алокаторов, выравнивания и т.д.
class SomeClass
{
private:
    static std::size_t total_allocated;
    static std::size_t total_freed;

public:
    SomeClass() { std::cout << "Constructor" << std::endl; }
    ~SomeClass() { std::cout << "Destructor" << std::endl; }

    // Перегрузка операторов new для класса
    static void* operator new(std::size_t size)
    {
        std::cout << "Class new: allocating " << size << " bytes" << std::endl;
        total_allocated += size;

        void* ptr = std::malloc(size);
        if (!ptr) {
            throw std::bad_alloc();
        }
        return ptr;
    }

    static void operator delete(void* ptr) noexcept
    {
        std::cout << "Class delete: freeing memory" << std::endl;
        total_freed += sizeof(SomeClass);
        std::free(ptr);
    }

    // Перегрузка операторов new[] и delete[] для класса
    static void* operator new[](std::size_t size)
    {
        std::cout << "Class new[]: allocating array of " << size << " bytes" << std::endl;
        total_allocated += size;

        void* ptr = std::malloc(size);
        if (!ptr) {
            throw std::bad_alloc();
        }
        return ptr;
    }

    static void operator delete[](void* ptr) noexcept
    {
        std::cout << "Class delete[]: freeing array memory" << std::endl;
        total_freed += sizeof(SomeClass); // Упрощенно
        std::free(ptr);
    }

    // Версии с nothrow
    static void* operator new(std::size_t size, const std::nothrow_t&) noexcept
    {
        std::cout << "Class new (nothrow): allocating " << size << " bytes" << std::endl;
        return std::malloc(size);
    }

    static void* operator new[](std::size_t size, const std::nothrow_t&) noexcept
    {
        std::cout << "Class new[] (nothrow): allocating array of " << size << " bytes" << std::endl;
        return std::malloc(size);
    }

    // Статистика
    static void print_stats()
    {
        std::cout << "Total allocated: " << total_allocated << " bytes" << std::endl;
        std::cout << "Total freed: " << total_freed << " bytes" << std::endl;
        std::cout << "Memory leak: " << (total_allocated - total_freed) << " bytes" << std::endl;
    }
};

// Инициализация статических переменных
std::size_t SomeClass::total_allocated = 0;
std::size_t SomeClass::total_freed = 0;

void test()
{
    // Одиночный объект
    SomeClass* obj = new SomeClass();
    delete obj;

    // Массив объектов
    SomeClass* arr = new SomeClass[3];
    delete[] arr;

    // Nothrow версия
    SomeClass* nothrow_obj = new (std::nothrow) SomeClass();
    delete nothrow_obj;

    SomeClass::print_stats();
}

} // namespace Example4
