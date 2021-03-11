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

Explicación del dockerfile:

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

Debo mencionar que antes de correr el contenedor que acababa de construir, moví toda la carpeta y le cambié de nombre, así que espero que todo funcione bien ahora.



