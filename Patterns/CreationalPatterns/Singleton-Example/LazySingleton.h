#pragma once

/*
 * Ленивый класс-одиночка. экземпляр создаётся только при первом обращении.
 */
class LazySingleton
{
private:
    /*
     * Конструкторы и деструктор приватные, чтобы обеспечить создание не более одного экземпляра.
     */
    LazySingleton();
    ~LazySingleton();

    LazySingleton(const LazySingleton &) = delete;
    LazySingleton(LazySingleton &&) = delete;
    LazySingleton &operator=(const LazySingleton &) = delete;
    LazySingleton &operator=(LazySingleton &&) = delete;

public:
    /*
     * Статический метод для получения и создания (если nullptr) экземпляра класса
     */
    static LazySingleton& instance();

    int getSomeData();
    void setSomeData(const int data);

private:
    int m_someData;

};
