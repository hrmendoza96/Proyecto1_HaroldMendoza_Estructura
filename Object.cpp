#include "Object.h"
#include <iostream>
#include <sstream>

Object::Object(){}
Object::~Object(){}

string Object::toString() const{
  stringstream ss;
  ss << "Object@" <<  this;
  return ss.str();
}

bool Object::equals(Object* other) const{
  return other==this;
}
