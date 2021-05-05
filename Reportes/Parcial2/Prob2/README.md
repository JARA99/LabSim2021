#   Problema 2

>   Utilizando un método numérico, encuentre una raíz de la ecuación
>
>   ```math
>   f(x) = e^{-x^2/2}−0.5
>   ```
>
>   Debe de realizar la gráfica de la ecuación y comparar el resultado obtenido con el programa realizado en C.



##  Documentación para el usuario

En una terminal desde esta carpeta ejecutar el archivo [Exe.sh](Exe.sh):

    ```
        ./Exe.sh
    ```

##  Metodología

Para realizar este problema utilicé el método de bisección, por que, aunque se ve más hambriento de poder, también es más simple, lo que evita código más complejo, y con esto, la documentación también es más sencilla de hacer. En mi caso, no tengo problema con la potencia que va requerir para computarlo relativamente rápido.

##  Plan

Comenzar realizando la gráfica para determinar el intervalo inicial a darle al programa. Y después proceder a correr el programa con este intervalo.

##  Variables de entrada
```c
double FMin          // Menor valor en el intervalo original
double FMax          // Mayor valor en el intervalo original
```
##  Variables de salida
```c
double r            // Raíz del polinomio
```

##  Otras variables

```c
const double MinErr = 1 // Error mínimo admitido
double Min              // Menor valor en el intervalo actual
double Max              // Mayor valor en el intervalo actual
double Med              // Variable para almacenar el valor medio actual entre Min y Max
double r                // [r]oot Varialbe para almacenar el valor actual de la raiz
double l                // [l]ast Varialbe para almacenar el valor anterior de la raiz
```

##  Funciones

```c
void main()             // Funcion inicial
double eval()           // Funcion que realiza las comparaciones evaluaciones
double err()            // Funcion que calcula el error
double f()              // Funcion que emula la funcion matematica
```



## Pseudocódigo general

```
Calcula el valor medio actual
Revisa el error de ese valor
Si el error es mayor a 1, repite
```

## Pseudocódigo explicito
```c
main():
    Min = FMin          // Asigna el intervalo inicial al intervalo variable
    Max = FMax          // Asigna el intervalo inicial al intervalo variable
    l = FMin            // Guarda el valor anterior de la raiz en l
    r = eval()          // Guarda el valor acual de la raiz en r

    while (err()>1)     // Loop para iterar mientras el error no sea menor a 1
        l = r           // Guarda el valor anterior de la raiz en l
        r = eval()      // Guarda el valor acual de la raiz en r
    print(r)            // Imprime la raiz con error menor al 1% al usuario
```

```c
eval():
    Med = (Min+Max)/2       // Evalua el valor medio entre Min y Max actual
    if (f(Med)*f(Min) > 0)  // Compara el signo
        Min = Med           // Remplaza el minimo si tiene el mismo signo
    else
        Max = Med           // Remplaza el maximo si tiene l mismo signo
    
    return Med              // Regresa el valor medio actual
```

```c
err():
    return (r-l)*100/r     // Regresa el valor del error actual
```

```c
f(x):
    return exp(-x^2/2)−0.5  // Regresa el valor de la funcion evaluada en x
```