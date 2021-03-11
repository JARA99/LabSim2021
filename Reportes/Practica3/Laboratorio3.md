# Práctica 3

Una vez instalados Docker y VS Code, continué con la ejecución del `hello-world` de Docker. Hasta este punto, aunque tengo instaladas las extensiones de Docker ya, aún no me *"funcionan"*, o más bien, aparece como que si no tengo ningún contenedor y Docker no está corriendo. Veré que pasa cuando ya corra el docker del Dockerfile.

## Hello-world

Intenté correr el comando: `docker run 'hello-world`, sin embargo, lo rechazó por falta de permisos. No tuve ningún problema después de agregar el `sudo` antes del comando para darle permisos de administrador, aunque debo admitir que no estaba seguro de hacerlo, ya que con `pip`, cuando se utiliza `sudo`, el mismo instalador recomienda no darle permisos de administrador.

La salida del `hello-world` fue la siguiente:

```
Hello from Docker!
This message shows that your installation appears to be working correctly.

To generate this message, Docker took the following steps:
 1. The Docker client contacted the Docker daemon.
 2. The Docker daemon pulled the "hello-world" image from the Docker Hub.
    (amd64)
 3. The Docker daemon created a new container from that image which runs the
    executable that produces the output you are currently reading.
 4. The Docker daemon streamed that output to the Docker client, which sent it
    to your terminal.

To try something more ambitious, you can run an Ubuntu container with:
 $ docker run -it ubuntu bash

Share images, automate workflows, and more with a free Docker ID:
 https://hub.docker.com/

For more examples and ideas, visit:
 https://docs.docker.com/get-started/
```

## Dockerfile

Realicé el dockerfile como en las instrucciones, con una excepción, agregué un punto más en el directorio, con esperanza de tenerlo más organizado cuando haga más ejercicios en próximos laboratorios. Aunque, pensandolo de nuevo, creo que habrá un dockerfile distinto en cada práctica, y el contenedor es probable que no sea el mismo así que este cambio fue innecesario.

### Explicación del dockerfile:

```
FROM ubuntu:latest
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install -y build-essential
RUN apt-get install -y git htop man vim curl
RUN apt clean
WORKDIR /home/ejercicios/ejercicio1
COPY . /home/ejercicios/ejercicio1
CMD ["bash"]
```

1.  Nos dice la imagen de docker que vamos a utilizar. En este caso UBUNTU. Docker se encarga de descargarla e instalarla en caso de no tenerla.
2.  Todos los comandos `RUN` ejecutan una instrucción de bash. En este caso, actualiza el listado de repositorios
3.  Actualiza los paquetes instalados
4.  Instala el paquete `build-essential`
5.  Instala los paquetes `git` `htop` `man` `vim` y `curl`
6.  Limpia los paquetes y el script de instalación en `/var/cache/apt/archives/`
7.  Se coloca en el directorio `/home/ejercicios/ejercicio1` del contenedor
8.  Copia el contenido ya existente en la carpeta local, a el contenedor, de nuevo, en el directorio `/home/ejercicios/ejercicio1`
9.  CMD provee de parámetros por defecto para correr el contenedor. En este caso, al abrir el docker, correrá una sesión de `bash`. (linux terminal)

### Construyendo el contenedor

Al realizar la instrucción:

```
sudo docker build -t ejdocker:latest .
```

Estoy diciendole a docker que construya el contenedor, con el nombre "ejdocker" , utilizando las configuraciones descritas en el dockerfile que está en el path `.` (esta carpeta).

Debo mencionar que antes de correr el contenedor que acababa de construir, moví toda la carpeta y le cambié de nombre, así que espero que todo funcione bien ahora.


### Docker corriendo

¡Todo bien, todo corrrrrrecto!

Mover la carpeta no afectó para nada, ya está funcionando el contenedor. Me pareció bien raro, por que después del `build` no se agregó ningún archivo, ninguna partición lógica, nada. Sigo sin saber en donde se construyó el contenedor. Pero al parecer, es el nombre que le dí el que reconoce cuando le doy `run`.

Estoy corriendo con la instrucción

```
sudo docker run -it ejdocker bash
```

Y en este punto, la extensión de docker para VS-code aún no encuentra ningún contenedor.

Lo que esta instrucción hace es buscar el contenedor llamado `ejdocker`, correrlo y abrir una terminal en el que se despliega en la terminal local. 

Extrañamente, también después de correr `touch archivo1` y `ls` el archivo se crea efectivamente. Pero al cerrar el contenedor y volverlo a abrir y hacer `ls` el archivo desaparece.

Ahora correré:

```
sudo docker run -it -v PATHLOCAL:/home/ejercicio/ejercicio1 -w /home/ejercicio/ejercicio1 ejdocker bash
```

Esto es diferente en la opcion `-v`, que según la documentación directa del `docker run --help`, que dice:

```
  -v, --volume list                    Bind mount a volume
```

Lo que hace es enlazar el path en el contenedor `/home/ejercicios/ejercicio1` con la carpeta local. Y montar este path a esta carpeta (como cuando insertamos una USB y se monta al sistema en un path específico.)

Aunque pasó algo extraño, yo juraba que se iba a crear el archivo en mi carpeta local también, pero no pasó así. Sin embargo, esta vez si se guardó el archivo en el docker.

Error encontrado, el path en el comando está mal, la segunda carpeta se llama "ejercicios" y no "ejercicio". Segundo intento.

Bueno, no cambió mucho, solo que ahora el dockerfile ya no está, pero el documento sigue sin aparecerme en mi carpeta local. Pensé que pasaría pero no.

Aún no estoy seguro de entender que rayos con Docker la verdad. Guardó los archivos, y cuando cambié el path, los archivos se movieron para allí. No se que rayos la verdad. Pero bueno, continuemos.

## Script de Bash

El [primer script](../../Bash/WeatherReport.sh) ya era suficientemente funcional con tres líneas de código efectivo (sin comentarios), sin embargo, agregué la impresión de unos espacios para que se viera mas limpio. La explicación está en el mismo [código](../../Bash/WeatherReport.sh) en los comentarios.

Para el [segundo script](../../Bash/C_Generator.sh) me llevé algo de más tiempo, pero este lo hice durante la clase, así que ese tiempo no fue contabilizado. Estoy orgulloso del resultado final, sin embargo creo que será mas fácil crear una plantilla en VS-code con la información que ejecutar el script. De nuevo, está explicado vía comentarios (me disculpo por comentar en inglés, pero dicen que es buena práctica, además de evitar el cambio del layer del teclado para comentar.)


**[Volver a la bitácora](../Journal.md)**

**[Volver al README.md](../../README.md)**
