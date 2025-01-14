#pragma once

class SomeClass
{
public:
    SomeClass();
    ~SomeClass();

    /*
     * Пример с взаимной блокировкой двух мьютексов
     */
    void run1();

    /*
     * Пример с повторной блокировкой мьютекса
     */
    void run2();

};
