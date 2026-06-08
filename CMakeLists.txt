cmake_minimum_required(VERSION 4.2)
project(Sistema___UBS C)
set(CMAKE_C_STANDARD 11)
add_executable(Sistema___UBS main.c
        structs.h
        functions/fila.c
        functions/pilha.c
        functions/lista.c
        functions/funcoes.c)