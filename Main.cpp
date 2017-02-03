#include <iostream>
#include "Object.h"
#include "ADTList.h"
#include "FSArrayList.h"
#include "Person.h"
#include "Empleado.h"
#include "VSArrayList.h"

using namespace std;

void menu();

int main(int argc, char const *argv[]) {
    int capacidad=0;
    cout << "Ingrese Capacidad Inicial para Lista de Empleados: ";
    cin>> capacidad;
    ADTList* ListaEmpleados = new VSArrayList(capacidad);
    cout << "La lista de Empleados ha sido creada exitosamente con una capacidad de: " << ListaEmpleados->capacity()<< " (Capacidad puede ser incrementada)"<< endl;
    cout << "Capacity "<<ListaEmpleados->capacity()<<endl;
    cout << "Size "<<ListaEmpleados->size()<<endl;
    cout << endl;
    int opcion=0;
    do {
      menu();
      cin >> opcion;
      if(opcion==1){ //Insertar Empleado
        /**
        *TODO: Validar
        */
        //pedir datos
          cout << "\033[2J\033[1;1H"; //limpiar consola
        string nombre; int edad; double salario;
        cout << "Ingrese el nombre del Empleado: ";
        cin >> nombre;
        cout << endl;
        cout << "Ingrese la edad del Empleado: ";
        cin >>  edad;
        cout << endl;
        cout << "Ingrese el salario del Empleado: ";
        cin >>  salario;
        cout << endl;

        int posicion;
        cout << "Ingrese la posicion en que desea agregar al Empleado: ";
        cin >>  posicion;
        cout << endl;

          cout << "\033[2J\033[1;1H";
        //crear Empleado
        if(ListaEmpleados->insert(new Empleado(nombre,edad,salario), posicion) ){
          cout << "Empleado Ingresado Exitosamente" << endl<<endl;
        }else{
          cout << "No se ha podido ingresar al empleado"<<endl<<endl;
        }

      }
      if(opcion==2){ //Listar Empleado
        cout << "\033[2J\033[1;1H";
        cout << "Lista de Empleados: " << endl;
        if(!ListaEmpleados->isEmpty()){
          for (int i = 0; i < ListaEmpleados->size(); i++) {
            cout<< i <<") "<< ListaEmpleados->get(i)->toString() << endl;
          }
        }else{
          cout << "La Lista de Empleados esta Vacia"<< endl<<endl;
        }
      }
      if(opcion==3){ //Borrar Empleado
        cout << "\033[2J\033[1;1H";
        cout << "Lista de Empleados: " << endl;
        if(!ListaEmpleados->isEmpty()){
          for (int i = 0; i < ListaEmpleados->size(); i++) {
            cout<< i <<") "<< ListaEmpleados->get(i)->toString() << endl;
          }
          int numeroBorrar;
          cout << "Escoger numero del empleado que desea Borrar de la Lista: ";
          cin>> numeroBorrar;
          cout <<endl;
          if(numeroBorrar>=0 && numeroBorrar<ListaEmpleados->size()){
            Empleado* empleadoBorrado = (Empleado*)ListaEmpleados->remove(numeroBorrar);
            cout << "Se ha borrado a :"<<empleadoBorrado->toString()<<endl<<endl;
          }else{
            cout << "No existe esa posicion de empleado"<<endl<<endl;
          }


        }else{
          cout << "La Lista de Empleados esta Vacia"<< endl<<endl;
        }


      }
      if(opcion==4){ //Calcular Salario Promedio
        cout << "\033[2J\033[1;1H";
        double promedio=0;
        if(!ListaEmpleados->isEmpty()){
          for (int i = 0; i < ListaEmpleados->size(); i++) {
            Empleado* empleado = (Empleado*) ListaEmpleados->get(i);
            promedio+=empleado->getSalario();
          }
          promedio=promedio/ListaEmpleados->size();
          cout << "El Promedio Salarial de los empleados es de: $" << promedio << endl<<endl;
        }else{
          cout << "La Lista de Empleados esta Vacia"<< endl<<endl;
        }
      }
      if(opcion==5){ //Ver Salario Maximo
        cout << "\033[2J\033[1;1H";
        double max=0;
        for (int i = 0; i < ListaEmpleados->size(); i++) {
          if( (dynamic_cast <Empleado*> (ListaEmpleados->get(i))->getSalario() ) > max ){
            max = dynamic_cast <Empleado*> (ListaEmpleados->get(i))->getSalario();
          }
        }

        cout << "El salario maximo es: $"<<max << endl<<endl;


      }
      if(opcion==6){ //Ver Salario Minimo
        cout << "\033[2J\033[1;1H";
        double min=0;
        int cont=0;
        for (int i = 0; i < ListaEmpleados->size(); i++) {
          if(cont==0 && min==0){
            min = dynamic_cast <Empleado*> (ListaEmpleados->get(i))->getSalario();
            cont++; //contador para permitir que este proceso solo se haga una vez

          }else{
            if( (dynamic_cast <Empleado*> (ListaEmpleados->get(i))->getSalario() ) < min ){
              min = dynamic_cast <Empleado*> (ListaEmpleados->get(i))->getSalario();
            }

          }

        }

        cout << "El salario maximo es: $"<<min << endl<<endl;

      }
      if(opcion==7){  // Dar Incremento por Inflacion

      }
      if(opcion==8){
        cout << "Hasta Pronto"<<endl;
      }

    } while(opcion!=8);


  return 0;
}

void menu(){
  cout << "Bienvenido al Sistema para administrar el Sueldo de sus Empleados "<<endl;
  cout << "1) Insertar Empleado"<<endl<<"2) Listar Empleado" << endl <<"3) Borrar Empleado"<<endl;
  cout << "4) Calcular Salario Promedio"<<endl<<"5) Ver Salario Maximo"<<endl;
  cout << "6) Ver Salario Minimo" <<endl<< "7) Dar Incremento por Inflacion"<<endl;
  cout << "8) Salir"<<endl<<"Ingrese su opcion: ";
}
