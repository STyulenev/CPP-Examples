#include "SomeClass.h"

SomeClass::SomeClass()
{
    // ...
}

SomeClass::~SomeClass()
{
    // ...
}

void SomeClass::launch()
{
    // Некоторые нагруженные операции, возможно в многопоточном режиме...
    // Получение данных...
    // Обработка...

    m_first = 0.11;
    m_second = 12;
    m_third = "Some data";
}
