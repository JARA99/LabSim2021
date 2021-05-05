/*
Author:        jorgealejandro@superdell-popos
Compiler:      gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
For execute:   gcc Grafica.c  -o  Grafica  && ./Grafica
Date:          Sun 02 May 2021 01:14:11 PM CST
Libraries:     stdio
Abstract:     
Inputs:       
Outputs:      
*/            


///////////////////////////////////////////////////////////////////////
////////////////////////////// Libraries //////////////////////////////

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// #define BUFFER_SIZE 225

///////////////////////////////////////////////////////////////////////
////////////////////////////// Constant //////////////////////////////

///////////////////////////////////////////////////////////////////////
////////////////////////////// Variables //////////////////////////////

int n = 6;                                      // Cantidad de elementos en las listas
double v[] = {1,3,8,11,14,18};                  // Lista de velocidades
double t[] = {2.1,3.0,5.2,7.1,9.2,10.1};        // Lista de tiempos
                     

///////////////////////////////////////////////////////////////////////
////////////////////////////// Functions //////////////////////////////

double ProdDSum(double a[], double b[]); // Funcion que suma los elementos de dos lists y los multiplica
double SumDProd(double a[], double b[]); // Funcion que multiplica elemento a elemento de dos listas y suma los productos
double Sum(double a[]);                  // Funcion que suma los elementos en una lista
double m();                              // Funcion que calcula la pendiente
double b(double m);                      // Funcion que calcula el corrimiento


///////////////////////////////////////////////////////////////////////
////////////////////////////// Main //////////////////////////////

void main(){                                        // Ejecuta las funciones m() y b() e imprime la funcion de la forma:
    double slope = m();
    printf("g(x) = (%f*x)+(%f)\n",slope,b(slope));  // g(x) = m*x+b
}

double ProdDSum(double a[], double b[]){            // Multiplica la suma de dos listas
    double SumA = 0;
    double SumB = 0;
    double r;

    for (int i = 0; i < n; i++)
    {
        SumA = SumA + a[i];
        SumB = SumB + b[i];
    }
    
    r = SumA * SumB;
    return r;
}

double SumDProd(double a[], double b[]){            // Suma productos de elemento a elemento en dos listas
    double r = 0;
    
    for (int i = 0; i < n; i++)
    {
        r = r + (a[i] * b[i]);
    }   
    return r;
}

double Sum(double a[]){                             // Suma los elementos en una lista
    double r = 0;
    for (int i = 0; i < n; i++)
    {
        r = r + a[i];
    }
    return r;
}

double m(){                                         // Calcula la pendiente con la formula de minimos cuadrados
    double r;
    r = (n*SumDProd(v,t)-ProdDSum(v,t))/(n*SumDProd(t,t)-ProdDSum(t,t));
    return r;
}

double b(double m){                                 // Calcula el desplazamiento de la grafica con la formula de minimos cuadrados.
    double r;
    r = (Sum(v)-m*Sum(t))/(n);
    return r;
}

