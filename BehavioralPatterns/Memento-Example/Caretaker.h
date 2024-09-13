#pragma once

#include <vector>

#include "MementoInterface.h"

class Originator;

/*!
 * \brief Класс-опекун, который позволяет сохранять данные, возвращать предыдущее состояние и показывать историю
 */
class Caretaker
{
private:
    std::vector<MementoInterface*> mementos_;
    Originator* originator_;

public:
    Caretaker(Originator* originator);

    void backup();
    void undo();
    void history() const;

};
