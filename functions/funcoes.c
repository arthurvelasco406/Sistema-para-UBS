#include "../structs.h"

/* ============================================================
 * ALGORITMO DE BUSCA — Binária
 * ============================================================ */

/*
 * IMPORTANTE: a busca binária exige que o vetor esteja ordenado.
 * Antes de chamar buscaBinaria(), ordenar o vetor com Bubble Sort.
 */

/* Busca sequencial por senha — percorre elemento a elemento */
int buscaSequencial(Cliente vet[], int n, int senha) {
    /* TODO: implementar */
    /* G02/G09: contar e exibir o número de comparações */
    return -1; /* retorna índice ou -1 se não encontrado */
}

/* Busca binária por senha — exige vetor ordenado */
int buscaBinaria(Cliente vet[], int n, int senha) {
    int low = 0, high = n - 1;
    /* TODO: implementar */
    /* G04/G10: exibir número de comparações realizadas */
    return -1; /* retorna índice ou -1 se não encontrado */
}


/* ============================================================
 * ALGORITMO DE ORDENAÇÃO — Bubble Sort
 * ============================================================ */

/* Ordena vetor de clientes por número de senha (crescente) */
void ordenar(Cliente vet[], int n) {
    /*
     * TODO: implementar Bubble Sort
     */
}


/* ============================================================
 * RELATÓRIO
 * ============================================================ */

/* Gera relatório de atendimentos ordenado */
void gerarRelatorio(Cliente historico[], int n) {
    /* TODO:
     * 1. Copiar histórico para vetor auxiliar
     * 2. Ordenar com Bubble Sort
     * 3. Exibir
     */
}


/* ============================================================
 * REQUISITO ÚNICO DO GRUPO G07
 * ============================================================ */

/*
 * Dois tipos de fila intercalados: fila normal e prioritária; regra de chamada: 1 prioritário a cada 2 normais.
 * TODO: implementar a função (ou funções) necessárias aqui.
 */
