#pragma once

#include "VisitorInterface.h"

/*!
 * \brief Конкретный посетитель, который использует конкретный алгоритм для разных компонентов в отдельных методах
 */
class ConcreteVisitor2 : public VisitorInterface
{
public:
    void visitConcreteComponentA(const ConcreteComponentA* element) const override;
    void visitConcreteComponentB(const ConcreteComponentB* element) const override;

};
