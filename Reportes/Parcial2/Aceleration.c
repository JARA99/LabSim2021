/*
Author:        jorgealejandro@superdell-popos
Compiler:      gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
For execute:   gcc Aceleration.c  -o  Aceleration  && ./Aceleration
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

#define BUFFER_SIZE 225

///////////////////////////////////////////////////////////////////////
////////////////////////////// Constant //////////////////////////////

///////////////////////////////////////////////////////////////////////
////////////////////////////// Variables //////////////////////////////

int n = 6;
double v[] = {1,3,8,11,14,18};
double t[] = {2.1,3.0,5.2,7.1,9.2,10.1};

int replace = 10;

///////////////////////////////////////////////////////////////////////
////////////////////////////// Functions //////////////////////////////

double ProdDSum(double a[], double b[]); // Funcion que suma los elementos de dos lists y los multiplica
double SumDProd(double a[], double b[]); // Funcion que multiplica elemento a elemento de dos listas y suma los productos
double Sum(double a[]);
// double m();
// double b(double m);
// void GPplot(char func[]);

///////////////////////////////////////////////////////////////////////
////////////////////////////// Main //////////////////////////////

void main(){
    
}

double ProdDSum(double a[], double b[]){
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

double SumDProd(double a[], double b[]){
    double r = 0;
    
    for (int i = 0; i < n; i++)
    {
        r = r + (a[i] * b[i]);
    }   
    return r;
}

double Sum(double a[]){
    double r = 0;
    for (int i = 0; i < n; i++)
    {
        r = r + a[i];
    }
    return r;
}

