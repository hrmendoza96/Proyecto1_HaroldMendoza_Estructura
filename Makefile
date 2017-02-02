Main: Main.o Object.o Person.o Empleado.o ADTList.o FSArrayList.o VSArrayList.o
	g++ Main.o Object.o Person.o Empleado.o ADTList.o FSArrayList.o VSArrayList.o -o Main
Main.o: Main.cpp Object.h Person.h Empleado.h ADTList.h FSArrayList.h VSArrayList.h
	g++ -c Main.cpp
Object.o: Object.h Object.cpp
	g++ -c Object.cpp
Person.o: Object.h Person.h Person.cpp
	g++ -c Person.cpp
Empleado.o: Person.h Empleado.h Empleado.cpp
	g++ -c Empleado.cpp
ADTList.o: ADTList.h ADTList.cpp
	g++ -c ADTList.cpp
FSArrayList.o: ADTList.h FSArrayList.h FSArrayList.cpp
	g++ -c FSArrayList.cpp
VSArrayList.o: ADTList.h VSArrayList.h VSArrayList.cpp
	g++ -c VSArrayList.cpp
Clean:
	rm -f *.o temp
