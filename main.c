


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

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "funcoesImprimir.h"
#include "structs.h"

void imprimirLinha(char esq, char meio, char dir, int largura) {
    printf("%c", esq);
    for (int i = 0; i < largura; i++) printf("%c", meio);
    printf("%c\n", dir);
}

void imprimirCentro(const char *texto, int largura) {
    int len = (int)strlen(texto);
    int pad = (largura - len) / 2;
    printf("\xBA");
    for (int i = 0; i < pad; i++) printf(" ");
    printf("%s", texto);
    for (int i = 0; i < largura - pad - len; i++) printf(" ");
    printf("\xBA\n");
}

void imprimirOpcao(const char *num, const char *texto, int largura) {
    char linha[128];
    snprintf(linha, sizeof(linha), "  %s  %s", num, texto);
    int len = (int)strlen(linha);
    printf("\xBA%s", linha);
    for (int i = len; i < largura; i++) printf(" ");
    printf("\xBA\n");
}
void imprimirMenu() {
    const int L = 38; /* largura interna */

    /* Topo */
    printf("\xC9");
    for (int i = 0; i < L; i++) printf("\xCD");
    printf("\xBB\n");

    /* Título */
    imprimirCentro("SISTEMA DE ATENDIMENTO", L);
    imprimirCentro("UBS  -  Grupo G07", L);

    /* Divisor */
    printf("\xBA");
    for (int i = 0; i < L; i++) printf("\xC4");
    printf("\xBA\n");

    /* Seção: Clientes */
    imprimirCentro("[ CLIENTES ]", L);
    imprimirOpcao("[1]", "Cadastrar novo cliente", L);
    imprimirOpcao("[2]", "Chamar proximo cliente", L);
    imprimirOpcao("[3]", "Buscar cliente por senha", L);

    /* Divisor */
    printf("\xBA");
    for (int i = 0; i < L; i++) printf("\xC4");
    printf("\xBA\n");

    /* Seção: Consultas */
    imprimirCentro("[ CONSULTAS ]", L);
    imprimirOpcao("[4]", "Exibir fila atual", L);
    imprimirOpcao("[5]", "Exibir historico (pilha)", L);
    imprimirOpcao("[6]", "Exibir lista de clientes", L);
    imprimirOpcao("[7]", "Gerar relatorio ordenado", L);

    /* Divisor */
    printf("\xBA");
    for (int i = 0; i < L; i++) printf("\xC4");
    printf("\xBA\n");

    /* Sair */
    imprimirOpcao("[0]", "Sair do sistema", L);

    /* Rodape */
    printf("\xC8");
    for (int i = 0; i < L; i++) printf("\xCD");
    printf("\xBC\n");

    printf("  Opcao: ");
}


/* ============================================================
 * FUNÇÃO PRINCIPAL
 * ============================================================ */

int main() {
    Fila   fila;
    Fila   filaPrioritaria;
    Pilha  historico;
	Pilha  retira;
    PilhaTimer relatorio;
    PilhaTimer retiraTimer;
    No    *lista   = NULL;
    int    opcao   = 0;
    int    proxSenha = 1;
    int    ciclo = 0;
    AtendimentoTimer timer = {0};
    bool timerValido = false;

    filaInicializar(&fila);
    filaInicializar(&filaPrioritaria);
    pilhaInicializar(&historico);
	pilhaInicializar(&retira);
    pilhaTimerInicializar(&relatorio);
    pilhaTimerInicializar(&retiraTimer);

    do {
        imprimirMenu();
        /* TODO G07: o menu de chamar já deve aplicar intercalação */
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int temp = 0;
                Cliente c = {0};

                printf("\nPrioritario? (1=sim, 0=nao) [VIP/Urgencia (prioritario=1)]: ");
                scanf("%d",
                    &c.prioritario);

				while(c.prioritario < 0 || c.prioritario > 1) {
					printf("Insira um valor valido!\nPrioritario? (1=sim, 0=nao): ");
                	scanf("%d",
                    	&c.prioritario);
				}

                if (c.prioritario == 1) {
                    if (filaCheia(&filaPrioritaria)) {
                        printf("\nFila prioritaria cheia...\n");
                        break;
                    }
                } else {
                    if (filaCheia(&fila)) {
                        printf("\nFila cheia...\n");
                        break;
                    }
                }

                printf("Nome: ");
                scanf(" %49[^\n]s",
					c.nome);
				clear_input_buffer();

				for(int i = 0; i < sizeof(c.nome); i++) {
					if(isdigit(c.nome[i])) {
						printf("Valor invalido!\n");
						temp = 1;
						break;
					}
				}

                if(temp) {
                	temp = 0;
                	break;
				}

                printf("Telefone: ");
                scanf("%19s",
                    c.telefone);
                clear_input_buffer();

                for(int i = 0; i < sizeof(c.telefone); i++) {
                    if(isalpha(c.telefone[i])) {
                        printf("Valor invalido!\n");
                        temp = 1;
                        break;
                    }
                }

                if(temp) {
                    temp = 0;
                    break;
                }

                c.senha = proxSenha++;

                if (c.prioritario == 1) {
                    filaInserir(&filaPrioritaria, c);
                } else {
                    filaInserir(&fila, c);
                }

                lista = listaInserir(lista, c);
                printf("\nCliente cadastrado. Senha: %03d\n",
                    c.senha);
                break;
            }
            case 2: {
                if (timerValido) {
                    if (pilhaTimerCheia(&relatorio) == 1) {
                        while (!pilhaTimerVazia(&relatorio)) {
                            pilhaTimerEmpilhar(&retiraTimer, pilhaTimerDesempilhar(&relatorio));
                        }
                        pilhaTimerDesempilhar(&retiraTimer);
                        while (!pilhaTimerVazia(&retiraTimer)) {
                            pilhaTimerEmpilhar(&relatorio, pilhaTimerDesempilhar(&retiraTimer));
                        }
                    }
                    timer.tick_fim = GetTickCount();
                    timer.tempo = timer.tick_fim - timer.tick_inicio;
                    timerValido = false;
                    pilhaTimerEmpilhar(&relatorio,timer);
                }

                Cliente atendido;
                if (!cicloClientes(&atendido, &fila, &filaPrioritaria, &ciclo)) {
                    break;
                }
                if (pilhaCheia(&historico) == 1) {
                    while (!pilhaVazia(&historico)) {
                        pilhaEmpilhar(&retira, pilhaDesempilhar(&historico));
                    }
                    pilhaDesempilhar(&retira);
                    while (!pilhaVazia(&retira)) {
                        pilhaEmpilhar(&historico, pilhaDesempilhar(&retira));
                    }
                }
                pilhaEmpilhar(&historico, atendido);
                printf("\nAtendendo: %s (Senha %03d)\n",
                    atendido.nome,
                    atendido.senha);

                    timer.cliente = atendido;
                    timer.tick_inicio = GetTickCount();
                    timerValido = true;
                break;
            }
            case 3: {
                int senha;
                printf("\nNumero da senha: ");
                scanf("%d", &senha);
                Cliente vet[9];
                int tam = 0;
                No* aux = lista;

                while (aux != NULL && tam < 9) {
                    vet[tam] = aux->dado;
                    tam++;
                    aux = aux->prox;
                }
                int resultado = buscaBinaria(vet,tam,senha);
                if (resultado != -1) {
                    const int L = 68;
                    printf("\n");
                    printf("\xC9");
                    for(int i = 0; i < L; i++) printf("\xCD");
                    printf("\xBB\n");
                    imprimirCentroLinha("CLIENTE ENCONTRADO", L);
                    printf("\xBA");
                    for(int i = 0; i < L; i++) printf("\xC4");
                    printf("\xBA\n");

                    char linha1[L], linha2[L];
                    snprintf(linha1, sizeof(linha1), " Nome: %s", vet[resultado].nome);
                    snprintf(linha2, sizeof(linha2), " Telefone: %s", vet[resultado].telefone);
                    imprimirCentroLinha(linha1, L);
                    imprimirCentroLinha(linha2, L);

                    printf("\xC8");
                    for(int i = 0; i < L; i++) printf("\xCD");
                    printf("\xBC\n");
                }
                else {
                    printf("\nCliente nao encontrado.\n");
                }
                break;
            }
            case 4: {
                if(filaVazia(&fila) && filaVazia(&filaPrioritaria)) {
                    printf("\nFila vazia...\n");
                    break;
                }
                filaExibir(&fila, 0);
                filaExibir(&filaPrioritaria, 1);
                break;
            }
            case 5: {
                pilhaExibir(&historico);
                break;
                }
            case 6: {
                listaExibir(lista);
                break;
                }
            case 7: {
                gerarRelatorio(&relatorio);
                break;
            }
            case 0: {
				printf("Encerrando...\n");
				break;
            }
            default:
				printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    lista = listaApagar(lista);
    return 0;
}