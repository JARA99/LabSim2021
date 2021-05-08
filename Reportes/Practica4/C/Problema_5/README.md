#     Problema_5

> Crear un programa que encuentre el factorial de un numero entero ingresado, debe de utilizar una función recursiva.

##    Documentación para el usuario

Correr el siguiente comando en una terminal:

```bash
gcc Problema_5.c  -lm -o  Problema_5  && ./Problema_5
```

Ingresar un entero para calcular su factorial.

##    Método

Se realizará una función recursiva que calcule el factorial de una variable, se solicitará una entrada, y se almacenará en la variable a la que se le aplicará esta función.

##    Variables

###   Entrada

```c
int m;          //Almacena el entero de entrada
```

###   Salida

```c
long int r;     //Almacena el entero de salida
```

##    Pseudocódigo

```c
main():
    Solicitar entero n
    Ejecutar función fac(n)
    Imprimir el resultado

fac(n):
    Si n > 1:
        regresar n*fac(n)
    Otro caso:
        regresar 1
```

##    [Código](Problema_5.c)
