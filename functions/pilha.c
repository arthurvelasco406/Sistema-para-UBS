#include <stdio.h>
#include "../structs.h"

/* ============================================================
 * FUNÇÕES DA PILHA (HISTÓRICO)
 * ============================================================ */

/* Inicializa a pilha */
void pilhaInicializar(Pilha *p) {
    p->topo = 0;
}

/* Retorna 1 se a pilha estiver vazia, 0 caso contrário */
int pilhaVazia(Pilha *p) {
    if (p->topo == 0) return 1;
    return 0;
}

/* Retorna 1 se a pilha estiver cheia, 0 caso contrário */
int pilhaCheia(Pilha *p) {
    if (p->topo == 4) return 1;
    return 0;
}

/* Empilha cliente no histórico */
void pilhaEmpilhar(Pilha *p, Cliente c) {
    if (pilhaCheia(p) == 0) {
        p->itens[p->topo] = c;
        p->topo++;
    }
}

/* Desempilha e retorna o topo */
Cliente pilhaDesempilhar(Pilha *p) {
    Cliente vazio = {0};
    if (pilhaVazia(p) == 0) {
        p->topo--;
        vazio = p->itens[p->topo];
    }
    return vazio;
}

/* Exibe o histórico de atendimentos */
void pilhaExibir(Pilha *p) {
    printf("\n =============================");
    printf("\n | HISTORICO DE ATENDIMENTOS |");
    printf("\n =============================\n\n");

    for (int i = 0; i < 4; i++) {
        char prioridade[10] = "Normal";
        if (p->itens[i].prioritario == 1) prioridade = "VIP";
        printf("\n%03d - %s | Prioridade: %s | Fone: %s",
            p->itens[i].senha,
            p->itens[i].nome,
            prioridade,
            p->itens[i].telefone);
    }
}
