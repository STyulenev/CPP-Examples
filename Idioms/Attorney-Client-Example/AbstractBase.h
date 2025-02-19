#pragma once

/*
 * Абстрактный класс-клиент с набором виртуальных методов. Имеет дружественный класс Attorney (адвокат), который единственным
 * имеет доступ к закрытым членам класса AbstractBase.
 */
class AbstractBase
{
    // Список дружественных классов/функций
    friend class Attorney;
    // ...

private:
    virtual void action1(int value) = 0;
    virtual void action2() = 0;
    // ...

public:
    AbstractBase() {}
    virtual ~AbstractBase() {}

};
