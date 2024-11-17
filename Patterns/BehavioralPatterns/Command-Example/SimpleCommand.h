#pragma once

#include <string>

#include "CommandInterface.h"

/*!
 * \brief Простая команда
 */
class SimpleCommand : public CommandInterface
{
private:
    std::string pay_load_;

public:
    explicit SimpleCommand(std::string pay_load);

    void execute() const override;

};
