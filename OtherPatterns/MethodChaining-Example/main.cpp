#include "SomeClass.h"

int main()
{
    { // С цепочкой методов
        SomeClass someClass;
        someClass.setFirstField(0.1).setSecondField(12).setThirdField("some text").setFirstField(0.2);

        someClass << "." << "." << ".";

        std::cout << someClass << std::endl;
    }

    { // Без цепочки методов
        SomeClass someClass;
        someClass.setFirstField(0.1);
        someClass.setSecondField(12);
        someClass.setThirdField("some text");
        someClass.setFirstField(0.2);
        someClass.setThirdField("some text...");

        std::cout << someClass << std::endl;
    }

    return 0;
}
