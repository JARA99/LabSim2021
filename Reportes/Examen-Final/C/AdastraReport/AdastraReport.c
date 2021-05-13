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
double dv_dt(double y, double t);         //Ecuacion diferencial dv/dt

//Algebraic functions
double E(double t);     //Funcion E (no se me quedo que es xD)
double F_a(double y);   //Funcion de friccion viscosa
double m_c(double t);   //Funcion de masa
double g(double y);     //Funcion de gravedad
double rho(double t);   //Funcion de densisdad

///////////////////////////////////////////////////////////////////////
///////////////////////////////   Code    /////////////////////////////

void main(){
    Euler();
}

void Euler(){
    //Rango del metodo
    double t_o = 0;                         
    double t_f = 1;

    //Presicion del metodo
    double slice_size = 0.1;
    int slices = (t_f-t_o)/slices;

    //Temporal store variables
    double old_v;
    double v = 0;

    //Archivo de datos
    FILE * vel_dat;
    vel_dat = fopen ("v-t.dat", "w+");

    double t = t_o;
    while (t <= t_f)
    {
        old_v = v;
        v = old_v + (slice_size*dv_dt(old_v, t));
        fprintf(vel_dat, "%E    %E\n", t, v);
        t = t + slice_size;
    }

    fclose(vel_dat);
}


double dv_dt(double y, double t){
    double r = (E(t)-F_a(y)-m_c(t)*g(y))/m_c(t);
    return r;
}