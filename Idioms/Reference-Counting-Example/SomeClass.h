#pragma once

class SomeClassReferenceCount;

/*
 * Класс со счётчиком ссылок. Счётчик увеличивается на единицу при использовании
 * конструктора копирования и обнуляется в деструкторе.
 */
class SomeClass
{
public:
    SomeClass();
    SomeClass(const SomeClass& someClass);
    SomeClass(const char* someClass);
    SomeClass &operator=(const SomeClass& someClass);
    ~SomeClass();

private:
    void swap(SomeClass& someClass) throw();

    SomeClassReferenceCount* reference;

};
