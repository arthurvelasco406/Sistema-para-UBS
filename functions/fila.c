#include <stddef.h>
#include <stdio.h>

#include "../structs.h"

/* ============================================================
 * FUNÇÕES DA FILA
 * ============================================================ */

/* Inicializa a fila */
void filaInicializar(Fila *f) {
    f->inicio = 0;
    f->final  = 0;
}

/* Retorna 1 se a fila estiver vazia, 0 caso contrário */
int filaVazia(Fila *f) {
    if (f->inicio == f->final) {
        return 1;
    }
    return 0;
}

/* Retorna 1 se a fila estiver cheia, 0 caso contrário */
int filaCheia(Fila *f) {
    if ((f->final + 1) % 9 == f->inicio) {
        return 1;
    }
    return 0;
}

/* Insere cliente na fila */
void filaInserir(Fila *f, Cliente c) {
    /* Lembrar: fila circular usa (f->final % 9) */
    if (!filaCheia(f)) {
        printf("Erro ao inserir... Fila cheia.\n");
    }
    f->itens[f->final] = c;
    f->final++;
    printf("Inserido com sucesso!\n");
}

/* Remove e retorna o primeiro cliente da fila */
Cliente filaRemover(Fila *f) {
    Cliente vazio = {0};
    /* G07: aplicar regra de intercalação (1 prioritário a cada 2 normais) */
    Cliente temp = vazio;
    vazio = f->itens[f->inicio];
    f->itens[f->inicio] = temp;
    f->inicio++;
    return vazio;
}

/* Exibe o estado atual da fila */
void filaExibir(Fila *f) {
    if(filaVazia(f)) {
        printf("Fila vazia...\n");
        return;
    }
    int tam = f->final + f->inicio;
    for (int i = 0; i < tam; i++) {
        printf("Nome: %s\n", f->itens[i].nome);
        if (f->itens[i].prioritario == 1) {
            printf("Prioritario: Urgencia\n");
        } else {
            printf("Prioritario: Normal\n");
        }
        printf("Senha: %03d\n", f->itens[i].senha);
        printf("Telefone: %s\n", f->itens[i].telefone);
    }
}
