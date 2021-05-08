#     Problema_6

> Crear un programa que realice la sumatoria desde 1 hasta un número n que ingrese el usuario de las siguientes funciones.
> 
>   $$
>       \sum^n_{k=1} k^2(k-3) \tag{a}
>   $$
> 
>   $$
>       \sum^n_{k=1} \frac{3}{k-1} \tag{b}
>   $$
>
>   $$
>       \sum^n_{k=1} \frac{1}{\sqrt{5}}\left(\frac{1+\sqrt{5}}{2}\right)^n-\frac{1}{\sqrt{5}}\left(\frac{1-\sqrt{5}}{2}\right)^n \tag{c}
>   $$
> 
>   $$
>       \sum^n_{k=2} 0.1\left(3*2^{k-2}+4\right)\tag{d}
>   $$


##    Documentación para el usuario

Correr el siguiente comando en una terminal:

```bash
gcc Problema_6.c  -lm -o  Problema_6  && ./Problema_6
```

Ingresar un entero para calcular las distintas sucesiones de 1 o 2 hasta este entero.

##    Método

Solicitar el entero n, realizar una función para cada sumatoria, que contenga un for desde 1 o 2 (dependiendo de la sumatoria) hasta n.

Una observación importante, es que la ecuación (b) se indetermina en el primer término, por tanto, la sumatoria se tomará desde 2 hasta n.

Por último, imprimir los valores de las sumas de manera ordenada, y se agregó un detalle, cuando el número es menor a 1, se solicita de nuevo un número, aclarando que debe ser mayor a 0.

##    Variables

###   Entrada

```c
int m;          //Almacena el entero de entrada
```

###   Salida

```c
// Aunque son funciones, son las encargadas de generar y almacenar las salidas. 
int a(int n);       //Salida del problema a
double b(int n);    //Salida del problema b
double c(int n);    //Salida del problema c
double d(int n);    //Salida del problema d
```

##    Pseudocódigo

```c
main():
    Solicitar un entero
    Leer y almacenar el entero
    Determinar si es menor a 1, igual a 1 o mayor a 1

        Si es mayor a 1
            Imprimir los resultados de las funciones a,b,c,d de forma ordenada
        Si es igual a 1
            Imprimir los resultados de las funciones a y c de forma ordenada
            Aclarar que par b y d se necesita un n > 1
        Si es menor a 1
            Solicitar un entero mayor a 1
            Leer y almacenar el entero
```

Para `a()`, `b()`, `c()` y `d()` se usa una estructura parecida, pero se aplica la función de cada inciso:

```c
F(n):
    Declarar una variable local r
    Mientras i <= n, loop y suma 1 a i:
        r = r + f(i)
    regresar r
```

Con `f()` la función matemática del problema en cuestión.

##    [Código](Problema_6.c)
