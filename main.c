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
#include "structs.h"

/* ============================================================
 * FUNÇÃO PRINCIPAL
 * ============================================================ */

int main() {
    Fila   fila;
    Fila   filaPrioritaria;
    Pilha  historico;
	Pilha  retira;
    PilhaTimer relatorio;
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
        printf("0. Sair\n");
        printf("Opcao: ");
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
						printf("Valor invalido!");
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
                        pilhaDesempilhar(&historico);
                    }
                if (pilhaTimerCheia(&relatorio) == 1) {
                        pilhaTimerDesempilhar(&relatorio);
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
                    printf("\nCliente encontrado: %s - Fone: %s\n", vet[resultado].nome, vet[resultado].telefone);
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