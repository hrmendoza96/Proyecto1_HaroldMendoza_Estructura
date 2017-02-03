#include <iostream>
#include "VSArrayList.h"
#include "ADTList.h"
#include <cstdlib>

VSArrayList::VSArrayList(int current_capacity){
  this-> current_capacity = current_capacity;
  array = new Object* [current_capacity];
  if(!array){
    cerr << "out of memory"  << endl; //cerr para tirar error por la consola
    exit(1); //no es la mejor manera
  }

}
VSArrayList::VSArrayList(int current_capacity, int delta){
  this->current_capacity=current_capacity;
  this->delta=delta;
}
//Destructor
VSArrayList::~VSArrayList(){
  for (int i = 0; i < size(); i++) {
    if(array[i]){
      delete array[i];
    }
  }
  delete [] array;
}

bool VSArrayList::insert(Object* e, int p){
    if(p<0 || p> tamano){
          return false;
     }
     if(tamano==current_capacity){
       resize();
     }
     for (int i = tamano; i> p ; i--){
          array[i] = array[i-1];
     }
     array[p]=e;
     tamano++;
     return true;
}

void VSArrayList::resize(){
  Object** temp  = NULL;
  temp= new Object*[current_capacity + delta];
  //validar memoria
  for (int i = 0; i < current_capacity; i++) {
    temp[i]= array[i];
  }
  delete[] array;
  array=temp;
  current_capacity+=delta;

}

Object* VSArrayList::remove(int p){
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
Object* VSArrayList::first() const{
    return array[0];



}
Object* VSArrayList::last() const{
  return array[tamano-1];
}

void  VSArrayList::clear(){
  for (int i = 0; i < size(); i++) {
    if(array[i]){
      delete array[i];
      array[i] = NULL;
    }
  }
}

int VSArrayList::indexOf(Object* e) const{
  int aux=0;
  for (int i = 0; i < tamano; i++) {
      if(array[i]==e){
        aux=i;
      }
  }
  return aux;

}
Object* VSArrayList::get(int p) const{
  return array[p];

}
int VSArrayList::capacity() const{
  return current_capacity;

}
bool VSArrayList::isEmpty() const{
  if(tamano==0){
    return true;
  }else{
    return false;
  }

}
bool VSArrayList::isFull() const{
  if(tamano==current_capacity){
    return true;
  }else{
    return false;
  }
}


//Object Heritage
string VSArrayList::toString() const{
  return "";

}
bool  VSArrayList::equals(Object*) const{
  return false;

}
