#include <stdio.h>
#include <string.h>

#include "../structs.h"
#include "../funcoesImprimir.h"
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
    if (p->topo == 4) {
        return 1;
    }
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
    if (pilhaVazia(p)) {
        printf("\n\xC9");
        for(int i = 0; i < 68; i++) printf("\xCD");
        printf("\xBB\n");
        imprimirCentroLinha("HISTORICO DE ATENDIMENTOS",68);
        printf("\xBA");
        for(int i = 0; i < 68; i++) printf("\xC4");
        printf("\xBA\n");
        imprimirCentroLinha("Nenhum atendimento registrado.",68);
        printf("\xC8");
        for(int i = 0; i < 68; i++) printf("\xCD");
        printf("\xBC\n");
        return;
    }

    printf("\n\xC9");
    for(int i = 0; i < 68; i++) printf("\xCD");
    printf("\xBB\n");
    imprimirCentroLinha("HISTORICO DE ATENDIMENTOS",68);
    printf("\xBA");
    for(int i = 0; i < 68; i++) printf("\xC4");
    printf("\xBA\n");

    for (int i = 0; i < p->topo; i++) {
        char prioridade[12] = "Normal";
        if (p->itens[i].prioritario == 1) strcpy(prioridade, "Urgencia");
        char linha[68];
        snprintf(linha, sizeof(linha), " [%03d] %-15s Fone: %-11s Prioridade: [%s] ",
            p->itens[i].senha,
            p->itens[i].nome,
            p->itens[i].telefone,
            prioridade);
        printf("\xBA%-68s\xBA\n", linha);
    }

    printf("\xC8");
    for(int i = 0; i < 68; i++) printf("\xCD");
    printf("\xBC\n");
}