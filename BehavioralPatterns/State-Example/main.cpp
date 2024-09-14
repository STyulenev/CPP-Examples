#include "ConcreteStateA.h"
#include "Context.h"

int main()
{
    { // client code
        Context* context = new Context(new ConcreteStateA());

        context->request1();
        context->request2();

        delete context;
    }

    return 0;
}
