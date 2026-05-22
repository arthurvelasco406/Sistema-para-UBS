#include "../structs.h"
#include "stdlib.h"


/* ============================================================
 * FUNÇÕES DA LISTA ENCADEADA
 * ============================================================ */

/* Insere cliente na lista */
No* listaInserir(No *inicio, Cliente c) {
    No *noh = (No*)malloc(sizeof(No));
    noh->dado = c;
    /* TODO: implementar inserção */
    /* G01: manter lista ordenada por senha na inserção */
    noh->prox = inicio;
    return noh;
}

/* Remove cliente da lista pelo número da senha */
No* listaRemover(No *inicio, int senha) {
    /* TODO: implementar */
    /* G10: usar busca binária antes de remover */
    return inicio;
}

/* Exibe todos os clientes da lista */
void listaExibir(No *inicio) {
    /* TODO: implementar */
}

/* Libera toda a memória da lista */
No* listaApagar(No *inicio) {
    No *atual = inicio;
    while (atual != NULL) {
        No *t = atual->prox;
        free(atual);
        atual = t;
    }
    return NULL;
}

