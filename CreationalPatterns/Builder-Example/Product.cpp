#include "Product.h"

Product::Product()
{
    // ...
}

Product::~Product()
{
    // ...
}

void Product::makeA(const std::string &part)
{
    partA = part;
}

void Product::makeB(const std::string &part)
{
    partB = part;
}

void Product::makeC(const std::string &part)
{
    partC = part;
}

std::string Product::get()
{
    return (partA + " " + partB + " " + partC);
}
