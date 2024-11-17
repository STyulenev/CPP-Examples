#pragma once

/**
 * Интерфейс Посетителя объявляет набор методов посещения, соответствующих
 * классам компонентов. Сигнатура метода посещения позволяет посетителю
 * определить конкретный класс компонента, с которым он имеет дело.
 */
class ConcreteComponentA;
class ConcreteComponentB;

/*!
 * \brief Интерфейс посетителя
 */
class VisitorInterface
{
public:
    virtual void visitConcreteComponentA(const ConcreteComponentA* element) const = 0;
    virtual void visitConcreteComponentB(const ConcreteComponentB* element) const = 0;

};
