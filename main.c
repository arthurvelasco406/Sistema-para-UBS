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
#include "structs.h"

/* ============================================================
 * FUNÇÃO PRINCIPAL
 * ============================================================ */

int main() {
    Fila   fila;
    Fila   filaPrioritaria;
    Pilha  historico;
    No    *lista   = NULL;
    int    opcao   = 0;
    int    proxSenha = 1;
    int    ciclo = 0;

    filaInicializar(&fila);
    filaInicializar(&filaPrioritaria);
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
        /* TODO G07: o menu de chamar já deve aplicar intercalação */
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int temp;
                Cliente c = {0};
                printf("Prioritario? (1=sim, 0=nao) [VIP/Urgencia (prioritario=1)]: ");
                scanf("%d",
                    &c.prioritario);
                if (c.prioritario == 1) {
                    if (filaCheia(&filaPrioritaria)) {
                        printf("Fila prioritaria cheia...");
                        break;
                    }
                } else {
                    if (filaCheia(&fila)) {
                        printf("Fila cheia...\n");
                        break;
                    }
                }
                c.senha = proxSenha++;
                printf("Nome: ");
                scanf(" %49s",
                    c.nome);
                printf("Telefone: ");
                scanf("%19s",
                    c.telefone);
                /* TODO: ler campo extra conforme tipo */

                if (c.prioritario == 1) {
                    filaInserir(&filaPrioritaria, c);
                } else {
                    filaInserir(&fila, c);
                }
                lista = listaInserir(lista, c);
                printf("Cliente cadastrado. Senha: %03d\n",
                    c.senha);
                break;
            }
            case 2: {
                Cliente atendido;
                if (filaVazia(&fila) && !filaVazia(&filaPrioritaria)) {
                    atendido = filaRemover(&filaPrioritaria);
                    ciclo = 0;
                } else if (!filaVazia(&fila) && filaVazia(&filaPrioritaria)) {
                    atendido = filaRemover(&fila);
                    ciclo++;
                } else if (ciclo < 2) {
                    if (filaVazia(&fila)) {
                        printf("Fila vazia...\n");
                        break;
                    }
                    atendido = filaRemover(&fila);
                    ciclo++;
                } else {
                    if (filaVazia(&filaPrioritaria)) {
                        printf("Fila prioritaria vazia...\n");
                        ciclo = 0;
                        break;
                    }
                    atendido = filaRemover(&filaPrioritaria);
                    ciclo = 0;
                }
                pilhaEmpilhar(&historico, atendido);
                printf("Atendendo: %s (Senha %03d)\n",
                    atendido.nome,
                    atendido.senha);
                break;
            }
            case 3: {
                int senha;
                printf("Numero da senha: ");
                scanf("%d", &senha);
                /* TODO: usar Binária */
                /* Converter lista para vetor auxiliar antes da busca */
                Cliente vet[9];
                int tam = 0;
                No* aux = lista;
                while (aux != NULL && tam < 9) {
                    vet[tam] = aux->dado;
                    tam++;
                    aux = aux->prox;
                }
                ordenar(vet,tam);
                int resultado = buscaBinaria(vet,tam,senha);
                if (resultado != -1) {
                    printf("Cliente encontrado: %s - Fone: %s\n", vet[resultado].nome, vet[resultado].telefone);
                }
                else {
                    printf("Cliente nao encontrado.\n");
                }
                break;
            }
            case 4:
                printf("Fila normal:\n");
                filaExibir(&fila);
                printf("Fila prioritaria:\n");
                filaExibir(&filaPrioritaria);
                break;
            case 5: pilhaExibir(&historico); break;
            case 6: listaExibir(lista);      break;
            case 7: {
                Cliente auxHistorico[4];
                int i;
                for (i = 0; i < historico.topo; i++) {
                    auxHistorico[i] = historico.itens[i];
                }
                gerarRelatorio(auxHistorico, historico.topo);
                break;
            }
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    lista = listaApagar(lista);
    return 0;
}
