#include <stdio.h>
#include <stdlib.h>
#include "prioridades.h"

/**
 * @brief função auxiliar que remove o '\n' deixado pelo fgets
 * @param str recebe uma string
 */
static void removerNewLine(char *str) {
    int tamanho = strlen(str);
    if (tamanho > 0 && str[tamanho - 1] == '\n') {
        str[tamanho - 1] = '\0';
    }
}

int main () {
    // Variaveis
    int opcao;
    int ordenadoPorNome = 0; // 0 = nao, 1 = sim
    int quantidadeAtual = 0;

    // Cria um array de componentes com a quantidade maxima definida no header
    Componente componentes[MAX_COMP];

    do {
        printf("-----------------------------------\n");
        printf("1 - Adicionar componente\n");
        printf("2 - Listar todos os componentes\n");
        printf("3 - Ordenar por nome       (Bubble Sort)\n");
        printf("4 - Ordenar por tipo       (Insertion Sort)\n");
        printf("5 - Ordenar por prioridade (Selection Sort)\n");
        printf("6 - Buscar componente-chave por nome\n");
        printf("7 - Limpar tela\n");
        printf("0 - Sair\n");
        printf("Qual opção você deseja tomar: ");
        scanf("%d", &opcao);
        getchar();
        printf("-----------------------------------\n");

        switch (opcao){
            // Cadastrar
            case 1:
                adicionarComponente(componentes, &quantidadeAtual, MAX_COMP);
                ordenadoPorNome = 0;
                break;
            // Listar
            case 2:
                if (quantidadeAtual == 0) {
                    printf("A lista esta vazia!\n");
                    break;
                }

                mostrarComponentes(componentes, quantidadeAtual);
                break;
            // Bubble Sort
            case 3:
                if (quantidadeAtual == 0) {
                    printf("A lista esta vazia!\n");
                    break;
                }
                medirTempo(bubbleSortNome, componentes, quantidadeAtual, "Bubble Sort (por nome)");

                printf("Componentes após a ordenação por nome:\n");
                mostrarComponentes(componentes, quantidadeAtual);

                ordenadoPorNome = 1;
                break;
            // Insertion Sort
            case 4:
                if (quantidadeAtual == 0) {
                    printf("A lista esta vazia!\n");
                    break;
                }

                medirTempo(insertionSortTipo, componentes, quantidadeAtual, "Insertion Sort (por tipo)");

                printf("Componentes depois da ordenação por tipo:\n");
                mostrarComponentes(componentes, quantidadeAtual);

                ordenadoPorNome = 0;
                break;
            // Selection Sort
            case 5:
                if (quantidadeAtual == 0) {
                    printf("A lista esta vazia!\n");
                    break;
                }

                medirTempo(selectionSortPrioridade, componentes, quantidadeAtual, "Selection Sort (por prioridade)");
                
                printf("Componentes depois da ordenação por prioridade:\n");
                mostrarComponentes(componentes, quantidadeAtual);
                
                ordenadoPorNome = 0;
                break;
            // Busca Binária
            case 6:
                if (quantidadeAtual == 0) {
                    printf("A lista esta vazia!\n");
                    break;
                }
                if (!ordenadoPorNome) {
                    printf("A lista nao esta ordenada por nome!\n");
                    printf("Use a opção 3 (Bubble Sort) primeiro!\n");
                    break;
                }

                char nomeBusca[30];
                printf("Digite o nome do componente-chave que você deseja buscar: ");
                fgets(nomeBusca, 30, stdin);
                removerNewLine(nomeBusca);

                int idx = buscaBinariaNome(componentes, quantidadeAtual, nomeBusca);
                if (idx != -1) {
                    printf("Componente-chave encontrado!\n");
                    printf("Nome: %s\n", componentes[idx].nome);
                    printf("Tipo: %s\n", componentes[idx].tipo);
                    printf("Prioridade: %d\n", componentes[idx].prioridade);
                } else {
                    printf("Componente-chave nao encontrado!\n");
                }
                break;
            // Limpar tela
            case 7:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                    break;
            // Sair
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while(opcao != 0);
    return 0;
}