#pragma once

#include <string>

/*
 * Класс-подсистема #2 имеет различные полезные методы без общего интерфейса, которые могут использоваться в клиентском коде.
 * Не имеет ничего общего с подсистемой #1.
 */
class SubSystem2
{
public:
    SubSystem2();
    ~SubSystem2();

    std::string operation3() const;
    std::string operation4() const;
    // ...

};
