#include <iostream>

#include "Composite.h"
#include "Leaf.h"

/*
 * Компоновщик – это структурный паттерн, который позволяет создавать дерево объектов и работать с ним так же,
 * как и с единичным объектом.
 */

int main()
{
    Component* simple = new Leaf();

    // Пример вывода одиночного листа
    std::cout << "RESULT: " << simple->someAction() << std::endl;

    Component* tree = new Composite();
    Component* branch1 = new Composite();
    Component* leaf_1 = new Leaf();
    Component* leaf_2 = new Leaf();
    Component* leaf_3 = new Leaf();

    branch1->add(leaf_1);
    branch1->add(leaf_2);

    Component* branch2 = new Composite();

    branch2->add(leaf_3);

    tree->add(branch1);
    tree->add(branch2);

    // Пример вывода дерева
    std::cout << "RESULT: " << tree->someAction() << std::endl;

    delete simple;
    delete tree;
    delete branch1;
    delete branch2;
    delete leaf_1;
    delete leaf_2;
    delete leaf_3;

    return 0;
}
