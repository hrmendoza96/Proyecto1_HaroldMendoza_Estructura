#pragma once
#include "Object.h"
#include <iostream>


class Person : public Object{
protected:
  string name;
  int age;

public:
  Person(string, int);
  virtual string toString() const;
  virtual bool equals(Object*) const;
};
