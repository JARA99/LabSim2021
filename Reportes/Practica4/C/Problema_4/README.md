#     Problema_4

>   Crear un programa que solicite al usuario dos matrices de 3x3 almacenarlas como (matA, matB) y una constante, el programa automáticamente debe de mostrar las los siguientes resultados:
> 
> 1.    matA por constante
> 2.    suma de las dos matrices
> 3.    resta de las dos matrices
> 4.    multiplicación de las dos matrices
> 5.    determinante de matA
> 6.    transpuesta de matB
> 7.    inversa de matA
> 8.    reducción de Gauss de maA
> 9.    reducción de Gauss Jordan de matB


##    Documentación para el usuario

Correr el siguiente comando en una terminal:

```bash
gcc Problema_4.c  -lm -o  Problema_4  && ./Problema_4
```

Ingresar de forma ordenada:

*   Los elementos de matriz de la matriz A
*   Los elementos de matriz de la matriz B
*   La constante

Los elementos de matriz están dados de la siguiente forma:

$$
    M = 
    \begin{pmatrix}
        M_{11} & M_{12} & M_{13}\\
        M_{21} & M_{22} & M_{23}\\
        M_{31} & M_{32} & M_{33}\\
    \end{pmatrix}
$$

Y `M_{ij}` = $M_{ij}$.

##    Método

Se realizarán una serie de funciones, algunas generales, como leer la matriz de entrada, o imprimir la matriz de salida. Y otras específicas a cada inciso.

Se solicitarán los elementos de matriz de las dos matrices y la constante, y luego se realizarán los cálculos.

##    Variables

###   Entrada

```c
double MatA[3][3];    // Almacena la matriz A original
double MatB[3][3];    // Almacena la matriz B original
double cte;           // Almacena la constante
```

###   Salida
```c
double M[3][3];       // Almacena temporalmente la matriz a imprimir
```

### Funciones
```c
//Generales
void InputMatrix(char Mat);         // Lee los elementos de matriz y los almacena
void OutputMatrix();                // Imprime la matriz de salida

//Especificas a cada problema
void MatAxCte();                    // Multiplica cada elemento de la matriz A por una contante e imprime
void MatSum();                      // Suma los elementos de matriz de uno en uno
void MatDif();                      // Resta los elementos de matriz de uno en uno
void MatProd();                     // Realiza el producto entre A y B
void DetA();                        // Calcula el determinante de A
void TranspB();                     // Calcula la transupesta de B
void InvA();                        // Calcula la inversa de A
```

###   Otras variables
```c
int i,j;            // Variables locales de conteo
double r;           // Variable local de almacenamiento
```


##    Pseudocódigo
```c
main():
    Imprime mensaje de ingresar constante
    Lee la constante y la almacena
    Imprime mensaje de lectura de elementos de matriz A
    Lee elemento a elemento y almacena
    Imprime mensaje de lectura de elementos de matriz B
    Lee elemento a elemento y almacena
    Calcula las funciones e imprime sus resultados

MatAxCte():
    Multiplica cada elemento de A, por la constante
    Imprime esta nueva matriz

MatSum():
    Suma A[i][j]+B[i][j] y lo almacena en M[i][j]
    Imprime M

MatDif():
    Resta A[i][j]-B[i][j] y lo almacena en M[i][j]
    Imprime M

MatProd():
    M[i][j] = MatA[i][1]*MatB[1][j]+MatA[i][2]*MatB[2][j]+MatA[i][0]*MatB[0][j]
    Imprime M

DetA():
    det = 
        MatA[1][1]*MatA[2][2]*MatA[3][3]
    +   MatA[2][1]*MatA[3][2]*MatA[1][3]
    +   MatA[1][2]*MatA[2][3]*MatA[3][1]
    -   MatA[3][1]*MatA[2][2]*MatA[1][3]
    -   MatA[1][2]*MatA[2][1]*MatA[3][3]
    -   MatA[1][1]*MatA[2][3]*MatA[3][2]
    Imprime det

TranspB():
    M[i][j]=B[j][i]
    Imprime M

InvA();
    a = 1/DetA()
    M[i][j] = a*A[j][i]
    Imprime M
```


##    [Código](Problema_4.c)
