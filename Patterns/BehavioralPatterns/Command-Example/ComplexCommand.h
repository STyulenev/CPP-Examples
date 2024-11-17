#pragma once

#include <string>

#include "CommandInterface.h"
#include "Receiver.h"

/*!
 * \brief Сложная команда
 */
class ComplexCommand : public CommandInterface
{
private:
    Receiver* receiver_;

    std::string a_;
    std::string b_;

public:
    ComplexCommand(Receiver* receiver, std::string a, std::string b);

    void execute() const override;

};
