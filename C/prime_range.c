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

int prime();

///////////////////////////////////////////////////////////////////////
///////////////////////////      Main        //////////////////////////

void main(){

    printf("Enter the first number: ");
    scanf("%d",&n1);
    printf("Enter the second number: ");
    scanf("%d",&n2);

    i = n1;
    for (i; i <= n2; i = i + 1)
    {
        //printf("\n i is: %d\n",i);
        state = prime(i);
        if (state != 0)
        {
            printf("%d, ", i);
        }
        //i = i + 1;
        //state = prime(i);
        //printf("%d",i);
    }
    printf("\n");
}



///////////////////////////////////////////////////////////////////////
///////////////////////////      Prime        //////////////////////////

int prime(int n){
    //printf("Enter a number: ");
    //scanf("%d", &n);
    int j;
    int status;

    //printf("\nenter prime");

    for (j = 2; j < n; j = j + 1){
        if (n%j==0)
        {
            status = 0;
            //break;
            printf("%d", status);
        }
    }
    if (status != 0)
    {
        return 1;
        //printf("\n prime: %d \n",n);
    }
    else {
        return 0;
        //printf("\n no prime: %d \n",n);
    }
}