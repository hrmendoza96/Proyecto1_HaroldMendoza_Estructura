#pragma once
#include "Object.h"
#include <iostream>

class ADTList{
protected:
      int tamano;
public:
     ADTList();
     virtual ~ADTList();
     int size();
     virtual bool insert(Object* , int)=0;
     virtual Object* remove(int)=0;
     virtual Object* first() const=0;
     virtual Object* last() const=0;
     virtual void clear()=0;
     virtual int indexOf(Object*) const=0;
     virtual Object* get(int) const=0;
     virtual int capacity() const=0;
     virtual bool isEmpty() const=0;
     virtual bool isFull() const=0;

};
