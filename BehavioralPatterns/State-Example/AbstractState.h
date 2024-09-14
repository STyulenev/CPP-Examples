#pragma once

class Context;

/*!
 * \brief Абстрактное состояние, с указателем на текущий класс-контекст
 */
class AbstractState
{
protected:
    Context* context_;

public:
    AbstractState();
    virtual ~AbstractState();

    void setContext(Context* context);

    virtual void handle1() = 0;
    virtual void handle2() = 0;

};
