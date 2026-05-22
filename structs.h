
/* ============================================================
 * DEFINIÇÃO DAS STRUCTS
 * ============================================================ */

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
    /* TODO G05: adicionar campo 'quantidade' aqui */
} Fila;

/* Pilha implementada com vetor */
typedef struct {
    Cliente itens[4];
    int topo;
} Pilha;


/* ============================================================
 * FUNÇÕES DA FILA
 * ============================================================ */

/* Inicializa a fila */
void filaInicializar(Fila *f);

/* Retorna 1 se a fila estiver vazia, 0 caso contrário */
int filaVazia(Fila *f);

/* Retorna 1 se a fila estiver cheia, 0 caso contrário */
int filaCheia(Fila *f);

/* Insere cliente na fila */
void filaInserir(Fila *f, Cliente c);

/* Remove e retorna o primeiro cliente da fila */
Cliente filaRemover(Fila *f);

/* Exibe o estado atual da fila */
void filaExibir(Fila *f);


/* ============================================================
 * FUNÇÕES DA PILHA (HISTÓRICO)
 * ============================================================ */

/* Inicializa a pilha */
void pilhaInicializar(Pilha *p);

/* Retorna 1 se a pilha estiver vazia, 0 caso contrário */
int pilhaVazia(Pilha *p);

/* Retorna 1 se a pilha estiver cheia, 0 caso contrário */
int pilhaCheia(Pilha *p);

/* Empilha cliente no histórico */
void pilhaEmpilhar(Pilha *p, Cliente c);

/* Desempilha e retorna o topo */
Cliente pilhaDesempilhar(Pilha *p);

/* Exibe o histórico de atendimentos */
void pilhaExibir(Pilha *p);


/* ============================================================
 * FUNÇÕES DA LISTA ENCADEADA
 * ============================================================ */

/* Insere cliente na lista */
No* listaInserir(No *inicio, Cliente c);

/* Remove cliente da lista pelo número da senha */
No* listaRemover(No *inicio, int senha);

/* Exibe todos os clientes da lista */
void listaExibir(No *inicio);

/* Libera toda a memória da lista */
No* listaApagar(No *inicio);


/* ============================================================
 * ALGORITMO DE BUSCA — Binária
 * ============================================================ */

/*
 * IMPORTANTE: a busca binária exige que o vetor esteja ordenado.
 * Antes de chamar buscaBinaria(), ordenar o vetor com Bubble Sort.
 */

/* Busca sequencial por senha — percorre elemento a elemento */
int buscaSequencial(Cliente vet[], int n, int senha);

/* Busca binária por senha — exige vetor ordenado */
int buscaBinaria(Cliente vet[], int n, int senha);


/* ============================================================
 * ALGORITMO DE ORDENAÇÃO — Bubble Sort
 * ============================================================ */

/* Ordena vetor de clientes por número de senha (crescente) */
void ordenar(Cliente vet[], int n);


/* ============================================================
 * RELATÓRIO
 * ============================================================ */

/* Gera relatório de atendimentos ordenado */
void gerarRelatorio(Cliente historico[], int n);


/* ============================================================
 * REQUISITO ÚNICO DO GRUPO G07
 * ============================================================ */

/*
 * Dois tipos de fila intercalados: fila normal e prioritária; regra de chamada: 1 prioritário a cada 2 normais.
 * TODO: implementar a função (ou funções) necessárias aqui.
 */

