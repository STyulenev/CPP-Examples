#include "ConcreteBuilderY.h"

ConcreteBuilderY::ConcreteBuilderY()
{

}

ConcreteBuilderY::~ConcreteBuilderY()
{

}

void ConcreteBuilderY::buildPartA()
{
    product.makeA("A-Y");
}

void ConcreteBuilderY::buildPartB()
{
    product.makeB("B-Y"); }

void ConcreteBuilderY::buildPartC()
{
    product.makeC("C-Y");
}
