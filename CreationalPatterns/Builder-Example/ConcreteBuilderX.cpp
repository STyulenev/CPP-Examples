#include "ConcreteBuilderX.h"

ConcreteBuilderX::ConcreteBuilderX()
{

}

ConcreteBuilderX::~ConcreteBuilderX()
{

}

void ConcreteBuilderX::buildPartA()
{
    product.makeA("A-X");
}

void ConcreteBuilderX::buildPartB()
{
    product.makeB("B-X");
}

void ConcreteBuilderX::buildPartC()
{
    product.makeC("C-X");
}
