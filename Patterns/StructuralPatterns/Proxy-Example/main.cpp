#include <iostream>

#include "Proxy.h"
#include "RealSubject.h"

/*
 * Заместитель — это структурный паттерн проектирования, который позволяет подставлять вместо реальных объектов специальные объекты-заменители.
 * Эти объекты перехватывают вызовы к оригинальному объекту, позволяя сделать что-то до или после передачи вызова оригиналу.
 */

void clientCode(const AbstractSubject& subject)
{
    // ...
    subject.someAction();
    // ...
}

int main()
{
    RealSubject *real_subject = new RealSubject();
    clientCode(*real_subject);

    std::cout << std::endl;

    Proxy *proxy = new Proxy(real_subject);
    clientCode(*proxy);

    std::cout << std::endl;

    delete real_subject;
    delete proxy;

    return 0;
}
