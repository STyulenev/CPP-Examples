#pragma once

#include <iostream>

namespace Example1 {

void test1()
{
    class SomeClass
    {
    private:
        mutable int counter = 0;

    public:
        // В константном методе нельзя изменять не mutable поля
        void task() const {
            std::cout << "task ..., # " << counter << std::endl;

            counter++;
        }
    };

    SomeClass someClass;

    someClass.task();
    someClass.task();
    someClass.task();
    someClass.task();
}

void test2()
{
    int counter = 0;

    // Без mutable нельзя менять захваченные переменные, т.к. перегрузка operator() имеет const
    auto lambda = [counter]() mutable -> void {
        std::cout << "task ..., # " << counter << std::endl;

        counter++;
    };

    lambda();
    lambda();
    lambda();
    lambda();
}

void test3()
{
    class SomeClass
    {
    private:
        mutable int counter = 0;

    public:
        void task() const {
            std::cout << "task ..., # " << counter << std::endl;

            counter++;
        }
    };

    // Не mutable поля нельзя изменять в константном объекте
    const SomeClass someClass;

    someClass.task();
    someClass.task();
    someClass.task();
    someClass.task();
}

} // namespace Example1
