/*
 * ============================================================
 * TRABALHO PRÁTICO — Estrutura de Dados
 * Grupo: G07 | Contexto: UBS
 * ============================================================
 * Parâmetros do grupo:
 *   Capacidade máxima da fila  : 9
 *   Capacidade do histórico    : 4
 *   Algoritmo de ordenação     : Bubble Sort
 *   Algoritmo de busca         : Binária
 *   Tipo de prioridade         : VIP/Urgencia (prioritario=1)
 *   Campo extra no cadastro    : char telefone[20]
 *   Questão 4 do Diário        : inserir 7, remover 2
 *
 * Requisito único: Dois tipos de fila intercalados: fila normal e prioritária; regra de chamada: 1 prioritário a cada 2 normais.
 * ============================================================
 *
 * TRACE MANUAL — (preencher aqui antes da entrega)
 * Algoritmo: Bubble Sort
 * Dados iniciais: [ preencher com senhas reais do contexto ]
 *
 * Passagem 1: ...
 * Passagem 2: ...
 * Resultado final: ...
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


/* ============================================================
 * FUNÇÕES DA LISTA ENCADEADA
 * ============================================================ */

/* Insere cliente na lista */
No* listaInserir(No *inicio, Cliente c) {
    No *noh = (No*)malloc(sizeof(No));
    noh->dado = c;
    /* TODO: implementar inserção */
    /* G01: manter lista ordenada por senha na inserção */
    noh->prox = inicio;
    return noh;
}

/* Remove cliente da lista pelo número da senha */
No* listaRemover(No *inicio, int senha) {
    /* TODO: implementar */
    /* G10: usar busca binária antes de remover */
    return inicio;
}

/* Exibe todos os clientes da lista */
void listaExibir(No *inicio) {
    /* TODO: implementar */
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


/* ============================================================
 * ALGORITMO DE BUSCA — Binária
 * ============================================================ */

/*
 * IMPORTANTE: a busca binária exige que o vetor esteja ordenado.
 * Antes de chamar buscaBinaria(), ordenar o vetor com Bubble Sort.
 */

/* Busca sequencial por senha — percorre elemento a elemento */
int buscaSequencial(Cliente vet[], int n, int senha) {
    /* TODO: implementar */
    /* G02/G09: contar e exibir o número de comparações */
    return -1; /* retorna índice ou -1 se não encontrado */
}

/* Busca binária por senha — exige vetor ordenado */
int buscaBinaria(Cliente vet[], int n, int senha) {
    int low = 0, high = n - 1;
    /* TODO: implementar */
    /* G04/G10: exibir número de comparações realizadas */
    return -1; /* retorna índice ou -1 se não encontrado */
}


/* ============================================================
 * ALGORITMO DE ORDENAÇÃO — Bubble Sort
 * ============================================================ */

/* Ordena vetor de clientes por número de senha (crescente) */
void ordenar(Cliente vet[], int n) {
    /*
     * TODO: implementar Bubble Sort
     *
     * G09: contar e retornar (ou exibir) o número de trocas
     * G10: implementar dois critérios (por senha e por nome)
     *      — use um parâmetro int criterio (0=senha, 1=nome)
     */
}


/* ============================================================
 * RELATÓRIO
 * ============================================================ */

/* Gera relatório de atendimentos ordenado */
void gerarRelatorio(Cliente historico[], int n) {
    /* TODO:
     * 1. Copiar histórico para vetor auxiliar
     * 2. Ordenar com Bubble Sort
     * 3. Exibir
     * G04: filtrar por intervalo de senhas (usa busca binária)
     * G10: perguntar critério ao usuário antes de ordenar
     */
}


/* ============================================================
 * REQUISITO ÚNICO DO GRUPO G07
 * ============================================================ */

/*
 * Dois tipos de fila intercalados: fila normal e prioritária; regra de chamada: 1 prioritário a cada 2 normais.
 * TODO: implementar a função (ou funções) necessárias aqui.
 */


/* ============================================================
 * FUNÇÃO PRINCIPAL
 * ============================================================ */

int main() {
    Fila   fila;
    Pilha  historico;
    No    *lista   = NULL;
    int    opcao   = 0;
    int    proxSenha = 1;

    filaInicializar(&fila);
    pilhaInicializar(&historico);

    printf("=== Sistema de Atendimento — UBS ===\n\n");

    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar novo cliente\n");
        printf("2. Chamar proximo cliente\n");
        printf("3. Buscar cliente\n");
        printf("4. Exibir fila atual\n");
        printf("5. Exibir historico (pilha)\n");
        printf("6. Exibir lista de clientes\n");
        printf("7. Gerar relatorio ordenado\n");
        /* TODO G03: adicionar opcao 8 - Desfazer atendimento */
        /* TODO G07: o menu de chamar já deve aplicar intercalação */
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Cliente c = {0};
                c.senha = proxSenha++;
                printf("Nome: ");
                scanf(" %49s", c.nome);
                printf("Prioritario? (1=sim, 0=nao) [VIP/Urgencia (prioritario=1)]: ");
                scanf("%d", &c.prioritario);
                printf("char telefone[20]: ");
                /* TODO: ler campo extra conforme tipo */

                filaInserir(&fila, c);
                lista = listaInserir(lista, c);
                printf("Cliente cadastrado. Senha: %03d\n", c.senha);
                break;
            }
            case 2: {
                if (filaVazia(&fila)) {
                    printf("Fila vazia.\n");
                } else {
                    Cliente atendido = filaRemover(&fila);
                    pilhaEmpilhar(&historico, atendido);
                    printf("Atendendo: %s (Senha %03d)\n",
                           atendido.nome, atendido.senha);
                }
                break;
            }
            case 3: {
                int senha;
                printf("Numero da senha: ");
                scanf("%d", &senha);
                /* TODO: usar Binária */
                /* Converter lista para vetor auxiliar antes da busca */
                break;
            }
            case 4: filaExibir(&fila);      break;
            case 5: pilhaExibir(&historico); break;
            case 6: listaExibir(lista);      break;
            case 7: {
                /* TODO: copiar histórico para vetor e chamar gerarRelatorio */
                break;
            }
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    lista = listaApagar(lista);
    return 0;
}
