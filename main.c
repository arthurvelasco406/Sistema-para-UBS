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
