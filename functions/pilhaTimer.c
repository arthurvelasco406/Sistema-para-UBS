
#include "../structs.h"


void pilhaTimerInicializar(PilhaTimer *p) { p->topo = 0; }

int pilhaTimerVazia(PilhaTimer *p) { return p->topo == 0; }

int pilhaTimerCheia(PilhaTimer *p) { return p->topo == 4; }

void pilhaTimerEmpilhar(PilhaTimer *p, AtendimentoTimer t) {
    if (!pilhaTimerCheia(p)) {
        p->itens[p->topo] = t;
        p->topo++;
    }
}

AtendimentoTimer pilhaTimerDesempilhar(PilhaTimer *p) {
    AtendimentoTimer vazio = {0};
    if (!pilhaTimerVazia(p)) {
        p->topo--;
        vazio = p->itens[p->topo];
    }
    return vazio;
}