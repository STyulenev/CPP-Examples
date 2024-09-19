#include "SomeClass.h"

int main()
{
    SomeClass someClass;
    someClass.print();

    // PimplNamespase::PimplClass pimplClass; // Нельзя т.к. видно только forward declaration, без возможности инициализации

    return 0;
}
