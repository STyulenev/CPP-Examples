#include "SomeClass.h"

/*
 * Реализация может быть как в отдельном private файле PimplClass.h, так и
 * внутренний класс здесь. Можно использовать в интерфейсах или абстрактных
 * классах, чтобы не подключать заголовочный файл.
 */
#include "PimplClass.h"

#include <iostream>

SomeClass::SomeClass() :
    m_pimplClass(new PimplNamespase::PimplClass("data")),
    m_anotherClass(new AnotherClass())
{
    // ...
}

SomeClass::~SomeClass()
{
    delete m_pimplClass;
    delete m_anotherClass;
}

void SomeClass::print()
{
    std::cout << "SomeClass::print(): " << m_pimplClass->getData() << std::endl;
    m_anotherClass->print();
}

AnotherClass::AnotherClass()
{
    // ...
}

AnotherClass::~AnotherClass()
{
    // ...
}

void AnotherClass::print()
{
    std::cout << "AnotherClass::print()" << std::endl;
}
