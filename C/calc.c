/*
Author:        jorgealejandro@superdell-popos
Compiler:      gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
For compile:   gcc calc.c -lm -o  calc
For run:       ./calc
Date:          Tue 06 Apr 2021 11:16:46 AM CST
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

float n1;
float n2;
int state;
int CloseProgram = 0;

void InputData();
void SelectState();
// void Exit();
float Sum();
float Dif();
float Prod();
float Div();


///////////////////////////////////////////////////////////////////////
///////////////////////////      Main        //////////////////////////

void main(){
    while (CloseProgram == 0)
    {
        InputData();
    }
    
}


void InputData(){
    printf("\n");
    printf("    [0] Exit \n");
    printf("    [1] Sum \n");
    printf("    [2] Difference \n");
    printf("    [3] Product \n");
    printf("    [4] Division \n");
    printf("\nSelect an operation type: ");
    scanf("%d",&state);

    SelectState();
}

void SelectState(){
    switch (state)
    {
    case 0:
        CloseProgram = 1;
        break;
    
    case 1:
        printf("\nFirst number: ");
        scanf("%f",&n1);
        printf("Plus:         ");
        scanf("%f",&n2);
        Sum();
        break;
    
    case 2:
        printf("\nFirst number: ");
        scanf("%f",&n1);
        printf("Less:         ");
        scanf("%f",&n2);
        Dif();
        break;

    case 3:
        printf("\nFirst number: ");
        scanf("%f",&n1);
        printf("Times:        ");
        scanf("%f",&n2);
        Prod();
        break;
    
    case 4:
        printf("\nFirst number: ");
        scanf("%f",&n1);
        printf("Divided by:   ");
        scanf("%f",&n2);
        Div();
        break;

    default:
        printf("Enter a number between 0 and 4. \n");
        printf("\nSelect an operation type: ");
        scanf("%d",&state);
        SelectState();
        break;
    }
}

float Sum(){
    float r = n1 + n2;
    printf("\n-----------------------------------------------------------------\n");
    printf("--------- The sum:    %f + %f = %f ---------",n1,n2,r);
    printf("\n-----------------------------------------------------------------\n");
}

float Dif(){
    float r = n1 - n2;
    printf("\n-----------------------------------------------------------------\n");
    printf("----- The difference:    %f - %f = %f ------",n1,n2,r);
    printf("\n-----------------------------------------------------------------\n");

}

float Prod(){
    float r = n1 * n2;
    printf("\n-----------------------------------------------------------------\n");
    printf("------- The product:    %f * %f = %f ------",n1,n2,r);
    printf("\n-----------------------------------------------------------------\n");
}

float Div(){
    float r = n1 / n2;
    printf("\n-----------------------------------------------------------------\n");
    printf("------ The division:    %f / %f = %f ------",n1,n2,r);
    printf("\n-----------------------------------------------------------------\n");
}