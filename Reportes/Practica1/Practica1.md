#   Práctica #1
##   Instalación de la maquina virtual
La instalación de la maquina virtual fue sencilla, aunque falló la primera vez, ya que le dí un espacio de almacenamiento muy pequeño.

Sin embargo, la segunda vez todo fue bien. Aunque me sorprendió el tamaño de la ISO, la instalación fue bastante lenta.

Los datos de mi computadora son los siguientes:

![](Graphics/PopOs.png)

Y tras la instalación de Debian en la máquina virtual, y su respectiva clonación tenemos:

![](Graphics/VM.png)

##  Entorno de usuario Shell Bash

### Pidiendo ayuda

Tal vez de los comandos más utilizados en Linux, el `-h` y el `man` me parecen una de las cosas más útiles de Linux, ya que puedo acceder a documentación directa de los desarrolladores sin necesidad de buscarla en un navegador. Es eficiente y rápido.

Algo que aprendí nuevo, es el comando `date`, el cual no había usado antes. Me pareció fascinante que pueda solicitar la fecha de otro día colocando una descripción después de `date -d`.

[![](Graphics/ayuda.svg)](https://asciinema.org/a/391084)

### Instrucciones Básicas

Cuando intente usar el `passwd` intenté poner la misma contraseña por que en realidad no quería cambiarla, y no me dejó, luego intenté poner "1" como contraseña y tampoco me dejó por que era muy corto. Esto fue muy chistoso.

Realicé esto dos veces por que la primera fue muy larga, y al parecer hay un límite para los SVG, así que realicé una más corta pero aún se puede acceder a la larga por este [link](https://asciinema.org/a/391086)

[![](Graphics/InsBas.svg)](https://asciinema.org/a/391087)

### Sistema de archivos

El movimiento entre carpetas utilizando los comandos `ls` y `cd` es bastante útil, aunque es más eficiente cuando uno conoce las locaciones de los directorios.

En esta primera prueba me muevo entre algunas carpetas, creo un directorio nuevo y lo borro, también creo un archivo de texto en blanco.

[![](Graphics/SisArch1.svg)](https://asciinema.org/a/391410)

Para las siguientes pruebas necesitaba un archivo de texto con algunas lineas de texto, así que escribí en el archivo que cree antes unas 16 lineas de código para hacer las pruebas utilizando `vi` (ya que la instalación de VIM se solicita hasta más adelante).

[![](Graphics/HolaMundo.svg)](https://asciinema.org/a/391411)

Con este archivo hago pruebas con los distintos comandos de lectura, en los que se notan diferencias que aunque pueden parecer poco significativas, con archivos de texto más grandes deben ser muy útiles.

También hago movimientos del mismo archivo utilizando comandos distintos.

[![](Graphics/CatMvRm.svg)](https://asciinema.org/a/391414)

Ahora jugamos un poco con los permisos, primero copiando la configuración de la práctica, en la que el usuario tiene permisos de ejecución, lectura y escritura; el grupo solo de lectura y ejecución y otros solo de lectura.

Después pasando a que todos tuvieran permisos de escritura y lectura y por último dejando estos permisos solo al usuario y el resto solo permisos de lectura que es la configuración que tiene más sentido para este tipo de archivo.

Después hice la prueba del `which`, probé con algunos de los comandos aprendidos, y todos resultaron estar en el `/usr/bin/*` en una carpeta con el nombre del comando.

Por último, revisé el historial de comandos, y también intenté revisar solo los últimos 10 items de esta lista, sin embargo no funcionó. Tengo una idea de como intentarlo de nuevo en el siguiente capítulo.

[![](Graphics/Chmod.svg)](https://asciinema.org/a/391420)

### Combinación de instrucciones

Ahora es cuando intentaré realizar la acción de revisar solo los últimos 10 datos del historial, combinando los comandos `history` y `tail`.

Tras haber hecho el intento, no, no funcionó, supongo que tiene que ver con que el comando `tail` necesita un archivo para funcionar y `history` es un comando, no un archivo.

Ahora, intenté combinar otros comandos y con los primeros dos métodos todo fue bien, pero el tercero me costó entender lo que hacía. Y es que en la guía dice *"permite ejecutar **ambas** ordenes aunque la primera falle"*. Sin embargo creo que descubrí que el comando `||` lo que hace es que ejecuta la segunda orden si la primera falla. Esto lo hace mil veces más útil. Por que puedo poner a ejecutar algo, y además tener un respaldo, que si falla, entonces va a hacer otra cosa. Esto es especialmente útil si quiero dejar ejecutando algo muy largo e irme a almorzar.

[![](Graphics/Combi.svg)](https://asciinema.org/a/391424)


###  Grep, ps, kill, find, du

Lo primero que haré será leer los manuales que estos comandos ya traen.
Siempre es mejor aprender probando los comandos y leyendo la documentación más básica, que copiando ejemplos. Vamos a separar esta sección comando por comando:

####  Grep

Leyendo el manual `man grep`, me encontré con que *grep* es una función muy útil cuando se trata de buscar palabras en documentos grandes, ya que lo que hace es leer el documento y lo compara con alguna palabra de entrada. Tiene muchas opciones para filtrar y hacer más específica la búsqueda, solo intenté utilizar uno de ellos, para estas funciones más específicas creo que vale más la pena ir a la [documentación](https://www.gnu.org/software/grep/manual/grep.html) del paquete.
