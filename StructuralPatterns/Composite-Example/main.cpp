#include <iostream>

#include "Composite.h"
#include "Leaf.h"

void clientCode(Component* component)
{
    // ...
    std::cout << "RESULT: " << component->someAction() << std::endl;
    // ...
}

int main()
{
    Component* simple = new Leaf();
    std::cout << "Simple component:" << std::endl;
    clientCode(simple);

    std::cout << std::endl;

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
    std::cout << "Client: Now I've got a composite tree:" << std::endl;
    clientCode(tree);

    delete simple;
    delete tree;
    delete branch1;
    delete branch2;
    delete leaf_1;
    delete leaf_2;
    delete leaf_3;

    return 0;
}
