/*
Author:        jorgealejandro@superdell-popos
Compiler:      gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
For compile:   gcc Problema_3.c  -lm -o  Problema_3  && ./Problema_3
Date:          Wed 05 May 2021 11:45:43 PM CST
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

const int n = 3;

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Variables /////////////////////////////

int v[3];
int w[3];

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Functions /////////////////////////////
void inp();
double mag(int vec[]);
void sum();
void p_dot();
void p_times();
int PrintArray(int p[]);

///////////////////////////////////////////////////////////////////////
///////////////////////////////   Code    /////////////////////////////

void main(){
    inp();
    printf("\n");
    printf("La magnitud del primer vector es: %f\n",mag(v));
    printf("La magnitud del segundo vector es: %f\n",mag(w));
    sum();
    p_dot();
    p_times();
    printf("\n");
}

void inp(){
    printf("Ingrese los 3 números enteros que componen el primer vector:\n"); //Solicita los enteros
    for (int i = 0; i < n; i++)
    {
        printf("%d) ", i+1);            // Enumera el entero que se esta solicitando
        scanf("%d",&v[i]);           // Guarda el input
    }

    printf("Ingrese los 3 números enteros que componen el segundo vector:\n"); //Solicita los enteros
    for (int i = 0; i < n; i++)
    {
        printf("%d) ", i+1);            // Enumera el entero que se esta solicitando
        scanf("%d",&w[i]);           // Guarda el input
    }
}

double mag(int vec[]){
    double magnitude;
    magnitude = sqrt(vec[0]^2+vec[1]^2+vec[2]^2);
    return magnitude;
}

void sum(){
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i]=v[i]+w[i];
    }
    printf("La suma es: ");
    PrintArray(temp);
}

void p_dot(){
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = temp + v[i]*w[i];
    }
    printf("El producto punto es: %d\n",temp);
}
    
void p_times(){
    int temp[n];
    temp[0] = v[1]*w[2]-v[2]*w[1];
    temp[1] = -v[0]*w[2]+v[2]*w[0];
    temp[2] = v[0]*w[1]-v[1]*w[0];
    printf("El producto cruz es: ");
    PrintArray(temp);
}

int PrintArray(int p[]){                    
    printf("(");                            //Abre parentesis
    for (int i = 0; i < n-1; i++)             //PAra los primeros 9 elementos
    {
        printf("%d,",p[i]);                 //Imprime el elemento y una coma
    }
    printf("%d",p[n-1]);                      //Imprime el ultimo elemento sin coma
    printf(")\n");                        //Cierra parentesis y dos enter
}