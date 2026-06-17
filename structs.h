/* ============================================================
 * DEFINIÇÃO DAS STRUCTS
 * ============================================================ */

#include <stdbool.h>
#include <windows.h>

/* Struct do cliente — adaptar conforme parâmetros do grupo */
typedef struct cliente {
    int senha;
    char nome[50];
    int prioritario;   /* 0 = normal, 1 = prioritário (VIP/Urgencia (prioritario=1)) */
    char telefone[20];        /* campo extra do grupo */
} Cliente;

/* Nó da lista encadeada — mantém nomes 'dado' e 'prox' das aulas */
typedef struct no {
    Cliente dado;
    struct no *prox;
} No;

/* Fila implementada com vetor */
typedef struct {
    Cliente itens[9];
    int inicio;
    int final;
} Fila;

/* Pilha implementada com vetor */
typedef struct {
    Cliente itens[4];
    int topo;
} Pilha;

typedef struct {
    Cliente cliente;
    DWORD tick_inicio;
    DWORD tick_fim;
    DWORD tempo;
} AtendimentoTimer;

typedef struct {
    AtendimentoTimer itens[4];
    int topo;
} PilhaTimer;
/* ============================================================
 * FUNÇÕES DA FILA
 * ============================================================ */

void filaInicializar(Fila *f);

int filaVazia(Fila *f);

int filaCheia(Fila *f);

void filaInserir(Fila *f, Cliente c);

Cliente filaRemover(Fila *f);

void filaExibir(Fila *f, int n);

/* ============================================================
 * FUNÇÕES DA PILHA (HISTÓRICO)
 * ============================================================ */

void pilhaInicializar(Pilha *p);

int pilhaVazia(Pilha *p);

int pilhaCheia(Pilha *p);

void pilhaEmpilhar(Pilha *p, Cliente c);

Cliente pilhaDesempilhar(Pilha *p);

void pilhaExibir(Pilha *p);


void pilhaTimerInicializar(PilhaTimer *p);

int pilhaTimerVazia(PilhaTimer *p);

int pilhaTimerCheia(PilhaTimer *p);

void pilhaTimerEmpilhar(PilhaTimer *p, AtendimentoTimer t);

AtendimentoTimer pilhaTimerDesempilhar(PilhaTimer *p);
/* ============================================================
 * FUNÇÕES DA LISTA ENCADEADA
 * ============================================================ */

No* listaInserir(No *inicio, Cliente c);

No* listaRemover(No *inicio, int senha);

void listaExibir(No *inicio);

No* listaApagar(No *inicio);

/* ============================================================
 * ALGORITMO DE BUSCA — Binária
 * ============================================================ */

int buscaSequencial(Cliente vet[], int n, int senha);

int buscaBinaria(Cliente vet[], int n, int senha);

/* ============================================================
 * ALGORITMO DE ORDENAÇÃO — Bubble Sort
 * ============================================================ */

void ordenar(Cliente vet[], int n);
void ordenarPorTempo(PilhaTimer vet[], int n);
/* ============================================================
 * RELATÓRIO
 * ============================================================ */

void gerarRelatorio(PilhaTimer historico[]);

/* ============================================================
 * REQUISITO ÚNICO DO GRUPO G07
 * ============================================================ */

bool cicloClientes(Cliente *c, Fila *f, Fila *fp, int *n);
void clear_input_buffer();
/*
 * Dois tipos de fila intercalados: fila normal e prioritária; regra de chamada: 1 prioritário a cada 2 normais.
 * TODO: implementar a função (ou funções) necessárias aqui.
 */
