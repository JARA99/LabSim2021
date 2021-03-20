/*
Author:        jorgealejandro@superdell-popos
Compiler:      gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
For compile:   gcc prime.c  -o  prime
Date:          Fri 19 Mar 2021 06:30:04 PM CST
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

int n;
int i = 2;
int state = 1;

///////////////////////////////////////////////////////////////////////
///////////////////////////      Main        //////////////////////////
//sp not you

void main(){
    printf("Enter a number: ");
    scanf("%d", &n);
    for (i = 2; i < n; i = i + 1){
        if (n%i==0)
        {
            state = 0;
            break;
        }
    }
    if (state != 0)
    {
        printf("\n      Si es primo \n\n");
    }
    else {
        printf("\n      No es primo \n\n");
    }
}