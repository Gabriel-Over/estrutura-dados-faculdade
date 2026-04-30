#include <stdio.h>
#include <stdlib.h>
#include "itens.h"

int main () {
    Item *cabeca = NULL;
    int opcao;

    do {
        printf("-----------Menu-----------\n");
        printf("1 - Adicionar item\n");
        printf("2 - Listar itens\n");
        printf("3 - Pesquisar item\n");
        printf("4 - Remover item\n");
        printf("5 - Limpar a tela\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                criarItem(&cabeca);
                break;
            case 2:
                listarItens(cabeca);
                break;
            case 3:
                pesquisarItem(cabeca);
                break;
            case 4:
                removerItem(&cabeca);
                break;
            case 5:
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);

    // Libera a memoria de toda a lista
    limparLista(&cabeca);
    return 0;
}