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

//Altura inicial carne 201804766

const int h_init = 66;

//Constantes universales

const double G = 6.693E-11;
const double M_T = 5.9736E+24;
const double R_T = 6.378E+6;
const double R = 287.06;
const double L = 6.5E-3;
const double g_0 = 9.81;
const double T_0 = 288.15;
const double P_0 = 101325;

//Constantes de cada cohete

const double E_o[] = {3E+7,2.7E+7,2.5E+7};
const double TSFC[] = {3.248E-4,2.248E-4,2.248E-4};
const double CD[] = {61.27,61.27,70.25};
const double A[] = {201.06,201.06,215};
const double M0[] = {1.1E+5,1.1E+5,1.8E+5};
const double M0_fuel[] = {1.5E+6,1.5E+5,2.1E+6};

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Variables /////////////////////////////

//Numero de cohete, de 0 a 2

int rocket;

//Altura maxima, definida con cero, una vez alcanzada, sustituida
double h_max = 0;
//Tiempo cuando se acaba el gas, difinido como cero
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
void PrintData(int rocket);
void Copy(int rocket);

///////////////////////////////////////////////////////////////////////
///////////////////////////////   Code    /////////////////////////////

void main(){
    for (int  i = 0; i < 3; i++)    //Repetir para cada cohete
    {
        h_max = 0;                  //Resetear altrua
        t_endfuel = 0;              //Resetear altura
        rocket = i;                 //Cohete numero
        PrintData(i);               //Imprimir datos del cohete
        printf("\n");               
        Euler();                    //Calcular datos
        printf("\n\n");
        Copy(i);                    //Copiar datos a carpeta externa
    }
    
    // system("gnuplot ../../Gnuplot/Plots.gp");

}

void Euler(){
    //Rango del metodo
    double t_o = 0;                         
    double t_f = 100;

    //Presicion del metodo
    double slice_size = 0.1;
    // double slice_size = 5;
    int slices = (t_f-t_o)/slices;

    //Temporal store variables
    double old_v;
    double v = 0;
    double old_h = h_init;
    double h = h_init;

    //Archivo de datos
    FILE * hv_dat;
    // FILE * pos_dat;
    hv_dat = fopen ("vh-t.dat", "w+");
    // pos_dat = fopen ("y-t.dat", "w+");
    
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
        fprintf(hv_dat, "%E    %E  %E\n", t, v, h);
        // fprintf(pos_dat, "%E    %E\n", t, h);
        t = t + slice_size;
    }

    fclose(hv_dat);
    // fclose(pos_dat);
}

void Copy(int rocket){
    switch (rocket)                                 //Para cada caso, se almacena una copia de los datos con un nombre distinto
    {
    case 0:
        system("cp vh-t.dat ../../DAT/vh1-t.dat");
        // system("cp y-t.dat ../../DAT/y1-t.dat");
        break;
    case 1:
        system("cp vh-t.dat ../../DAT/vh2-t.dat");
        // system("cp y-t.dat ../../DAT/y2-t.dat");
        break;
    case 2:
        system("cp vh-t.dat ../../DAT/vh3-t.dat");
        // system("cp y-t.dat ../../DAT/y3-t.dat");
        break;
    
    default:                                    //Lamentablemente no se pueden sumar strings diría Alex
        break;
    }
}

void PrintData(int rocket){                     //Imprime los datos por cohete
    switch (rocket)                             //Segun el caso, imprime el nombre
    {  
    case 0:
        printf("Cohete 1: Ah Mun\n");
        break;
    case 1:
        printf("Cohete 2: Ahau Kin\n");
        break;
    case 2:
        printf("Cohete 3: Chac\n");
        break;
    
    default:
        break;
    }

    //Imprime el resto de datos de cada caso

    printf("Empuje del cohete:              %.2EN\n",E_o[rocket]);
    printf("Consumo específico:             %.2EKg/Ns\n",TSFC[rocket]);
    printf("Coeficiente de forma:           %.2E\n",CD[rocket]);
    printf("Sección transversal:            %.2E\nm^2",A[rocket]);
    printf("Masa del propulsor:             %.2E\nKg",M0[rocket]);
    printf("Masa inicial de combustible:    %.2E\nKg",M0_fuel[rocket]);
}

double dv_dt(double v, double h, double t){         //Ecuacion diferencial dv/dt = esta funcion
    double r = (E(t)-F_a(h,v)-m_c(t)*g(h))/m_c(t);
    return r;
    // return h+v-((t+10)*(t+10));
}

int TestData(double t, double h, double old_h){     //Cada loop, revisa se los datos actuales no son importantes para imprimir, y también, analiza si ya toco el suelo y debe parar el loop
    if (h<old_h && h_max == 0)                      //h_max sirve para evitar que esto se siga imprimiendo despues de haber impreso una vez
    {
        printf("La altura máxima alcanzada fue              h = %.2Em\n", old_h);
        h_max = old_h;
    }
    if (m_c(t) == M0[rocket] && t_endfuel == 0)
    {
        printf("El combustible se acaba en el tiempo        t = %.2Es\n", t);
        t_endfuel = t;
    }
    if (h <= 0)
    {
        printf("El cohete choca con el suelo en el tiempo   t = %.2fmin\n", t/60.0);
        return 1;
    }
    return 0;   
}

double E(double t){             //Fuerza de propulsion
    if (m_c(t) == M0[rocket])
    {
        return 0;               //Cero si ya no hay combustible
    }
    else
    {
        return E_o[rocket];     //Constante si hay combustible
    }
    
}     //Funcion E (no se me quedo que es xD)

double F_a(double h, double v){ //Friccion con el aire
    double r = 0.5*rho(h)*CD[rocket]*A[rocket]*v*fabs(v);   //Depende de la densidad, y la velocidad, mas otras constantes
    // printf("F_a es: %E\n",r);
    return r;
}   //Funcion de friccion viscosa

double m_c(double t){   // Masa actual del cohete
    double r = M0_fuel[rocket]-(TSFC[rocket]*E_o[rocket]*t);    //primero calculamos cuanta masa por gas nos queda
    if (r > 0)                                                  //Si no se ha acabado
    {
        r = M0[rocket] + r;                                     //La sumamos a la masa fija
    }
    else
    {
        r = M0[rocket];                                         //Si ya se acabó, solo tenemos la masa fija entonces
    }
    
    return r;
}   //Funcion de masa

double g(double h){     //Gravedad del cohete a cierta altura
    double r = (G*M_T)/(powf(R_T+h,2));       //Depende de la altura actual y de otras constantes.
    return r;
}     //Funcion de gravedad

double rho(double h){       //Densidad del aire a una altura h
    double r;
    if (h <= T_0/L)         //Comprobamos que siga dentro de la atmosfera
    {
        r = (P_0/(R*T_0))*powf((1-((L*h)/T_0)),(g_0/R*L));  //Si esta dentro, entonces calculamos la funcion que mayormente depende de variables
    }
    else
    {
        r = 0;      //Si ya salio de la atmosfera, la densidad es cero.
    }
    // printf("Rho es: %E\n",r);
    return r;
}   //Funcion de densisdad