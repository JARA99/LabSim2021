/*
Author:        jorgealejandro@superdell-popos
Compiler:      gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
For compile:   gcc Problema_1.c  -lm -o  Problema_1  && ./Problema_1
Date:          Wed 05 May 2021 04:15:16 PM CST
Libraries:     stdio
Abstract:     
Inputs:       
Outputs:      
*/            


///////////////////////////////////////////////////////////////////////
////////////////////////////// Libraries //////////////////////////////

#include <stdio.h>


///////////////////////////////////////////////////////////////////////
/////////////////////////////// Constants /////////////////////////////


///////////////////////////////////////////////////////////////////////
/////////////////////////////// Variables /////////////////////////////
int a[] = {2,4,6,8,10,12,14,16,18,20};      //Lista ascendente
int d[] = {20,18,16,14,12,10,8,6,4,2};      //Lista descendente
int state = 0;                              //Variable para determinar si ya se ingreso un valor aceptado
char input;                                 //Variable para almacenar la entrada

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Functions /////////////////////////////

int loop();                                 //Loop de comparación   
int PrintArray(int p[]);                    //Funcion para imprimir cada elemento en el array

///////////////////////////////////////////////////////////////////////
///////////////////////////////   Code    /////////////////////////////

void main(){
    while (state == 0)                      //Mientras el usuario no ingrese a o d
    {
        printf("\nSeleccione un tipo de ordenación: [a]scendente/[d]scendente:  "); //Imprimir instruccion
        scanf("%s",&input);                 //Leer la entrada
        printf("\n");                       //Imprimir un enter
        state = loop();                     //Actualizar el estado
    }
    
    // loop();
}

int loop(){
    if (input == 'a')                       //Si el usuario ingresa a
    {
        PrintArray(a);                      //Imprime la lista ascendente
        return 1;                           //Actualiza el estado
    }
    // else if (input == 'ascendente')
    // {
    //     PrintArray(a);
    // }    
    else if (input == 'd')                   //Si el usuario ingresa d
    {
        PrintArray(d);                       //Imprime descendente
        return 1;                            //Actualiza el estado
    }
    // else if (input == 'descendente')
    // {
    //     PrintArray(d);
    // }
    else                                    //Cualquier otro caso
    {
        return 0;                           //Mantiene el estado
    }
}

int PrintArray(int p[]){                    
    printf("(");                            //Abre parentesis
    for (int i = 0; i < 9; i++)             //PAra los primeros 9 elementos
    {
        printf("%d,",p[i]);                 //Imprime el elemento y una coma
    }
    printf("%d",p[9]);                      //Imprime el ultimo elemento sin coma
    printf(")\n\n");                        //Cierra parentesis y dos enter
}