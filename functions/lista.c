#include <stdio.h>
#include "../structs.h"
#include "stdlib.h"

/* ============================================================
 * FUNÇÕES DA LISTA ENCADEADA
 * ============================================================ */

/* Insere cliente na lista e mantem ordenado pela senha*/
No* listaInserir(No *inicio, Cliente c) {
    No *noh = (No*)malloc(sizeof(No));
    No *aux;

    if (noh) {
        noh->dado = c;

        if (inicio == NULL) {
            noh->prox = NULL;
            return noh;
        }
        else if (inicio->dado.senha > c.senha) {
            noh->prox = inicio;
            return noh;
        }
        else if (inicio->dado.senha < c.senha) {
            aux = inicio;
            while (aux->prox != NULL && aux->prox->dado.senha < c.senha) {
                aux = aux->prox;
            }
            noh->prox = aux->prox;
            aux->prox = noh;
            return inicio;
        }
    }
    else {
        printf("\nErro na alocaçao de memória!");
    }
}

/* Remove cliente da lista pelo número da senha */
No* listaRemover(No *inicio, int senha) {
    No *aux = inicio;
    No *removed = NULL;

    if (inicio->dado.senha == senha) {
        removed = inicio;
        inicio = inicio->prox;
    }
    else {
        while (aux->prox != NULL && aux->prox->dado.senha != senha) {
            aux = aux->prox;
        }
        if (aux->prox) {
            removed = aux->prox;
            aux->prox = removed->prox;
        }
    }
    return removed;
}

/* Exibe todos os clientes da lista */
void listaExibir(No *inicio) {
    No *noh = inicio;
    char prioridade[10] = "Normal";

    if (noh->dado.prioritario == 1) prioridade = "Urgência";

    printf("\n ==============================");
    printf("\n |     LISTA DE PACIENTES     |");
    printf("\n ==============================\n");

    while (noh) {
        printf("\n | %03d - %s - Fone: %s - Prioridade = %s",
            noh->dado.senha,
            noh->dado.nome,
            noh->dado.telefone,
            prioridade);
        noh = noh->prox;
    }
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

