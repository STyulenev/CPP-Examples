#include "Handlers.h"

std::string Handler1::someAction(std::string data)
{
    if (data == "1") {
        return "First == " + data + ".\n";
    } else {
        return AbstractHandler::someAction(data);
    }
}

std::string Handler2::someAction(std::string data)
{
    if (data == "2") {
        return "Second == " + data + ".\n";
    } else {
        return AbstractHandler::someAction(data);
    }
}

std::string Handler3::someAction(std::string data)
{
    if (data == "3") {
        return "Third == " + data + ".\n";
    } else {
        return AbstractHandler::someAction(data);
    }
}
