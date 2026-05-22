#include "../structs.h"

/* ============================================================
 * FUNÇÕES DA FILA
 * ============================================================ */

/* Inicializa a fila */
void filaInicializar(Fila *f) {
    f->inicio = 0;
    f->final  = 0;
    /* TODO: inicializar campo quantidade se necessário (G05) */
}

/* Retorna 1 se a fila estiver vazia, 0 caso contrário */
int filaVazia(Fila *f) {
    /* TODO: implementar */
    return 0;
}

/* Retorna 1 se a fila estiver cheia, 0 caso contrário */
int filaCheia(Fila *f) {
    /* TODO: implementar */
    return 0;
}

/* Insere cliente na fila */
void filaInserir(Fila *f, Cliente c) {
    /* TODO: implementar — verificar se fila está cheia antes */
    /* Lembrar: fila circular usa (f->final % 9) */
}

/* Remove e retorna o primeiro cliente da fila */
Cliente filaRemover(Fila *f) {
    Cliente vazio = {0};
    /* TODO: implementar — verificar se fila está vazia antes */
    /* G07: aplicar regra de intercalação (1 prioritário a cada 2 normais) */
    /* G06: antes de remover, verificar expirações */
    return vazio;
}

/* Exibe o estado atual da fila */
void filaExibir(Fila *f) {
    /* TODO: implementar — exibir senha e nome de cada cliente na fila */
}
