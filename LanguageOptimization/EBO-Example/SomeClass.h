#pragma once

#include <iostream>

/*
 * Интерфейс ISomeClass имеет sizeof(ISomeClass) равный 1, т.к. статические члены класса не пренадлежат
 * классу и не увеличивают его вес (даже на 1 байт).
 */
class ISomeClass
{
protected:
    static int counter;

// При использовании v-table размер класса увеличится на 4 или 8 байт (в зависимости от разрядности)
/*public:
    virtual void print() = 0;
    // ...
*/

};

/*
 * Класс SomeClass имеет sizeof(SomeClass) равный 1, т.к. наследован от ISomeClass (используется EBO) и
 * не имеет своих полей. Если наследовать SomeClass от двух и более пустых классов, то EBO не будет работать.
 */
class SomeClass : public ISomeClass
{
public:
    SomeClass() {
        counter++;
    }

    /*void print() override {
        std::cout << "SomeClass::print()" << counter << std::endl;
    }

    // ...
    */

};
