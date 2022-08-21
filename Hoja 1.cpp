#include "pch.h"
#include <iostream>
#include <conio.h>
#include <locale.h>

using namespace System;
using namespace std; 

//FUNCIONES DE LA HOJA 1

void generar_Arreglo(int* arr, int n) {
    Random r;
    for (int i = 0; i < n; i++)
    {
        arr[i] = r.Next(0,10); 
    }
}
void mostrar_Arreglo(int* arr, int n) {

    for (int i = 0; i < n; i++)
    {
        cout << arr[i]; cout << endl;
    }
}
void numero_Mayor(int *arr, int n) {  
    int mayor = 0; 
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mayor) {
            mayor = arr[i]; 
        }
    }
    cout << "El numero mayor es: " << mayor << endl; 
}
void ordenamiento(int *arr, int n) {
    
    int aux=0; 

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <n-1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                aux = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = aux; 
            }
        }
    }
    
}
void eliminar_posicion(int *&arr,int& n, int &pos) {
    
    if (pos >= n)return; 
    int* aux = new int[n - 1]; 
    int i = 0; 
    for (;i<pos; i++)
    {
        aux[i] = arr[i]; 
    }
    for (; i < n-1; i++)
    {
        aux[i] = arr[i+1];
    }
    delete[]arr; 
    arr = aux; 
    aux = nullptr; 
    delete []aux; 
    n--; 
}
void buscar_posicion(int *arr, int n) {
    int num;
    bool ban; 
    cout << "Numero a buscar: "; cin >> num; cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (num == arr[i]) {
            ban = true;
        }
        else ban = false; 
    }
    if (ban == true) {
        cout << "Si se encuentra el numero" << endl;
    }
    else if (ban == false) {
        cout << "No se encuentra el numero" << endl;
    }
}
void factorialNumero() {
    int n;
    double factorial=1;
    cout << "Introduce un numero: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        factorial = factorial * i;
    }
    cout << endl << "Factorial de " << n << " es " << factorial << endl;
}
void existe_numero(int* arr, int n) {
    int num;
    bool ban;
    cout << "Numero a buscar: "; cin >> num; cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (num == arr[i]) {
            ban = true;
        }
        else ban = false;
    }
    if (ban == true) {
        cout << "El numero si existe" << endl;
    }
    else if (ban == false) {
        cout << "El numero No existe" << endl;
    }
}
void RepiteNumero(int* arr,int numeroRepetido, int n) {
    int contRepe = 0; 
    for (int i = 0; i < n; i++)
    {
        if (numeroRepetido == arr[i]) {
            contRepe++; 
        }
    }
    cout << "El elemento " << numeroRepetido << " se repite " << contRepe << " veces.";
}
void sumaDigito() {
    int extNum, sumaDigitos = 0, numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    while (numero != 0) {
        extNum = numero % 10;
        numero /= 10;
        sumaDigitos += extNum;
    }
    cout << "La suma de los digitos es: " << sumaDigitos << endl;
}
void NumeroPrimo() {
    int numero; 
    bool primo = true; 
    cout << "Ingrese un numero: ";
    cin >> numero;
    for (int i = 2; i < numero; i++)
    {
        if (numero % i == 0) {
            primo = false; 
        }
    }
    if (primo == true) {
        cout << "El numero si es primo"; 
    }else cout << "El numero no es primo";
}

void main()
{
    setlocale(LC_ALL, "");
    int n; 
    int numeRepe1 = 3;
    int pos;
    cout << "Ingrese el numero del arreglo:"; cin >> n;
    int* arr = new int[n];
    generar_Arreglo(arr, n); 
    mostrar_Arreglo(arr, n); 
    cout << endl;
    int hacer; 

    cout <<"1. Encontrar el número mayor en un arreglo de enteros                       "<<endl;
    cout <<"2. Ordenar un arreglo de números enteros                                    "<<endl;
    cout <<"3. Eliminar el elemento en una posicion de un arreglo                       "<<endl;
    cout <<"4. Buscar un número en un arreglo                                           "<<endl;
    cout <<"5. Calcular el factorial de N                                               "<<endl;
    cout <<"6. Determinar si un número existe en un arreglo de enteros.                 "<<endl;
    cout <<"7. Calcular cuántas veces se repite un número X en un arreglo de enteros.   "<<endl;
    cout <<"8. Sumar los dígitos de un número entero positivo.                          "<<endl;
    cout <<"9. Determinar si un número es primo o no.                                   "<<endl;
    cout <<"10. Determinar la cantidad de primos que existen en un arreglo de enteros.  "<<endl;
   
    cout << "Opcion:";  cin >> hacer; cout << endl;
    switch (hacer)
    {
    case 1:numero_Mayor(arr,n); break;
    case 2:ordenamiento(arr, n); mostrar_Arreglo(arr, n); break;
    case 3:   
        cout << "Que posicion desea eliminar: "; cin >> pos; cout << endl; 
            eliminar_posicion(arr, n, pos);
            mostrar_Arreglo(arr, n); break;
    case 4:buscar_posicion (arr,n);break;
    case 5:factorialNumero();  break;
    case 6:existe_numero(arr, n);  break;
    case 7:RepiteNumero(arr, numeRepe1, n);break;
    case 8:sumaDigito();  break;
    case 9:NumeroPrimo(); break;
    
    }
   _getch(); 
    
}
