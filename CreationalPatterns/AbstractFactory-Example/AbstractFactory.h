#pragma once

#include "AbstractProductA.h"
#include "AbstractProductB.h"

class AbstractFactory
{
public:
  virtual AbstractProductA* createProductA() const = 0;
  virtual AbstractProductB* createProductB() const = 0;

};
