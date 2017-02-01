#include <iostream>
#include "Person.h"

using namespace std;

Person::Person(string name, int age):name(name),age(age){

}

string Person::toString() const{
  stringstream ss;
  ss << "Name: " << name << " Age: " <<age<<endl;
  return ss.str();
}

bool Person::equals(Object* other) const{
  if(dynamic_cast <Person*>(other)){
    return false;
  }

  Person* p = dynamic_cast<Person*>(other);
  return p->name==name;
}
