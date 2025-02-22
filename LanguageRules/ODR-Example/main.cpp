#include <iostream>

#include "Logic.h"
#include "SomeClass.h"

/*
 * Правило одного определения (ODR - One Definition Rule) — важное правило языка программирования C++ , которое предписывает, что классы/структуры и невстроенные функции
 * не могут иметь более одного определения во всей программе и шаблоне, а типы не могут иметь более одного определения по единице трансляции.
 *
 * - В любой единице перевода шаблон, тип, функция или объект могут иметь не более одного определения. Некоторые из них могут иметь любое количество объявлений.
 * Определение предоставляет экземпляр.
 * - Во всей программе объект или невстроенная функция не могут иметь более одного определения; если объект или функция используются, они должны иметь ровно одно определение.
 * Вы можете объявить объект или функцию, которые никогда не используются, в этом случае вам не нужно предоставлять определение. Ни в коем случае не может быть более одного определения.
 * - Некоторые вещи, такие как типы, шаблоны и внешние встроенные функции, могут быть определены в более чем одной единице перевода. Для данной сущности каждое определение
 * должно иметь одинаковую последовательность токенов. Невнешние объекты и функции в разных единицах перевода являются разными сущностями, даже если их имена и типы одинаковы.
 */

int main()
{
    {
        someFunction(); // из Logic.h
    }

    {
        SomeClass someClass;
        someClass.someFunction(); // из SomeClass.h
    }

    {
        std::cout << "DATA = " << DATA << std::endl; // из Logic.h
    }

    return 0;
}
