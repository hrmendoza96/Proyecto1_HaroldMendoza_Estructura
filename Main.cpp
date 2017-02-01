#include <iostream>
#include "Object.h"
#include "ADTList.h"
#include "FSArrayList.h"
#include "Person.h"
#include "VSArrayList.h"

using namespace std;

int main(int argc, char const *argv[]) {
    FSArrayList*  arreglo = new FSArrayList(4);
    Person* p = new Person("Harold", 20);
    arreglo->insert(p,0);
    //cout << arreglo->get(0)->toString();
    Person* p2 = new Person("Gaby",  21);
    arreglo->insert(p2,1);
    for (int i = 0; i < arreglo->size(); i++) {
      cout << arreglo->get(i)->toString();
    }

    cout<< "First: " << arreglo->first()->toString();
    cout<< "Last: " << arreglo->last()->toString();

    cout << "Index of Object 'p' : " << arreglo->indexOf(p) << endl;
    cout << "Index of Object 'p2' : " << arreglo->indexOf(p2) << endl;

    cout << "Capacity: " << arreglo->capacity()<< endl;
    bool isEmpty=arreglo->isEmpty();
    if(isEmpty==0){
      cout << "Is Empty? = FALSE" << endl;
    }else{
      cout << "Is Empty? = TRUE" << endl;
    }
    bool isFull=arreglo->isFull();
    if(isFull==0){
      cout << "Is Full? = FALSE" << endl;
    }else{
      cout << "Is Full? = TRUE" << endl;
    }

    cout << "Removido "<<arreglo->remove(0)->toString();



  return 0;
}
