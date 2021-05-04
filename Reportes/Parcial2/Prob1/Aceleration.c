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

int n = 6;
double v[] = {1,3,8,11,14,18};
double t[] = {2.1,3.0,5.2,7.1,9.2,10.1};
double err = 0.1;

int replace = 10;

double tfinal = 15;

///////////////////////////////////////////////////////////////////////
////////////////////////////// Functions //////////////////////////////

double ProdDSum(double a[], double b[]); // Funcion que suma los elementos de dos lists y los multiplica
double SumDProd(double a[], double b[]); // Funcion que multiplica elemento a elemento de dos listas y suma los productos
double Sum(double a[]);
double m();
double b(double m);
double Dm();
double Db();

///////////////////////////////////////////////////////////////////////
////////////////////////////// Main //////////////////////////////

void main(){
    double v;
    // printf("ProdDSum %f y SumDProd %f \n",ProdDSum(v,t),SumDProd(v,t));
    double slope = m();
    printf("a = %f ± %f\n",slope, Dm());
    printf("v(0) = %f ± %f\n",b(slope),Db());
    v = slope*tfinal+b(slope);
    printf("\nv(15) = %f\n",v);
    // printf("g(x) = (%f*x)+(%f)\n",slope,b(slope));
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

double m(){
    double r;
    r = (n*SumDProd(v,t)-ProdDSum(v,t))/(n*SumDProd(t,t)-ProdDSum(t,t));
    return r;
}

double b(double m){
    double r;
    r = (Sum(v)-m*Sum(t))/(n);
    return r;
}

double Dm(){
    double r;
    r = (sqrt(n)*err)/(sqrt(n*SumDProd(t,t)-ProdDSum(t,t)));
    return r;
}

double Db(){
    double r;
    r = err/sqrt(n);
    return r;
}