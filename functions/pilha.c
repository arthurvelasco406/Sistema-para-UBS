#include "../structs.h"

/* ============================================================
 * FUNÇÕES DA PILHA (HISTÓRICO)
 * ============================================================ */

/* Inicializa a pilha */
void pilhaInicializar(Pilha *p) {
    p->topo = -1;
}

/* Retorna 1 se a pilha estiver vazia, 0 caso contrário */
int pilhaVazia(Pilha *p) {
    /* TODO: implementar */
    return 0;
}

/* Retorna 1 se a pilha estiver cheia, 0 caso contrário */
int pilhaCheia(Pilha *p) {
    /* TODO: implementar */
    return 0;
}

/* Empilha cliente no histórico */
void pilhaEmpilhar(Pilha *p, Cliente c) {
    /* TODO: implementar */
    /* G08: se cheia, descartar o mais antigo antes de empilhar */
}

/* Desempilha e retorna o topo */
Cliente pilhaDesempilhar(Pilha *p) {
    Cliente vazio = {0};
    /* TODO: implementar */
    return vazio;
}

/* Exibe o histórico de atendimentos */
void pilhaExibir(Pilha *p) {
    /* TODO: implementar */
}

