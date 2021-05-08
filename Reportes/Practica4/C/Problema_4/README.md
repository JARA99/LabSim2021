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
double A[3][3];       // Almacena temporalmente la matriz A a imprimir
double B[3][3];       // Almacena temporalmente la matriz B a imprimir
```


###   Otras variables



##    Pseudocódigo



##    [Código](Problema_4.c)
