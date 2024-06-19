
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
FUNCION DE PARTICION
[]Elegir el ultimo elemento del array como pivote.
[]Organizar los elemento del array de haciendo que todos los elementos menores que el pivote queden a la izquierda.
[]Poner el pivote en la posicion que debida y devolver el indice indicion.
*/

int particion(int unArray[], int numeroBajo, int numeroAlto){
    int pivote = unArray[numeroAlto]; ///Ultimo elemento como pivote
    int i = numeroBajo - 1; /// Indice del elemento mas pequeño

    for (int j = numeroBajo; j <= numeroAlto - 1; j++){
        if (unArray[j] < pivote){
            i++;
            swap(unArray[i], unArray[j]);
        }
    }
    swap(unArray[i + 1], unArray[numeroAlto]); /// poner pivote en posicion correcta
    return (i + 1);
}

/*

FUNCION QUICKSORT
[]Si el primer numero(numeroBajo) es menor que el ultimo numero(numeroAlto), particionar el array usando la funcion que hice
antes y se obtiene asi el indice de particion(indiceParticion).
[]Llamar recursivamente a la funcion QUICKSORT para los subarray a la izquierda y derecha del pivote.

*/

void quicksort(int unArray[], int numeroBajo, int numeroAlto){
    if (numeroBajo < numeroAlto) {
        int indiceParticion = particion(unArray, numeroBajo, numeroAlto);

        quicksort(unArray, numeroBajo, indiceParticion - 1);
        quicksort(unArray, indiceParticion + 1, numeroAlto);
    }
}

/*

FUNCION PRINCIPAL
[]Leer el numero de elementos y los elementos del array.
[]LLamar a QUICKSORT para ordenar el arreglo.
[]Mostrar el arreglo ordenado.

*/

int main (){

int largoArray;

cout << "Ingrese el largo del vector: ";
cin >> largoArray;
cout << endl;

int numeros[largoArray];
srand(time(0));

for (int i = 0; i < largoArray; i++){
    numeros[i] = rand() % 100;
}
cout << "La lista desordenada es: ";
for (int i = 0; i < largoArray; i++){
    cout << numeros[i] << " ";
}

cout << endl << endl;

quicksort(numeros, 0, largoArray - 1);

cout << "La lista ordenada es: ";
for (int i = 0; i < largoArray; i++){
    cout << numeros[i] << " ";
}

cout << endl;

return 0;
}
