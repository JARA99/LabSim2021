/*
Author:        jorgealejandro@superdell-popos
Compiler:      gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
For compile:   gcc Problema_6.c  -lm -o  Problema_6  && ./Problema_6
Date:          Fri 07 May 2021 11:58:34 AM CST
Libraries:     stdio
Abstract:     
Inputs:       
Outputs:      
*/            


///////////////////////////////////////////////////////////////////////
////////////////////////////// Libraries //////////////////////////////

#include <stdio.h>
#include <math.h>

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Constants /////////////////////////////


///////////////////////////////////////////////////////////////////////
/////////////////////////////// Variables /////////////////////////////

int m;      //A lmacena el entero de ingreso

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Functions /////////////////////////////

// Una funcion para cada inciso:
int a(int n);
double b(int n);
double c(int n);
double d(int n);

///////////////////////////////////////////////////////////////////////
///////////////////////////////   Code    /////////////////////////////

void main(){
    printf("\nIngrese un número entero positivo: ");
    scanf("%d",&m);
    if (m > 1) // Cuando m si es mayor a 1, imprime todo
    {
        printf("\nPara los distintos incisos tenemos:\na) %d\nb) %f\nc) %f\nd) %f\n\n",a(m),b(m),c(m),d(m));
    }
    else if (m == 1){ //Excepcion de b y c
        printf("\nPara los distintos incisos tenemos:\na) %d\nb) Elija un n > 1\nc) %f\nd) Elija un n > 1\n\n",a(m),c(m));
    }
    else{   //No imprime calcula nada, solicita un enter MAYOR a 0
        printf("\nEl número debe ser mayor a 0.");
        main();
    }
}

int a(int n){
    // printf("\nin a");
    int r = 0;                      // Variable de sumas recursivas
    for (int i = 1; i <= n; i++)
    {
        r = r + ((i*i)*(i-3));      // Forma de la funcion a sumar de forma recursiva
        // printf("r = %d\n",r);
    }
    return r;
}

double b(int n){
    // printf("\nin b");
    double r = 0;                      // Variable de sumas recursivas
    for (int i = 2; i <= n; i++)
    {
        r = r + 3/(i-1);      // Forma de la funcion a sumar de forma recursiva
    }
    return r;
}

double c(int n){
    // printf("\nin c");
    double sq = sqrt(5);
    double r = 0;                      // Variable de sumas recursivas
    for (int i = 1; i <= n; i++)
    {
        r = r + (1/sq)*(pow((1+sq)/2,i)-pow((1-sq)/2,i));      // Forma de la funcion a sumar de forma recursiva
        // printf("\nsqrt5=%f",sqrt(5));
    }
    return r;
}

double d(int n){
    // printf("\nin d");
    double r = 0;                      // Variable de sumas recursivas
    for (int i = 2; i <= n; i++)
    {
        r = r + 0.1*(3*pow(2,i-2)+4);      // Forma de la funcion a sumar de forma recursiva
    }
    return r;
}
