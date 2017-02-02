#include <iostream>
#include <sstream>
#include "Object.h"
#include "Person.h"
#include "Empleado.h"

//Empleado::Empleado(){}
Empleado::Empleado(string name, int age, double salario):Person(name,age){
  this->salario=salario;
}
double Empleado::getSalario(){
  return salario;

}
void Empleado::setSalario(double salario){
  this->salario=salario;

}
void Empleado::setInflacion(double inflacion){

}

string Empleado::toString() const{
  stringstream ss;
  ss << Person::toString() << "Salario: " << salario << "\n";
  return ss.str();
}

bool Empleado::equals(Object* other) const{
  if(dynamic_cast <Empleado*>(other)){
    return false;
  }

  //Person* p = dynamic_cast<Empleado*>(other);
  //return p->name==name;
}
