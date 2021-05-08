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
// double A[3][3];         //output matrix A
// double B[3][3];         //output matrix B
double cte;             //input constant
double M[3][3];

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Functions /////////////////////////////
//Generales
void InputMatrix(char Mat);
void OutputMatrix();

//Especificas a cada problema
void MatAxCte();
void MatSum();
void MatDif();
void MatProd();
void DetA();
void TranspB();
void InvA();

///////////////////////////////////////////////////////////////////////
///////////////////////////////   Code    /////////////////////////////

void main(){
    //Escanear entradas
    printf("Ingrese la constante: ");
    scanf("%lf",&cte);
    InputMatrix('A');
    InputMatrix('B');

    //Operar e imprimir salidas
    MatAxCte();
    MatSum();
    MatDif();
    MatProd();
    DetA();
    TranspB();
    InvA();
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
                M[i][j] = MatA[i][j];                       //Copia esta matriz en la salida A para imprimirla
            }
        }
        //Imprime la matriz
        printf("\n");
        printf("A = ");
        OutputMatrix();
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
                M[i][j] = MatB[i][j];                       //Copia esta matriz en la salida B para imprimirla
            }
        }
        //Imprime la matriz
        printf("\n");
        printf("B = ");
        OutputMatrix();
        printf("\n");
        break;

    default:
        break;
    }
    
}

void OutputMatrix(){
    printf("\n");                           //Enter para separacion
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            printf("    %.2f  ",M[i][j]);  //Imprimir los elementos de matriz de una misma linea
        }
        printf("\n");                       //Enter y cambio de linea
    }
    printf("\n");                           //Enter para separacion
        
}

void MatAxCte(){
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            M[i][j] = MatA[i][j]*cte;
        }
        
    }
    printf("La matriz A por la constante es: ");
    OutputMatrix();
}

void MatSum(){
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            M[i][j] = MatA[i][j]+MatB[i][j];
        }
        
    }
    printf("La matriz A + B es: ");
    OutputMatrix();
}

void MatDif(){
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            M[i][j] = MatA[i][j]-MatB[i][j];
        }
    }
    printf("La matriz A - B es: ");
    OutputMatrix();
}

void MatProd(){
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            M[i][j] = MatA[i][1]*MatB[1][j]+MatA[i][2]*MatB[2][j]+MatA[i][0]*MatB[0][j];
            // printf("M[%d][%d] = %lf",i,j,M[i][j]);
        }
        
    }
    printf("El producto AB es: ");
    OutputMatrix();
}

void DetA(){
    double r = 0;
    r = MatA[1][1]*MatA[2][2]*MatA[3][3]
    +   MatA[2][1]*MatA[3][2]*MatA[1][3]
    +   MatA[1][2]*MatA[2][3]*MatA[3][1]
    -   MatA[3][1]*MatA[2][2]*MatA[1][3]
    -   MatA[1][2]*MatA[2][1]*MatA[3][3]
    -   MatA[1][1]*MatA[2][3]*MatA[3][2];

    printf("El determinante de A es: %lf\n\n",r);
}

void TranspB(){
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            M[i][j] = MatB[j][i];
        }
        
    }
    
    printf("La transpuesta de B es: ");
    OutputMatrix();
}

void InvA(){
    double r = 0;
    r = MatA[1][1]*MatA[2][2]*MatA[3][3]
    +   MatA[2][1]*MatA[3][2]*MatA[1][3]
    +   MatA[1][2]*MatA[2][3]*MatA[3][1]
    -   MatA[3][1]*MatA[2][2]*MatA[1][3]
    -   MatA[1][2]*MatA[2][1]*MatA[3][3]
    -   MatA[1][1]*MatA[2][3]*MatA[3][2];

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            M[i][j] = (1/r)*MatA[j][i];
        }
        
    }
    

    printf("La inversa de A es: ");
    OutputMatrix();
}

//Antiguo codigo de ingreso (descartado):
// void OutputMatrix(char Mat){
//     switch (Mat)
//     {
//     case 'A':                                   //Si quiero imprimir la matriz A
//         printf("\n");                           //Enter para separacion
//         for (int i = 0; i < dim; i++)
//         {
//             for (int j = 0; j < dim; j++)
//             {
//                 printf("    %f  ",A[i][j]);  //Imprimir los elementos de matriz de una misma linea
//             }
//             printf("\n");                       //Enter y cambio de linea
//         }
//         printf("\n");                           //Enter para separacion
//         break;
    
//     case 'B':                                   //Caso en el que quiero imprimir la matriz B
//         printf("\n");                           
//         for (int i = 0; i < dim; i++)
//         {
//             for (int j = 0; j < dim; j++)
//             {
//                 printf("    %f  ",B[i][j]);  //Programa identico, solo cambia la matriz
//             }
//             printf("\n");
//         }
//         printf("\n");
//         break;
    
//     default:
//         break;
//     }
// }