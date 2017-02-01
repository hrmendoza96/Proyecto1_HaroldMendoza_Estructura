#include <iostream>
#include "ADTList.h"
#include "Object.h"
#include "FSArrayList.h"
#include <cstdlib>
//Constructor
FSArrayList::FSArrayList(int capacidad){
  this-> capacidad = capacidad;
  array = new Object* [capacidad];
  if(!array){
    cerr << "out of memory"  << endl; //cerr para tirar error por la consola
    exit(1); //no es la mejor manera
  }

}
//Destructor
FSArrayList::~FSArrayList(){
  for (int i = 0; i < size(); i++) {
    if(array[i]){
      delete array[i];
    }
  }
  delete [] array;
}

bool FSArrayList::insert(Object* e, int p){
    if(p<0 || p> tamano){
          return false;
     }
     if(isFull()){
          return false;
     }
     for (int i = tamano; i> p ; i--){
          array[i] = array[i-1];
     }
     array[p]=e;
     tamano++;
     return true;

}
Object* FSArrayList::remove(int p){
  Object* elemento = array[p];
  //delete array[p];
  array[p] = NULL;
  for (int i = p; i < tamano-1; i++) { //corre los elementos del arreglo
    array[i]=array[i+1];
  }
  delete array[tamano-1]; //elimina el ultimo elemento del arreglo que queda sobrante
  tamano--;
  return elemento;


}
Object* FSArrayList::first() const{

    return array[0];



}
Object* FSArrayList::last() const{
  return array[tamano-1];
}

void  FSArrayList::clear(){
  for (int i = 0; i < size(); i++) {
    if(array[i]){
      delete array[i];
      array[i] = NULL;
    }
  }
}

int FSArrayList::indexOf(Object* e) const{
  int aux=0;
  for (int i = 0; i < tamano; i++) {
      if(array[i]==e){
        aux=i;
      }
  }
  return aux;

}
Object* FSArrayList::get(int p) const{
  return array[p];

}
int FSArrayList::capacity() const{
  return capacidad;

}
bool FSArrayList::isEmpty() const{
  if(tamano==0){
    return true;
  }else{
    return false;
  }

}
bool FSArrayList::isFull() const{
  if(tamano==capacidad){
    return true;
  }else{
    return false;
  }
}
