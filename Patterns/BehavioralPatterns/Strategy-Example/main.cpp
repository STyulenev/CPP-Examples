#include <iostream>

#include "ConcreteStrategyA.h"
#include "ConcreteStrategyB.h"
#include "Context.h"

int main()
{
    { // client code
        Context* context = new Context(new ConcreteStrategyA());

        std::cout << "Client: Strategy is set to normal sorting." << std::endl;
        context->someBusinessLogic();

        std::cout << "Client: Strategy is set to reverse sorting." << std::endl;
        context->setStrategy(new ConcreteStrategyB());
        context->someBusinessLogic();

        delete context;
    }

    return 0;
}
