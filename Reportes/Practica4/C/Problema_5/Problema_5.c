/*
Author:        jorgealejandro@superdell-popos
Compiler:      gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
For compile:   gcc Problema_5.c  -lm -o  Problema_5  && ./Problema_5
Date:          Fri 07 May 2021 11:20:35 AM CST
Libraries:     stdio
Abstract:     
Inputs:       
Outputs:      
*/            


///////////////////////////////////////////////////////////////////////
////////////////////////////// Libraries //////////////////////////////

#include <stdio.h>


///////////////////////////////////////////////////////////////////////
/////////////////////////////// Constants /////////////////////////////


///////////////////////////////////////////////////////////////////////
/////////////////////////////// Variables /////////////////////////////

int m;                      // Almacena la entrada

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Functions /////////////////////////////

long int fact(int n);       // Genera la salida

///////////////////////////////////////////////////////////////////////
///////////////////////////////   Code    /////////////////////////////

void main(){
    printf("\nIngrese un número entero: ");             //Solicita la entrada
    scanf("%d",&m);                                     // Escanea la entrada
    printf("El factorial de %d es %ld\n", m, fact(m));  // Valua e imprime
}

long int fact(int n){
    if (n > 1)                                      // Mientras no llegue a 1
    {
        return n * fact(n-1);                       // Agregar a la productoria y restar 1
    }
    else                                            // Si ya llego a 1
    {
        return 1;                                   // Detiene la recursividad
    }
}