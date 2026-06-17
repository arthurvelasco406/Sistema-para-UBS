cmake_minimum_required(VERSION 3.31.6)
project(Sistema___UBS C)
set(CMAKE_C_STANDARD 11)
add_executable(Sistema___UBS main.c
        structs.h
        funcoesImprimir.h
        functions/funcoesImprimir.c
        functions/fila.c
        functions/pilha.c
        functions/lista.c
        functions/funcoes.c
        functions/pilhaTimer.c)