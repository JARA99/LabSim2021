/*
Author:        jorgealejandro@superdell-popos
Compiler:      gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
For execute:   gcc Root.c  -lm -o  Root  && ./Root
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
#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////
////////////////////////////// Constant //////////////////////////////

const double MinErr = 1; // Error mínimo admitido

///////////////////////////////////////////////////////////////////////
////////////////////////////// Variables //////////////////////////////

double FMin = 0;          // Menor valor en el intervalo original
double FMax = 5;          // Mayor valor en el intervalo original
double Min;              // Menor valor en el intervalo actual
double Max;              // Mayor valor en el intervalo actual
double Med;              // Variable para almacenar el valor medio actual entre Min y Max
double r;                // [r]oot Varialbe para almacenar el valor actual de la raiz
double l;                // [l]ast Varialbe para almacenar el valor anterior de la raiz

///////////////////////////////////////////////////////////////////////
////////////////////////////// Functions //////////////////////////////

double eval();           // Funcion que realiza las comparaciones evaluaciones
double err();            // Funcion que calcula el error
double f(double x);              // Funcion que emula la funcion matematica

///////////////////////////////////////////////////////////////////////
////////////////////////////// Main //////////////////////////////

void main(){
    Min = FMin;          // Asigna el intervalo inicial al intervalo variable
    Max = FMax;          // Asigna el intervalo inicial al intervalo variable
    l = FMin;            // Guarda el valor anterior de la raiz en l
    r = eval();          // Guarda el valor acual de la raiz en r

    while (err()>1){     // Loop para iterar mientras el error no sea menor a 1
        l = r;           // Guarda el valor anterior de la raiz en l
        r = eval();      // Guarda el valor acual de la raiz en r
    }     
    printf("root on: x = %f\n",r);            // Imprime la raiz con error menor al 1% al usuario
}


double eval(){
    Med = (Min+Max)/2;       // Evalua el valor medio entre Min y Max actual
    if (f(Med)*f(Min) > 0){  // Compara el signo
        // printf("eval()-> Min %f = %f\n",Min,Med);
        Min = Med;           // Remplaza el minimo si tiene el mismo signo
    }           
    else{
        // printf("eval()-> Max %f = %f\n",Max,Med);
        Max = Med;           // Remplaza el maximo si tiene l mismo signo
    }           
    
    return Med;              // Regresa el valor medio actual
}


double err(){
    double a = fabs(r-l)*100/r;
    // printf("err() = (%f-%f)/2 = %f\n",r,l,a);
    return a;     // Regresa el valor del error actual
}


double f(double x){
    double y = (exp((-(x*x))/2)-0.5);
    // printf("f(%f) = %f\n",x,y);
    return y;  // Regresa el valor de la funcion evaluada en x
}