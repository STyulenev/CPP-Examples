#pragma once

/*
 * Интерфейс для класса с логикой
 */
class Logic
{
public:
    Logic();
    virtual ~Logic();

    virtual void someAction() = 0;
    // ...

};

/*
 * Реализация конкретного класса с логикой
 */
class ConcreteLogic1 : public Logic
{
public:
    ConcreteLogic1();
    virtual ~ConcreteLogic1();

    void someAction() override;
    // ...

};

/*
 * Реализация конкретного класса с логикой
 */
class ConcreteLogic2 : public Logic
{
public:
    ConcreteLogic2();
    virtual ~ConcreteLogic2();

    void someAction() override;
    // ...

};
