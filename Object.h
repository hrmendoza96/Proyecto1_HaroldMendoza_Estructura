#pragma once
#include <sstream>
#include <iostream>
#include <string>


using namespace std;

class Object{
  public:
    Object();
    virtual ~Object();
    virtual string toString() const;
    virtual bool  equals(Object*) const;

};
