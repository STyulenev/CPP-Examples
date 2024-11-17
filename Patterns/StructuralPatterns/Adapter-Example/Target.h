#pragma once

#include <string>

/*
 * Целевой класс с некоторой логикой
 */
class Target
{
public:
    Target();
    virtual ~Target();

    virtual std::string someAction() const;

};
