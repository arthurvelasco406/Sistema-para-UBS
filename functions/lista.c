#include <stdio.h>
#include "../structs.h"
#include "stdlib.h"

/* ============================================================
 * FUNÇÕES DA LISTA ENCADEADA
 * ============================================================ */

/* Insere cliente na lista */
No* listaInserir(No *inicio, Cliente c) {

    /* TODO: a implementação está ordenando pela senha. Faz sentido manter assim?*/
    /* G01: manter lista ordenada por senha na inserção */

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
    /* TODO: deverá retornar o inicio da lista ou o elemento removido? */
    /*G10: usar busca binária antes de remover */

    No *aux = inicio;
    if (inicio->dado.senha == senha) {
        aux = inicio->prox;
        free(inicio);
        *inicio = NULL;
        return aux;
    }
    else {
        while (aux->prox != NULL) {
            if (aux->prox->dado.senha == senha) {
                No *auxProx = aux->prox->prox;
                free(aux->prox);
                aux->prox->prox = NULL;
                aux->prox = auxProx;
                return inicio;
            }
            aux = aux->prox;
        }
    }
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

