#include "ComplexCommand.h"

#include <iostream>

ComplexCommand::ComplexCommand(Receiver* receiver, std::string a, std::string b) :
    receiver_(receiver),
    a_(a),
    b_(b)
{
    // ...
}

void ComplexCommand::execute() const
{
    std::cout << "ComplexCommand: running..." << std::endl;

    this->receiver_->doSomething(this->a_);
    this->receiver_->doSomethingElse(this->b_);
}
