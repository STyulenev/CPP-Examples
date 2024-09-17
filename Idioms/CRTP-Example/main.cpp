#include "ConcreteClass.h"

int main()
{
    AbstractBase<ConcreteClass1>* c1 = new ConcreteClass1();
    AbstractBase<ConcreteClass2>* c2 = new ConcreteClass2();
    AbstractBase<ConcreteClass2>* c3 = new ConcreteClass2();

    c1->interface();
    c2->interface();
    c3->interface();

    delete c1;
    delete c2;
    delete c3;

    return 0;
}
