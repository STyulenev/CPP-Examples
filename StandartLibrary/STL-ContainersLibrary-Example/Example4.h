#pragma once

#include <stack>
#include <queue>

#include <vector>
#include <list>

#include "SomeClass.h"

/*
 * =======================================================================================================================================================================
 *                                                                      Adaptors
 * =======================================================================================================================================================================
 *
 * - stack
 * - queue
 * - priority_queue
 * - flat_set
 * - flat_multiset
 * - flat_map
 * - flat_multimap
 *
 */

namespace Example4 {

namespace Stack {

/*
 * Стек (std::stack) - это структура данных, которая работает по принципу LIFO (last-in first-out или «последний вошёл — первым вышел»).
 * Первым всегда извлекается последний добавленный элемент. Является адаптером, который по умолчанию использует std::deque контейнер.
 *
 */

/*
 * Создание и вставка
 */
void test_1()
{
    std::stack<SomeClass*> stack;

    stack.push(new SomeClass(1));
    stack.push(new SomeClass(2));
    stack.push(new SomeClass(3));

    std::cout << "Stack elements: " << std::endl;
    while (!stack.empty()) {
        std::cout << stack.top()->getField() << std::endl;

        delete stack.top(); // Удаление объекта
        stack.pop(); // Удаление верхнего элемента из стека

    }
    std::cout << std::endl;
}

/*
 * Использование vector в качестве контейнера
 */
void test_2()
{
    std::stack<SomeClass*, std::vector<SomeClass*>> stack;

    stack.push(new SomeClass(1));
    stack.push(new SomeClass(2));
    stack.push(new SomeClass(3));

    std::cout << "Stack elements: " << std::endl;
    while (!stack.empty()) {
        std::cout << stack.top()->getField() << std::endl;

        delete stack.top(); // Удаление объекта
        stack.pop(); // Удаление верхнего элемента из стека

    }
    std::cout << std::endl;
}

/*
 * Использование list в качестве контейнера
 */
void test_3()
{
    std::stack<SomeClass*, std::list<SomeClass*>> stack;

    stack.push(new SomeClass(1));
    stack.push(new SomeClass(2));
    stack.push(new SomeClass(3));

    std::cout << "Stack elements: " << std::endl;
    while (!stack.empty()) {
        std::cout << stack.top()->getField() << std::endl;

        delete stack.top(); // Удаление объекта
        stack.pop(); // Удаление верхнего элемента из стека

    }
    std::cout << std::endl;
}

void test()
{
    test_1();
    test_2();
    test_3();
}

} // namespace Stack






namespace Queue {

/*
 * Стек (std::stack) - это структура данных, которая построена по принципу FIFO (first in — first out: первым пришёл — первым вышел).
 * Является адаптером, который по умолчанию использует std::list контейнер.
 *
 */

/*
 * Создание и вставка
 */
void test_1()
{
    std::queue<SomeClass*> queue;

    queue.push(new SomeClass(1));
    queue.push(new SomeClass(2));
    queue.push(new SomeClass(3));

    std::cout << "Queue elements: " << std::endl;
    while (!queue.empty()) {
        std::cout << queue.front()->getField() << " "<< std::endl;

        delete queue.front();
        queue.pop();
    }

    std::cout << std::endl;
}

/*
 * Использование queue в качестве контейнера. std::vector не сработает т.к. не имеет pop_front метода.
 */
void test_2()
{
    std::queue<SomeClass*, std::deque<SomeClass*>> queue;

    queue.push(new SomeClass(1));
    queue.push(new SomeClass(2));
    queue.push(new SomeClass(3));

    std::cout << "Queue elements: " << std::endl;
    while (!queue.empty()) {
        std::cout << queue.front()->getField() << " "<< std::endl;

        delete queue.front();
        queue.pop();
    }

    std::cout << std::endl;
}

void test()
{
    //test_1();
    test_2();
}

} // namespace Queue

} // namespace Example4
