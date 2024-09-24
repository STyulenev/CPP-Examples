#pragma once

#include <mutex>

/*
 * Безопасный класс-одиночка. Отличается от обычного наличием мьютекса для работы в многопоточной среде.
 */
class SafeSingleton
{
private:
    static SafeSingleton* self;
    static std::mutex mutex;

    /*
     * Конструкторы и деструктор привытные, чтобы обеспечить создание не более одного экземпляра.
     */
    SafeSingleton();
    ~SafeSingleton();

    SafeSingleton(const SafeSingleton&) = delete;
    SafeSingleton(SafeSingleton&&) = delete;
    SafeSingleton& operator=(const SafeSingleton&) = delete;
    SafeSingleton& operator=(SafeSingleton&&) = delete;

public:
    /*
     * Статический метод для получения и создания (если nullptr) экземпляра класса
     */
    static SafeSingleton* instance();

    /*
     * Статический метод пересоздания экземпляра класса
     */
    static void recreation();

    int getSomeData();
    void setSomeData(const int data);

private:
    int m_someData;

};
