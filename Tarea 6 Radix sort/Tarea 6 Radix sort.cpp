#include <iostream>
#include <cstdlib>
#include <ctime>
#include "List.h"
#include "linkedList.h"

using std::cout;
using std::cin;
using std::ws;
using std::streamsize;
using std::numeric_limits;

void radixSort(int base,List<int>&lista ) {

}


int main()
{
    bool seguir = true;
    while (seguir) {
        cout << "Ingrese el tamaño de la lista que desea ordenar: \n";
        int tamano;
        while (!(cin >> ws >> tamano) || tamano <= 0) {
            cout << "Debe ser un numero entero positivo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Ingrese la base numerica que desea utilizar: \n";
        int base;
        while (!(cin >> ws >> base)) {
            cout << "Debe ser un numero entero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        linkedList<int> lista;
        srand(time(0));
        //rand()
        for (int i = 0; i < tamano; i++) {
            lista.append(rand());
        }
        cout << "Lista sin ordenar: \n";
        lista.print();
        radixSort(base, lista);

        cout << "\n" << "Lista ordenada: ";
        lista.print();
        cout << "Desea repetir el programa? \n";
        cout << "[1] : si \n";
        cout << "[2] : no \n";
        int opcion;
        while (!(cin >> ws >> opcion) || opcion <= 0 || opcion > 2) {
            cout << "Opcion no valida. ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (opcion == 2)
            seguir = false;
    }
    

}
