#pragma once

#include "AbstractProduct.h"

class Creator {
public:
  Creator();
  virtual ~Creator();

  virtual AbstractProduct* factoryMethod() const = 0;
  std::string someOperation() const;

};
