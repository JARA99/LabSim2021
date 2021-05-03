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

int n = 6;
double v[] = {1,3,8,11,14,18};
double t[] = {2.1,3.0,5.2,7.1,9.2,10.1};

int replace = 10;

///////////////////////////////////////////////////////////////////////
////////////////////////////// Functions //////////////////////////////

double ProdDSum(double a[], double b[]); // Funcion que suma los elementos de dos lists y los multiplica
double SumDProd(double a[], double b[]); // Funcion que multiplica elemento a elemento de dos listas y suma los productos
double Sum(double a[]);
double m();
double b(double m);
// void GPplot(char func[]);

///////////////////////////////////////////////////////////////////////
////////////////////////////// Main //////////////////////////////

void main(){
    // printf("ProdDSum %f y SumDProd %f \n",ProdDSum(v,t),SumDProd(v,t));
    double slope = m();
    // printf("\nm = %f",slope);
    // printf("\nb = %f\n",b(slope));
    printf("g(x) = (%f*x)+(%f)\n",slope,b(slope));
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

// void GPplot(char func[]){

    // FILE * fOrig; // Pointer to the original file
    // FILE * fOutp; // Pointer to the output file
    // char path[100];
    
    // char buffer[BUFFER_SIZE]; //Array of chars where the string read is stored.
    // // char newline[BUFFER_SIZE];
    // int line, count;

    // fOrig  = fopen(path, "r");
    // fOutp = fopen("output.gp", "w"); 

    // line = replace;
    // count = 0;
    // while ((fgets(buffer, BUFFER_SIZE, fOrig)) != NULL)
    // {
    //     count++;

    //     /* If current line is line to replace */
    //     if (count == line)
    //         fputs(func, fOutp);
    //     else
    //         fputs(buffer, fOutp);
    // }

    // fclose(fOrig);
    // fclose(fOutp);
    
    // return;

    /////////////////////////////////////////////////////////////////////

    // FILE * fOrig;
    // FILE * fOutp;
    // char buff[BUFFER_SIZE];

    // fOrig = fopen("v-t.gp", "r");
    // fOutp = fopen("output.gp", "w");
    // fscanf(fOrig, "%s", buff);
    // fputs("This is testing for fputs...\n", fp);
    
    // fprintf(fOrig, "This is testing for fprintf...\n");
    // fputs("This is testing for fputs...\n", fOrig);
    // fclose(fOrig);

// }