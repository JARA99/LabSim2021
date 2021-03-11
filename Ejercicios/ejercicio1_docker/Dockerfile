FROM ubuntu:latest
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install -y build-essential
RUN apt-get install -y git htop man vim curl
RUN apt clean
WORKDIR /home/ejercicios/ejercicio1
COPY . /home/ejercicios/ejercicio1
CMD ["bash"]