/*
Author:        jorgealejandro@superdell-popos
Compiler:      gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
For compile:   gcc heights.c  -o  heights
Date:          Fri 19 Mar 2021 05:31:59 PM CST
Libraries:     stdio
Abstract:     
Inputs:       
Outputs:      
*/            


///////////////////////////////////////////////////////////////////////
////////////////////////////// Libraries //////////////////////////////

#include <stdio.h>


///////////////////////////////////////////////////////////////////////
/////////////////////////// Declarations   //////////////////////////

int n = 1;
float sum = 0;
float max;
float min;
float med;
float x;

///////////////////////////////////////////////////////////////////////
///////////////////////////      Main        //////////////////////////

void main(){

    printf("Enter a height: ");
    scanf("%f", &x);

    max = x;
    min = x;

    while (x >= 0){
        n = n + 1;
        sum = sum + x;
        (x>max)? max = x: 0;
        (x<min)? min = x: 0;

        printf("Enter a height: ");
        scanf("%f", &x);
    }

    med = sum/n ;

    if (n==0)
    {
        printf("No positive input");
    }
    else
    {
        printf("\n Med: %f \n Max: %f \n Min: %f \n",med,max,min);
    }
    
}


///////////////////////////////////////////////////////////////////////
///////////////////////////   Functions   //////////////////////////