#pragma once

/*!
 * \brief Интерфейс для команд
 */
class CommandInterface
{
public:
    virtual ~CommandInterface() {}

    virtual void execute() const = 0;

};
