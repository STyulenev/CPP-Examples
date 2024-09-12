#pragma once

#include "CommandInterface.h"

/*!
*  \brief Класс-отправитель, который запускает команды
*/
class Invoker
{
private:
    CommandInterface* onStart_;
    CommandInterface* onFinish_;

public:
    Invoker();
    ~Invoker();

    void setOnStart(CommandInterface* command);
    void setOnFinish(CommandInterface* command);

    void someAction();

};
