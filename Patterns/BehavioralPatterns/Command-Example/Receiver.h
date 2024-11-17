#pragma once

#include <string>

/*!
 * \brief Некоторый класс-получатель с бизнес логикой
 */
class Receiver
{
public:
    void doSomething(const std::string& a);
    void doSomethingElse(const std::string& b);

};
