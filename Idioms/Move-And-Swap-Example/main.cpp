#include <iostream>

#include "SomeClass.h"

/*
 * Идиома move-and-swap в C++ (перемещение с обменом) применяется в операторах присвоения с перемещением. Она позволяет избежать
 * дублирования кода деструктора и конструктора копирования.
 *
 * Суть идиомы состоит в следующей последовательности действий:
 * - Для перемещаемого объекта создают копию с помощью конструктора перемещения.
 * - Текущий объект заменяют изменённой копией. Если при изменении копии на каком-то этапе возникла ошибка, то текущий объект не заменяется.
 */

int main()
{
    SomeClass someClass{"text1"};
    SomeClass movedSomeClass{"text2"}; // Временный объект для перемещения
    someClass = std::move(movedSomeClass); // присваивание с перемещением
    // someClass = SomeClass{"text2"}; // Вариант 2

    // movedSomeClass уже нельзя использовать
    //std::cout << "Text " << movedSomeClass.getId() << ": " << movedSomeClass.getText() << std::endl; // error
    std::cout << "Text " << someClass.getId() << ": " << someClass.getText() << std::endl;

    return 0;
}
