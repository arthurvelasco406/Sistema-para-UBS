#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include "../funcoesImprimir.h"
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
    // if ((f->final) % 9 == f->inicio)
    int tam = f->final+f->inicio;
    if (tam == 9) return 1;
    return 0;
}

/* Insere cliente na fila */
void filaInserir(Fila *f, Cliente c) {
    /* Lembrar: fila circular usa (f->final % 9) */
    if (filaCheia(f)) {
        printf("\nErro ao inserir... Fila cheia.\n");
        return;
    }
    f->itens[f->final] = c;
    f->final = (f->final + 1) % 9;
}

/* Remove e retorna o primeiro cliente da fila */
Cliente filaRemover(Fila *f) {
    Cliente vazio = {0};
    /* G07: aplicar regra de intercalação (1 prioritário a cada 2 normais) */
    Cliente temp = vazio;
    vazio = f->itens[f->inicio];
    f->itens[f->inicio] = temp;
    f->inicio = (f->inicio + 1) % 9;
    return vazio;
}

/* Exibe o estado atual da fila */
void filaExibir(Fila *f, int prioridade) {
    if(filaVazia(f)) {
        return;
    }

    printf("\n\xC9");
    for(int i = 0; i < 68; i++) printf("\xCD");
    printf("\xBB\n");

    if(prioridade == 1) {
    imprimirCentroLinha(" FILA PRIORITARIA (VIP / Urgencia)",68);
    } else {
    imprimirCentroLinha("FILA NORMAL",68);
    }

    printf("\xBA");
    for(int i = 0; i < 68; i++) printf("\xC4");
    printf("\xBA\n");

    int i = f->inicio;
    while(i != f->final) {
        char linha[68];
        snprintf(linha, sizeof(linha), " [%03d] %-15s  Fone: %s",
            f->itens[i].senha,
            f->itens[i].nome,
            f->itens[i].telefone);
        printf("\xBA%-68s\xBA\n", linha);
        i = (i + 1) % 9;
    }

    printf("\xC8");
    for(int i = 0; i < 68; i++) printf("\xCD");
    printf("\xBC\n");
}

