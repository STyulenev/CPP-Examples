#pragma once

#include <string>

class MementoInterface;

/*!
 * \brief Класс-создатель отвечает за сохранение, обновление и возврат состояния
 */
class Originator
{
private:
    std::string state_;

public:
    Originator(std::string state);

    void update(const std::string& state);

    MementoInterface* save();
    void restore(MementoInterface* memento);

};
