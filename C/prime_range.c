/*
Author:        jorgealejandro@superdell-popos
Compiler:      gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
For compile:   gcc prime_range.c  -o  prime_range
Date:          Fri 19 Mar 2021 06:43:09 PM CST
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

int n1;
int n2;
int i;
int state = 1;

void prime();

///////////////////////////////////////////////////////////////////////
///////////////////////////      Main        //////////////////////////

void main(){
    printf("Enter the lower number: ");
    scanf("%d",&n1);
    printf("Enter the higher number: ");
    scanf("%d",&n2);

    printf("\n The interval is [%d,%d]\n",n1,n2);

    i = n1;

    for ( i; i <= n2; i++)
    {
        prime();

        if (state == 1)
        {
            printf("%d, ", i);
        }        
    }
    printf("\n");
}



///////////////////////////////////////////////////////////////////////
///////////////////////////      Prime        //////////////////////////

void prime(){
    int j =2;
    state = 1;

    for (j = 2; j < i; j++)
    {
        if (i%j == 0)
        {
            state = 0;
            break;
        }
    }
}