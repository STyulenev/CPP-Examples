#pragma once

#include <iostream>

/*
 * Целовой класс, который имеет виртуальные методы для создания или клонирования объекта
 */
class AbstractTarget
{
public:
    /*
     * Конструктор не может быть виртуальный
     */
    AbstractTarget() {
        std::cout << "AbstractTarget::AbstractTarget()" << std::endl;
    }

    virtual ~AbstractTarget() {
        std::cout << "AbstractTarget::~AbstractTarget()" << std::endl;
    }

    virtual AbstractTarget* create() const = 0; // ~Виртуальный конструктор
    virtual AbstractTarget* clone() const = 0;  // ~Виртуальный конструктор копирования

};
