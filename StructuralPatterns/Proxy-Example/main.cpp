#include <iostream>

#include "Proxy.h"
#include "RealSubject.h"

void clientCode(const AbstractSubject &subject)
{
    // ...
    subject.someAction();
    // ...
}

int main()
{
    std::cout << "Client code with real object: ";
    RealSubject *real_subject = new RealSubject;
    clientCode(*real_subject);
    std::cout << "\n";

    std::cout << "Client code with real proxy: ";
    Proxy *proxy = new Proxy(real_subject);
    clientCode(*proxy);
    std::cout << "\n";

    delete real_subject;
    delete proxy;
    return 0;
}
