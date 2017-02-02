#pragma once
#include <iostream>
#include <sstream>
#include "Object.h"
#include "Person.h"

class Empleado : public Person{
  protected:
    double salario;
  public:
    //Empleado();
    Empleado(string, int, double);
    double getSalario();
    void setSalario(double);
    void setInflacion(double);
    virtual string toString() const;
    virtual bool equals(Object*) const;


};
