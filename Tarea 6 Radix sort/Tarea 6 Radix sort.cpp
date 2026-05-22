#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "List.h"
#include "linkedList.h"

using std::cout;
using std::cin;
using std::ws;
using std::streamsize;
using std::numeric_limits;
using std::log;
using std::floor;

int potencia(int base, int exponente) {
    int res = 1;
    for (int i = 0; i < exponente; i++) {
        res *= base;
    }
    return res;
}
int calcTotalDigitos(int base) {
    return (int)floor(log((double)32767) / log((double)base)) + 1;
}
void radixSort(int base,List<int>&lista ) {
    linkedList<linkedList<int>*> Baldes;
    for (int i = 0; i < base; i++) {
        linkedList<int>* lista = new linkedList<int>();
        Baldes.append(lista);
    }
    int res;
    int num;
    int totalIteraciones = calcTotalDigitos(base);
    for (int j = 0; j < totalIteraciones; j++) {
        for (int i = 0; i < lista.getSize(); i++) {
            lista.goToPos(i);
            num = lista.getElement();
            res = (num / potencia(base, j)) % base;
            Baldes.goToPos(res);
            Baldes.getElement()->append(num);
        }
        lista.clear();
        for (int numBalde = 0; numBalde < base; numBalde++) {
            Baldes.goToPos(numBalde);
            while (Baldes.getElement()->getSize() != 0) {
                int temp;
                Baldes.getElement()->goToStart();
                temp = Baldes.getElement()->remove();
                lista.append(temp);
            }
        }

    }
}


int main()
{
    bool seguir = true;
    while (seguir) {
        cout << "Ingrese el tamano de la lista que desea ordenar: \n";
        int tamano;
        while (!(cin >> ws >> tamano) || tamano <= 0) {
            cout << "Debe ser un numero entero positivo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Ingrese la base numerica que desea utilizar: \n";
        int base;
        while (!(cin >> ws >> base)|| base<=0) {
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
        
        time_t creacionLista = time(nullptr);
        cout << "Lista sin ordenar: \n";
        lista.print();
        radixSort(base, lista);

        cout << "\n" << "Lista ordenada: \n";
        lista.print();
        time_t listaOrdenada = time(nullptr);
        cout << "Tiempo que se duro en ordenar la lista: " << difftime(listaOrdenada, creacionLista) << "\n";
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
