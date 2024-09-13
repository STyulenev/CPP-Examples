#pragma once

#include "AbstractHandler.h"

/*!
 * \brief Конкретный обработчик 1
 */
class Handler1 : public AbstractHandler
{
public:
    std::string someAction(std::string data) override;

};

/*!
 * \brief Конкретный обработчик 2
 */
class Handler2 : public AbstractHandler
{
public:
    std::string someAction(std::string data) override;

};

/*!
 * \brief Конкретный обработчик 3
 */
class Handler3 : public AbstractHandler
{
public:
    std::string someAction(std::string data) override;

};
