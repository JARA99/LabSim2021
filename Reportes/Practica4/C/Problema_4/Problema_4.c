/*
Author:        jorgealejandro@superdell-popos
Compiler:      gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
For compile:   gcc Problema_4.c  -lm -o  Problema_4  && ./Problema_4
Date:          Fri 07 May 2021 11:20:19 AM CST
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

const int dim = 3;

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Variables /////////////////////////////
double MatA[3][3];      //input matrix A
double MatB[3][3];      //input matrix B
double A[3][3];         //output matrix A
double B[3][3];         //output matrix B
double cte;             //input constant

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Functions /////////////////////////////
void InputMatrix(char Mat);
void OutputMatrix(char Mat);
void MatAxCte();

///////////////////////////////////////////////////////////////////////
///////////////////////////////   Code    /////////////////////////////

void main(){
    scanf("%lf",&cte);
    InputMatrix('A');
    MatAxCte();
}

void InputMatrix(char Mat){
    switch (Mat)
    {
    case 'A':
        printf("\nIngrese los elementos de matriz de la matriz A:\n\n");    //Instruccion general
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                printf("A_{%d%d} = ",i,j);                  //Que elemento se esta almacenando
                scanf("%lf",&MatA[i][j]);                   //Guarda el elemento en la matriz original
            }
            
        }
        for (int i = 0; i < dim; i++){
            for (int j = 0; j < dim; j++){
                A[i][j] = MatA[i][j];                       //Copia esta matriz en la salida A para imprimirla
            }
        }
        //Imprime la matriz
        printf("\n");
        printf("A = ");
        OutputMatrix('A');
        printf("\n");
        break;
    
    case 'B':
        printf("\nIngrese los elementos de matriz de la matriz B:\n\n");    //Instruccion general
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                printf("B_{%d%d} = ",i,j);                  //Que elemento se esta almacenando
                scanf("%lf",&MatB[i][j]);                   //Guarda el elemento en la matriz original
            }
            
        }
        for (int i = 0; i < dim; i++){
            for (int j = 0; j < dim; j++){
                B[i][j] = MatB[i][j];                       //Copia esta matriz en la salida B para imprimirla
            }
        }
        //Imprime la matriz
        printf("\n");
        printf("B = ");
        OutputMatrix('B');
        printf("\n");
        break;

    default:
        break;
    }
    
}

void OutputMatrix(char Mat){
    switch (Mat)
    {
    case 'A':                                   //Si quiero imprimir la matriz A
        printf("\n");                           //Enter para separacion
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                printf("    %f  ",A[i][j]);  //Imprimir los elementos de matriz de una misma linea
            }
            printf("\n");                       //Enter y cambio de linea
        }
        printf("\n");                           //Enter para separacion
        break;
    
    case 'B':                                   //Caso en el que quiero imprimir la matriz B
        printf("\n");                           
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                printf("    %f  ",B[i][j]);  //Programa identico, solo cambia la matriz
            }
            printf("\n");
        }
        printf("\n");
        break;
    
    default:
        break;
    }
}

void MatAxCte(){
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            A[i][j] = MatA[i][j]*cte;
        }
        
    }
    printf("La matriz A por la constante es: ");
    OutputMatrix('A');
}

void MatSum(){
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            A[i][j] = MatA[i][j]+MatB[i][j];
        }
        
    }
    printf("La matriz A + B es: ");
    OutputMatrix();
}