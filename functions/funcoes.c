#include <stdbool.h>
#include <string.h>

#include "stdio.h"
#include "../structs.h"
#include "../funcoesImprimir.h"
/* ============================================================
 * ALGORITMO DE BUSCA — Binária
 * ============================================================ */

/*
 * IMPORTANTE: a busca binária exige que o vetor esteja ordenado.
 * Antes de chamar buscaBinaria(), ordenar o vetor com Bubble Sort.
 */

/* Busca binária por senha — exige vetor ordenado */
int buscaBinaria(Cliente vet[], int n, int senha) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low+high) / 2;
        if (vet[mid].senha == senha) {
            return mid;
        } else if (vet[mid].senha < senha) {
            low = mid + 1;
        } else {
            high = mid -1;
        }
    }
    return -1;
}


/* ============================================================
 * ALGORITMO DE ORDENAÇÃO — Bubble Sort
 * ============================================================ */

/* Ordena vetor de clientes por número de senha (crescente) */
void ordenar(Cliente vet[], int n) {
    Cliente aux;
    for (int i =0; i < n -1; i++) {

        for (int j = 0; j < i;j++) {
            if (vet[j].senha > vet[j+1].senha) {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}
void ordenarPorTempo(PilhaTimer *p, int n) {
    AtendimentoTimer aux;
    for (int i = 0; i < p->topo - 1; i++) {
        for (int j = 0; j < p->topo - 1 - i; j++) {
            if (p->itens[j].tempo > p->itens[j+1].tempo) {
                aux          = p->itens[j];
                p->itens[j]   = p->itens[j+1];
                p->itens[j+1] = aux;
            }
        }
    }
}


/* ============================================================
 * RELATÓRIO
 * ============================================================ */

/* Gera relatório de atendimentos ordenado */
void gerarRelatorio(PilhaTimer *p) {
    if (pilhaTimerVazia(p)) {
        printf("\n\xC9");
        for(int i = 0; i < 68; i++) printf("\xCD");
        printf("\xBB\n");
        imprimirCentroLinha("RELATORIO DE ATENDIMENTOS",68);
        printf("\xBA");
        for(int i = 0; i < 68; i++) printf("\xC4");
        printf("\xBA\n");
        imprimirCentroLinha(" Nenhum atendimento registrado.",68);
        printf("\xC8");
        for(int i = 0; i < 68; i++) printf("\xCD");
        printf("\xBC\n");
        return;
    }

    ordenarPorTempo(p, p->topo);

    printf("\n\xC9");
    for(int i = 0; i < 68; i++) printf("\xCD");
    printf("\xBB\n");
        imprimirCentroLinha("RELATORIO DE ATENDIMENTOS",68);
    printf("\xBA");
    for(int i = 0; i < 68; i++) printf("\xC4");
    printf("\xBA\n");

    for (int i = 0; i < p->topo; i++) {
        char prioridade[12] = "Normal";
        if (p->itens[i].cliente.prioritario == 1) strcpy(prioridade, "Urgencia");
        char linha[64];
        snprintf(linha, sizeof(linha), " [%03d] %-15s Prioridade: [%s] Tempo: %.2fs",
            p->itens[i].cliente.senha,
            p->itens[i].cliente.nome,
            prioridade,
            p->itens[i].tempo / 1000.0f);
        printf("\xBA%-68s\xBA\n", linha);
    }

    printf("\xC8");
    for(int i = 0; i < 68; i++) printf("\xCD");
    printf("\xBC\n");
}

/* ============================================================
 * REQUISITO ÚNICO DO GRUPO G07
 * ============================================================ */

/*
 * Dois tipos de fila intercalados: fila normal e prioritária; regra de chamada: 1 prioritário a cada 2 normais.
 * TODO: implementar a função (ou funções) necessárias aqui.
 */

bool cicloClientes(Cliente *atendido, Fila *fila, Fila *filaPrior, int *ciclo) {
    if (filaVazia(fila) && !filaVazia(filaPrior)) {
        *atendido = filaRemover(filaPrior);
        *ciclo = 0;
    } else if (!filaVazia(fila) && filaVazia(filaPrior)) {
        *atendido = filaRemover(fila);
        *ciclo++;
    } else if (*ciclo < 2) {
        if (filaVazia(fila)) {
            printf("\nFila vazia...\n");
            return false;
        }
        *atendido = filaRemover(fila);
        *ciclo++;
    } else {
        if (filaVazia(filaPrior)) {
            printf("\nFila prioritaria vazia...\n");
            *ciclo = 0;
            return false;
        }
        *atendido = filaRemover(filaPrior);
        *ciclo = 0;
    }
    return true;
}

 void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // discard characters
    }
}


