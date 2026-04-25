#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itens.h"

/**
 * @brief remove o '\n' deixado pelo fgets
 * @param str recebe uma string
 */
static void removerNewLine(char *str) {
    int tamanho = strlen(str);
    if (tamanho > 0 && str[tamanho - 1] == '\n') {
        str[tamanho - 1] = '\0';
    }
}

/**
 * @brief Função que adiciona um item na lista
 * @param itens ponteiro para o array de itens
 * @param quantidade ponteiro para o tamanho atual do array
 * @param capacidade tamanho maximo do array
 * @return 1 se o item foi adicionado com sucesso, 0 caso contrário
 */
int adicionarItem(Item *itens, int *quantidade, int capacidade) {
    if (*quantidade >= capacidade) {
        printf("A mochila esta cheia!\n");
        return 0;
    }

    printf("Digite o nome do item (no maximo 30 caracteres): ");
    fgets(itens[*quantidade].nome, 30, stdin);
    removerNewLine(itens[*quantidade].nome);

    printf("Digite o tipo do item (no maximo 20 caracteres): ");
    fgets(itens[*quantidade].tipo, 20, stdin);
    removerNewLine(itens[*quantidade].tipo);

    printf("Digite a quantidade do item: ");
    scanf("%d", &itens[*quantidade].quantidade);
    getchar();

    (*quantidade)++;
    printf("Item adicionado com sucesso\n");
    return 1;
}

/**
 * @brief Função que remove um item da lista
 * @param itens ponteiro para o array de itens
 * @param quantidade ponteiro para o tamanho atual do array
 * @return 1 se o item foi removido com sucesso, 0 caso contrário
 */
int removerItem(Item *itens, int *quantidade) {
    if (*quantidade == 0) {
        printf("Lista vazia!\n");
        return 0;
    }

    char nome[30];

    printf("Remova um item da lista (informe o nome): ");
    fgets(nome, 30, stdin);
    removerNewLine(nome);

    // Verifica se o nome do item foi encontrado, e depois substitui o item pelo item seguinte
    // e diminui o tamanho do array 
    for (int i = 0; i < *quantidade; i++) {
        if (strcmp(itens[i].nome, nome) == 0) {
            for (int j = i; j < *quantidade - 1; j++) {
                itens[j] = itens[j + 1];
            }
            (*quantidade)--;
            printf("Item \"%s\" removido com sucesso!\n", nome);
            return 1;
        }
    }
    // Caso nao encontre o item
    printf("Item \"%s\" nao encontrado!\n", nome);
    return 0;
}

/**
 * @brief Função que lista todos os itens presentes na lista
 * @param itens ponteiro para o array de itens
 * @param quantidade ponteiro para o tamanho atual do array
 */
void listarItens(Item *itens, int quantidade) {
    if (quantidade == 0) {
        printf("A lista esta vazia!\n");
        return;
    }
    
    for (int i = 0; i < quantidade; i++) {
        printf("-----------------------------------\n");
        printf("%dº Item:\n", i + 1);
        printf("Nome: %s\n", itens[i].nome);
        printf("Tipo: %s\n", itens[i].tipo);
        printf("Quantidade: %d\n", itens[i].quantidade);
    }
}

/** 
 * @brief Função que pesquisa um item pelo nome
 * @param itens ponteiro para o array de itens
 * @param quantidade ponteiro para o tamanho atual do array
 * @return 1 se o item foi encontrado, 0 caso contrário
 */
int pesquisarItens(Item *itens, int quantidade) {
    if (quantidade == 0) {
        printf("A lista esta vazia!\n");
        return 0;
    }

    char nome[30];

    printf("Digite o nome do item que deseja pesquisar: ");
    fgets(nome, 30, stdin);
    removerNewLine(nome);

    // Verifica se o item foi encontrado, se sim, imprime seus dados
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(itens[i].nome, nome) == 0) {
            printf("-----------------------------------\n");
            printf("Nome: %s\n", itens[i].nome);
            printf("Tipo: %s\n", itens[i].tipo);
            printf("Quantidade: %d\n", itens[i].quantidade);
            return 1;
        }
    }

    // Caso o item nao seja encontrado
    printf("Item \"%s\" nao encontrado!\n", nome);
    return 0;
}

