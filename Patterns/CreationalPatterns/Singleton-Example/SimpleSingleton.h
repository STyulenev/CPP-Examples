#pragma once

#define IS_POINTER true // false

/*
 * Класс-одиночка, который гарантирует единственный экземпляр в течении работы программы. Приведены примеры для ссылки и указателя.
 * Экземпляр создаётся при запуске если IS_POINTER == false, иначе при первом обращении.
 */
class SimpleSingleton
{
private:
#if IS_POINTER
    static SimpleSingleton* self;
#else
    static SimpleSingleton self;
#endif

    /*
     * Конструкторы и деструктор приватные, чтобы обеспечить создание не более одного экземпляра.
     */
    SimpleSingleton();
    ~SimpleSingleton();

    SimpleSingleton(const SimpleSingleton&) = delete;
    SimpleSingleton(SimpleSingleton&&) = delete;
    SimpleSingleton& operator=(const SimpleSingleton&) = delete;
    SimpleSingleton& operator=(SimpleSingleton&&) = delete;

public:
    /*
     * Статический метод для получения и создания (если nullptr) экземпляра класса
     */
#if IS_POINTER
    static SimpleSingleton* instance();
#else
    static SimpleSingleton& instance();
#endif
    /*
     * Статический метод пересоздания экземпляра класса
     */
#if IS_POINTER
    static void recreation();
#endif

    int getSomeData();
    void setSomeData(const int data);

private:
    int m_someData;

};
