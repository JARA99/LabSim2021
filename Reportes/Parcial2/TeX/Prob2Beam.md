Problema 2
==========

### Metodología

Para realizar este problema utilicé el método de bisección, por que,
aunque se ve más hambriento de poder, también es más simple, lo que
evita código más complejo, y con esto, la documentación también es más
sencilla de hacer.

\<2\>

<span>Plan</span> Comenzar realizando la gráfica para determinar el
intervalo inicial a darle al programa. Y después proceder a correr el
programa con este intervalo.

### Programación

<span>Funciones principales</span>

-   main(): Ejecuta iteraciones hasta minimizar el error a 1%. Despues
    imprime la raiz

-   eval(): Calcula el punto medio del intervalo actual, y devuelve un
    nuevo intervalo

-   err(): Calcula el error del punto medio actual

<span>Funciones secundarias</span>

-   f(x): Función que emula la función matemática propuesta

### Automatización

A diferencia del problema 1, aquí no había mucho que automatizar, así
que la automatización es solamente un script de bash que compila y
ejecuta el código en C, y la gráfica en gnuplot, y después de imprimir
la raíz en la terminal, abre el pdf con la gráfica (válido solo para
gnome).
