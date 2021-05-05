/*
Author:        jorgealejandro@superdell-popos
Compiler:      gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
For execute:   gcc Aceleration.c  -lm -o  Aceleration  && ./Aceleration
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

///////////////////////////////////////////////////////////////////////
////////////////////////////// Constant //////////////////////////////

///////////////////////////////////////////////////////////////////////
////////////////////////////// Variables //////////////////////////////

int n = 6;                                      // Cantidad de elementos en las listas
double v[] = {1,3,8,11,14,18};                  // Lista de velocidades
double t[] = {2.1,3.0,5.2,7.1,9.2,10.1};        // Lista de tiempos
double err = 0.1;                               // Error de la medicion de t

double tfinal = 15;                             // Tiempo en el que se desea conocer la velocidad

///////////////////////////////////////////////////////////////////////
////////////////////////////// Functions //////////////////////////////

double ProdDSum(double a[], double b[]); // Funcion que suma los elementos de dos lists y los multiplica
double SumDProd(double a[], double b[]); // Funcion que multiplica elemento a elemento de dos listas y suma los productos
double Sum(double a[]);                  // Funcion que suma los elementos en una lista
double m();                              // Funcion que calcula la pendiente
double b(double m);                      // Funcion que calcula el corrimiento
double Dm();                             // Funcion que calcula el error de m
double Db();                             // Funcion que calcula el error de b

///////////////////////////////////////////////////////////////////////
////////////////////////////// Main //////////////////////////////

void main(){
    double v;
    double slope = m();
    printf("a = %f ± %f\n",slope, Dm());            // Imprime la pendiente con su error
    printf("v(0) = %f ± %f\n",b(slope),Db());       // Imprime el corrimiento con su error
    v = slope*tfinal+b(slope);                      // Calcula la velocidad en t_final
    printf("\nv(15) = %f\n",v);                     // Imprime la velocidad en t_final
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

double Dm(){                                         // Calcula el error de la pendiente con la formula de minimos cuadrados
    double r;
    r = (sqrt(n)*err)/(sqrt(n*SumDProd(t,t)-ProdDSum(t,t)));
    return r;
}

double Db(){                                 // Calcula el error del desplazamiento de la grafica con la formula de minimos cuadrados.
    double r;
    r = err/sqrt(n);
    return r;
}