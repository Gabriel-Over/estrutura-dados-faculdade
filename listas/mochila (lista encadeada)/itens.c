#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itens.h"

/**
 * @brief Funcao que cria um item e adiciona na lista, colocando-o na cabeça da lista
 * @param cabeca ponteiro para a cabeca da lista
 */
void criarItem(Item **cabeca) {
    // Aloca memoria para o novo item
    char nome[30];
    char tipo[20];
    int quantidade;
    
    printf("Digite o nome do item (no maximo 30 caracteres): ");
    fgets(nome, 30, stdin);
    printf("Digite o tipo do item (no maximo 20 caracteres): ");
    fgets(tipo, 20, stdin);
    printf("Digite a quantidade do item: ");
    scanf("%d", &quantidade);
    getchar();
    Item *novoItem = (Item *) malloc(sizeof(Item));

    // Insere os dados do item
    strcpy(novoItem->nome, nome);
    strcpy(novoItem->tipo, tipo);
    novoItem->quantidade = quantidade;

    // Insere o item na lista
    novoItem->prox = (*cabeca);
    (*cabeca) = novoItem;
}

/**
 * @brief Funcao que lista todos os itens presentes na lista
 * @param cabeca informa a cabeca da lista
 */
void listarItens(Item *cabeca) {
    if (cabeca == NULL) {
        printf("--------------------------\n");
        printf("Lista vazia!\n");
        return;
    }
    // Percorre a lista imprimindo os itens, caso a lista nao esteja vazia
    while (cabeca != NULL) {
        printf("--------------------------\n");
        printf("Nome: %s", cabeca->nome);
        printf("Tipo: %s", cabeca->tipo);
        printf("Quantidade: %d\n", cabeca->quantidade);
        cabeca = cabeca->prox;
        printf("--------------------------\n");
    }
}

/**
 * @brief Funcao que pesquisa um item na lista pelo nome
 * @param cabeca informa a cabeca da lista
 */
void pesquisarItem(Item *cabeca) {
    if (cabeca == NULL) {
        printf("--------------------------\n");
        printf("Lista vazia!\n");
        return;
    }
    
    char nome[30];

    printf("--------------------------\n");
    printf("Qual item deseja pesquisar: ");
    fgets(nome, 30, stdin);

    // Percorre a lista procurando o item
    while(cabeca != NULL) {
        if (strcmp(cabeca->nome, nome) == 0) {
            printf("--------------------------\n");
            printf("Nome: %s", cabeca->nome);
            printf("Tipo: %s", cabeca->tipo);
            printf("Quantidade: %d\n", cabeca->quantidade);
            printf("--------------------------\n");
            return;
        }
        cabeca = cabeca->prox;
    }
}

/**
 * @brief Funcao que libera a memoria alocada da lista
 * @param cabeca ponteiro para a cabeca da lista
 */
void limparLista(Item **cabeca) {
    if (cabeca == NULL) {
        printf("--------------------------\n");
        printf("Lista vazia!\n");
        return;
    }
    // Se a lista estiver nao estiver vazia, libera a memoria
    while (*cabeca != NULL) {
        Item *temp = (*cabeca);
        (*cabeca) = (*cabeca)->prox;
        free(temp);
    }
}


/**
 * @brief Funcao que remove um item da lista
 * @param cabeca ponteiro para o cabeca da lista
 */
void removerItem(Item **cabeca) {
    // Se a lista estiver vazia, retorna
    if (*cabeca == NULL) {
        printf("--------------------------\n");
        printf("Lista vazia!\n");
        return;
    }

    // Solicita o nome do item
    printf("Qual item deseja remover? (informe o nome): ");
    char nome[30];
    fgets(nome, 30, stdin);

    // Pesquisa por cada item na lista
    for (Item *atual = *cabeca, *anterior = NULL; atual != NULL; atual = atual->prox) {
        // Se o nome for igual ao informado, remove o item
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior == NULL) {
                *cabeca = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            // Libera a memoria
            free(atual);
            printf("Item removido com sucesso!\n");
            return;
        }
        // Atualiza o ponteiro
        anterior = atual;
    }
    printf("Item nao encontrado!\n");
}