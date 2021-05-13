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

const int h_init = 66;

const double E_o[] = {3E+7,2.7E+7,2.5E+7};
const double TSFC[] = {3.248E-4,2.248E-4,2.248E-4};
const double CD[] = {61.27,61.27,70.25};
const double Trans[] = {201.06,201.06,215};
const double M0[] = {1.1E+5,1.1E+5,1.8E+5};
const double M0_fuel[] = {1.5E+6,1.5E+5,2.1E+6};

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Variables /////////////////////////////

int rocket = 1;

double h_max = 0;
double t_endfuel = 0;

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Functions /////////////////////////////
// Euler method
void Euler();                                       //Metodo de euler para la velocidad y la posicion

//ED functions
double dv_dt(double y, double h, double t);         //Ecuacion diferencial dv/dt

//Algebraic functions
double E(double t);                                 //Funcion E (no se me quedo que es xD)
double F_a(double h, double v);                     //Funcion de friccion viscosa
double m_c(double t);                               //Funcion de masa
double g(double h);                                 //Funcion de gravedad
double rho(double t);                               //Funcion de densisdad

//Other functions
int TestData(double t, double h, double old_h);     //Esta función analiza los datos actuales, y verifica si alguo es de los datos importantes. Retorna cuando el cohete choca.

///////////////////////////////////////////////////////////////////////
///////////////////////////////   Code    /////////////////////////////

void main(){
    printf("Cohete 1: Ah Mun");
    Euler();
}

void Euler(){
    //Rango del metodo
    double t_o = 0;                         
    double t_f = 100;

    //Presicion del metodo
    double slice_size = 0.1;
    int slices = (t_f-t_o)/slices;

    //Temporal store variables
    double old_v;
    double v = 0;
    double old_h = h_init;
    double h = h_init;

    //Archivo de datos
    FILE * vel_dat;
    FILE * pos_dat;
    vel_dat = fopen ("v-t.dat", "w+");
    pos_dat = fopen ("y-t.dat", "w+");
    
    //Metodo de euler
    double t = t_o;
    while (TestData(t,h,old_h) == 0)
    // while (t <= t_f)
    {   
        //Almacenar el valor antiguo de v y h
        old_v = v;
        old_h = h;
        //Valuar el nuevo valor de v y h
        v = old_v + (slice_size*dv_dt(old_v, old_h, t));
        h = old_h + (slice_size*v);
        //Inprimir en el archivo
        fprintf(vel_dat, "%E    %E\n", t, v);
        fprintf(pos_dat, "%E    %E\n", t, h);
        t = t + slice_size;
    }

    fclose(vel_dat);
    fclose(pos_dat);
}


double dv_dt(double v, double h, double t){
    // double r = (E(t)-F_a(h,v)-m_c(t)*g(h))/m_c(t);
    // return r;
    return h+v-((t+10)*(t+10));
}

int TestData(double t, double h, double old_h){
    if (h<old_h && h_max == 0)
    {
        printf("La altura máxima alcanzada fue %.2Em\n", old_h);
        h_max = old_h;
    }
    if (m_c(t) <= M0[rocket] && t_endfuel == 0)
    {
        printf("El combustible se acaba en el tiempo t = %.2Es\n", t);
        t_endfuel = t;
    }
    if (h <= 0)
    {
        printf("El cohete choca con el suelo en el tiempo t = %.2Es\n",old_h);
        return 1;
    }
    return 0;   
}

double E(double t){
    if (m_c(t) <= M0[rocket])
    {
        return 0;
    }
    else
    {
        return E_o[rocket];
    }
    
}     //Funcion E (no se me quedo que es xD)

double F_a(double h, double v){
    double r = 0.5*rho(h);
}   //Funcion de friccion viscosa
double m_c(double t){
    return 8.2-t;
}   //Funcion de masa

double g(double h);     //Funcion de gravedad
double rho(double t);   //Funcion de densisdad