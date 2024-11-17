#pragma once

/**
 * Интерфейс Компонента объявляет метод accept, который в качестве аргумента
 * может получать любой объект, реализующий интерфейс посетителя.
 */

class VisitorInterface;

class ComponentInterface
{
public:
    virtual ~ComponentInterface() {}

    virtual void someAction(VisitorInterface* visitor) const = 0;

};
