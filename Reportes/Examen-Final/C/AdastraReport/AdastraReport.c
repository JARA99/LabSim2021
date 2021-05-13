/*
Author:        jorgealejandro@superdell-popos
Compiler:      gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
For compile:   gcc AdastraReport.c  -lm -o  AdastraReport  && ./AdastraReport
Date:          Thu 13 May 2021 10:30:26 AM CST
Libraries:     stdio, math
Abstract:      Create a euler function that output to a .dat file, from those files
Inputs:        none
Outputs:       Rocket name, rocket features, max heigth, no fuel time, crash time
*/            


///////////////////////////////////////////////////////////////////////
////////////////////////////// Libraries //////////////////////////////

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Constants /////////////////////////////


///////////////////////////////////////////////////////////////////////
/////////////////////////////// Variables /////////////////////////////


///////////////////////////////////////////////////////////////////////
/////////////////////////////// Functions /////////////////////////////
// Euler method
void Euler();     //Metodo de euler para la velocidad

//ED functions
double dv_dt();         //Ecuacion diferencial dv/dt

//Algebraic functions
double E(double t);     //Funcion E (no se me quedo que es xD)
double F_a(double y);   //Funcion de friccion viscosa
double m_c(double t);   //Funcion de masa
double g(double y);     //Funcion de gravedad
double rho(double t);   //Funcion de densisdad

///////////////////////////////////////////////////////////////////////
///////////////////////////////   Code    /////////////////////////////

void main(){

}

void Euler(){
    //Rango del metodo
    double t_o = 0;                         
    double t_f = 100;

    //Presicion del metodo
    double slice_size = 0.1;
    int slices = (t_f-t_o)/slices;


}
