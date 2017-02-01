#include <iostream>
#include "ADTList.h"

class FSArrayList : public ADTList{
protected:
  int capacidad; Object** array;
public:
  FSArrayList(int);
  virtual ~FSArrayList();
  virtual bool insert (Object* , int);
  virtual Object* remove(int);
  virtual Object* first() const;
  virtual Object* last() const;
  virtual void clear();
  virtual int indexOf(Object*) const;
  virtual Object* get(int) const;
  virtual int capacity() const;
  virtual bool isEmpty() const;
  virtual bool isFull() const;
};
