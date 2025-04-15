#pragma once

#include <string>

/*
 * Класс-подсистема #1 имеет различные полезные методы без общего интерфейса, которые могут использоваться в клиентском коде.
 * Не имеет ничего общего с подсистемой #2.
 */
class SubSystem1
{
public:
    SubSystem1();
    ~SubSystem1();

    std::string operation1() const;
    std::string operation2() const;
    // ...

};
