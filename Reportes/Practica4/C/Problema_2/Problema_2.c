/*
Author:        jorgealejandro@superdell-popos
Compiler:      gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
For compile:   gcc Problema_2.c  -lm -o  Problema_2  && ./Problema_2
Date:          Wed 05 May 2021 10:42:18 PM CST
Libraries:     stdio
Abstract:     
Inputs:       
Outputs:      
*/            


///////////////////////////////////////////////////////////////////////
////////////////////////////// Libraries //////////////////////////////

#include <stdio.h>
#include <stdbool.h>

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Constants /////////////////////////////
const int n = 5;

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Variables /////////////////////////////
int list[5];                    //Si uso n como el largo de la lista me da un error :/
// int list[] = {5,2,7,4,9};

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Functions /////////////////////////////

void sort(int l[]);             // Ordena la lista l
int PrintArray(int p[]);        // Imprime la lista p
void inp();                     // Solicita los valores de la lista

///////////////////////////////////////////////////////////////////////
///////////////////////////////   Code    /////////////////////////////

void main(){
    inp();                      // Solicita la lista
    sort(list);                 // Ordena la lista
    PrintArray(list);           // Imprime la lista
}

void sort(int l[]) {            //Metodo burbuja, es bastante autoexplicativo

    int temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (l[j]>l[j+1])
            {
                temp = l[j];
                l[j] = l[j+1];
                l[j+1] = temp;
            }
            
        }
        
    }
    
}

int PrintArray(int p[]){                    
    printf("La lista ordenada es: (");                            //Abre parentesis
    for (int i = 0; i < n-1; i++)             //PAra los primeros 9 elementos
    {
        printf("%d,",p[i]);                 //Imprime el elemento y una coma
    }
    printf("%d",p[n-1]);                      //Imprime el ultimo elemento sin coma
    printf(")\n");                        //Cierra parentesis y dos enter
}

void inp(){
    printf("Ingrese los 5 números enteros que componen la lista a ordenar:\n"); //Solicita los enteros
    for (int i = 0; i < n; i++)
    {
        printf("%d) ", i+1);            // Enumera el entero que se esta solicitando
        scanf("%d",&list[i]);           // Guarda el input
    }
}