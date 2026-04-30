#include "itens.h"

/**
 * @brief Remove o '\n' deixado pelo fgets
 * @param str recebe uma string
 */
static void removerNewLine(char *str) {
    int tamanho = strlen(str);
    if (tamanho > 0 && str[tamanho - 1] == '\n') {
        str[tamanho - 1] = '\0';
    }
}
/**
 * @brief Formata o primeiro caractere da string para maiusculo e os demais para minusculo
 * @param nome recebe uma string
 */
static void formatarNome(char *nome) {
    // Se o primeiro caractere for uma letra minuscula, transforma em maiuscula
    if (nome[0] >= 'a' && nome[0] <= 'z') {
            nome[0] -= 32;
    }

    int tamanho = strlen(nome);

    // Se os demais caracteres forem maiusculos, transforma em minusculos
    for (int i = 1; i < tamanho; i++) {
        if (nome[i] >= 'A' && nome[i] <= 'Z') {
            nome[i] += 32;
        }
    }
}

/**
 * @brief Funcao que ordena os itens por nome utilizando o bubble sort
 * @param itens ponteiro para o array de itens
 * @param quantidade informa o tamanho atual do array
 */
static void ordenarPorNome(Item *itens, int quantidade) {
    if (quantidade == 0) {
        printf("A lista esta vazia!\n");
        return;
    }

    printf("Ordenando por nome...\n");
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - 1 - i; j++) {
            // Compara o primeiro caractere do nome, se for maior, troca
            if (strcmp(itens[j].nome, itens[j + 1].nome) > 0) {
                // Aqui ocorre a substituição dos dados
                Item temp = itens[j];
                itens[j] = itens[j + 1];
                itens[j + 1] = temp;
            }
        }
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
    formatarNome(itens[*quantidade].nome);

    printf("Digite o tipo do item (no maximo 20 caracteres): ");
    fgets(itens[*quantidade].tipo, 20, stdin);
    removerNewLine(itens[*quantidade].tipo);
    formatarNome(itens[*quantidade].tipo);

    printf("Digite a quantidade do item: ");
    scanf("%d", &itens[*quantidade].quantidade);
    getchar();

    (*quantidade)++;
    printf("Item adicionado com sucesso\n");

    ordenarPorNome(itens, *quantidade);

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
int pesquisarItem(Item *itens, int quantidade) {
    if (quantidade == 0) {
        printf("A lista esta vazia!\n");
        return 0;
    }

    char nome[30];

    printf("Digite o nome do item que deseja pesquisar: ");
    fgets(nome, 30, stdin);
    removerNewLine(nome);
    formatarNome(nome);

    // Utiliza a busca binária paraa encontrar o item
    int inicio = 0, fim = quantidade - 1, meio = (inicio + fim) / 2;
    while (inicio <= fim) {
        if (strcmp(itens[meio].nome, nome) == 0) {
            printf("-----------------------------------\n");
            printf("%dº Item:\n", meio + 1);
            printf("Nome: %s\n", itens[meio].nome);
            printf("Tipo: %s\n", itens[meio].tipo);
            printf("Quantidade: %d\n", itens[meio].quantidade);
            return 1;
        } else if (strcmp(itens[meio].nome, nome) > 0) {
            fim = meio - 1;
            meio = (inicio + fim) / 2;
        } else {
            inicio = meio + 1;
            meio = (inicio + fim) / 2;
        }
    }

    // Caso o item nao seja encontrado
    printf("Item \"%s\" nao encontrado!\n", nome);
    return 0;
}
