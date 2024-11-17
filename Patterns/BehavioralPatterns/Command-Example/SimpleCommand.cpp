#include "SimpleCommand.h"

#include <iostream>

SimpleCommand::SimpleCommand(std::string pay_load) :
    pay_load_(pay_load)
{
    // ...
}

void SimpleCommand::execute() const
{
  std::cout << "SimpleCommand: running... ("<< this->pay_load_ << ")" << std::endl;
}
