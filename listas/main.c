#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct contendo os dados de um item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

/**
 * @brief Função que remove um item da lista
 * @param itens ponteiro para o array de itens
 * @param quantidade informa o tamanho do array
 */
void removerItem(Item *itens, int quantidade) {
    char nome[30];
    printf("Remova um item da lista (informe o nome): ");
    fgets(nome, 30, stdin);

    // Remove o item
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(itens[i].nome, nome) == 0) {
            for (int j = i; j < quantidade - 1; j++) {
                itens[j] = itens[j + 1];
            }
            quantidade--;
            break;
        }
    }
}

/**
 * @brief Função que lista todos os itens presentes na lista
 * @param itens ponteiro para o array de itens
 * @param quantidade informa o tamanho do array
 */
void listarItens(Item *itens, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("%dº Item:\n");
        printf("Nome: %s", itens[i].nome);
        printf("Tipo: %s", itens[i].tipo);
        printf("Quantidade: %d\n", itens[i].quantidade);
    }
}

/** 
 * @brief Função que pesquisa um item pelo nome
 * @param itens ponteiro para o array de itens
 * @param quantidade informa o tamanho do array
 */
void pesquisarItens(Item *itens, int quantidade) {
    char nome[30];
    printf("Digite o nome do item que deseja pesquisar: ");
    fgets(nome, 30, stdin);
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(itens[i].nome, nome) == 0) {
            printf("Nome: %s", itens[i].nome);
            printf("Tipo: %s", itens[i].tipo);
            printf("Quantidade: %d\n", itens[i].quantidade);
            break;
        }
    }
}

int main () {
    // Variaveis
    int quantidade = 0;
    int opcao;

    // Solicita ao usuário a quantidade de itens
    do {
        printf("Quantos items você deseja criar? (1-10): ");
        scanf("%d", &quantidade);
        getchar(); // Limpa o buffer
        if (quantidade < 1 || quantidade > 10) {
            printf("Quantidade inválida!\n");
        }
    } while (quantidade < 1 || quantidade > 10);

    // Cria um array de itens
    Item itens[quantidade];

    // Preenche o array
    for (int i = 0; i < quantidade; i++) {
        printf("Digite o nome do item %d: ", i + 1);
        fgets(itens[i].nome, 30, stdin);
        printf("Digite o tipo do item %d: ", i + 1);
        fgets(itens[i].tipo, 20, stdin);
        printf("Digite a quantidade do item %d: ", i + 1);
        scanf("%d", &itens[i].quantidade);
        getchar();
        printf("\n");
    }

    // Imprime o array
    for (int i = 0; i < quantidade; i++) {
        printf("Item %d: %s - %s - %d\n", 
            i + 1, itens[i].nome, itens[i].tipo, itens[i].quantidade);
    }

    // Menu de opções
    int rodando = 1;
    do {
        printf("-----------------------------------\n");
        printf("1 - Listar todos os itens\n");
        printf("2 - Pesquisar item\n");
        printf("3 - Remover item\n");
        printf("0 - Sair\n");
        printf("Qual opção você deseja tomar:\n");
        scanf("%d", &opcao);
        getchar();
        printf("-----------------------------------\n");

        switch (opcao){
            case 1:
                listarItens(itens, quantidade);
                break;
            case 2:
                pesquisarItens(itens, quantidade);
                break;
            case 3:
                removerItem(itens, quantidade);
                break;
            default:
                printf("Saindo...\n");
                rodando = 0;
                break;
        }
    } while(rodando);

    return 0;
}