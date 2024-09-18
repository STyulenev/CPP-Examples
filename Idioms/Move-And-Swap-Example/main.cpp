#include <iostream>

#include "SomeClass.h"

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
