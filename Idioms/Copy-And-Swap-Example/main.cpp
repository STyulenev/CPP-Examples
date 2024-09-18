#include <iostream>

#include "SomeClass.h"

int main()
{
    SomeClass someClass{"text1"};
    SomeClass copySomeClass{"text2"};
    someClass = copySomeClass; // присваивание с копированием

    std::cout << "Text " << copySomeClass.getId() << ": " << copySomeClass.getText() << std::endl; // error
    std::cout << "Text " << someClass.getId() << ": " << someClass.getText() << std::endl;

    return 0;
}
