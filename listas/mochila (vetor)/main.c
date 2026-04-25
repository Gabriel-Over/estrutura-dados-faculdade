#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itens.h"

#define MAX_ITENS 10

int main () {
    // Variaveis
    int quantidadeAtual = 0;
    int opcao;

    // Cria um array de itens
    Item itens[MAX_ITENS];

    // Menu de opções
    do {
        printf("-----------------------------------\n");
        printf("1 - Adicionar item\n");
        printf("2 - Listar todos os itens\n");
        printf("3 - Pesquisar item\n");
        printf("4 - Remover item\n");
        printf("5 - Limpar tela\n");
        printf("0 - Sair\n");
        printf("Qual opção você deseja tomar: ");
        scanf("%d", &opcao);
        getchar();
        printf("-----------------------------------\n");

        switch (opcao){
            case 1:
                adicionarItem(itens, &quantidadeAtual, MAX_ITENS);
                break;
            case 2:
                listarItens(itens, quantidadeAtual);
                break;
            case 3:
                pesquisarItens(itens, quantidadeAtual);
                break;
            case 4:
                removerItem(itens, &quantidadeAtual);
                break;
            case 5:
                system("cls");
                break;
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