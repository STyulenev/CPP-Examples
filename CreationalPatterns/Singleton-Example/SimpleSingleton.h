#pragma once

/*
 * Класс-одиночка, который гарантирует единственный экземпляр в течении работы программы.
 */
class SimpleSingleton
{
private:
    static SimpleSingleton* self;

    /*
     * Конструкторы и деструктор привытные, чтобы обеспечить создание не более одного экземпляра.
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
    static SimpleSingleton* instance();

    /*
     * Статический метод пересоздания экземпляра класса
     */
    static void recreation();

    int getSomeData();
    void setSomeData(const int data);

private:
    int m_someData;

};
