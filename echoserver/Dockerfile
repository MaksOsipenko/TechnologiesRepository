FROM ubuntu:latest

RUN apt-get update 
RUN apt-get -y install g++ 
RUN apt-get -y install qt6-base-dev
RUN apt-get -y install qt6-tools-dev
RUN apt-get -y install make

WORKDIR /catalog 
COPY main.cpp mytcpserver.cpp mytcpserver.h echoserver.pro /catalog 

RUN qmake6
RUN make

EXPOSE 54321

CMD ["./application"]