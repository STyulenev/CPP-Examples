#include "ComplexCommand.h"
#include "SimpleCommand.h"

#include "Invoker.h"
#include "Receiver.h"

int main()
{
    { // client code
        Invoker* invoker = new Invoker();
        invoker->setOnStart(new SimpleCommand("Say Hi!"));

        Receiver* receiver = new Receiver();
        invoker->setOnFinish(new ComplexCommand(receiver, "Send email", "Save report"));

        invoker->someAction();

        delete invoker;
        delete receiver;
    }

    return 0;
}
