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

/**
 * @brief Função que adiciona um componente na lista
 * @param componentes ponteiro para o array de componentes
 * @param quantidade ponteiro para o tamanho atual do array
 * @param capacidade tamanho maximo do array
 * @return 1 se o componente foi adicionado com sucesso, 0 caso contrário
 */
int adicionarComponente(Componente *componentes, int *quantidade, int capacidade) {
    if (*quantidade >= capacidade) {
        printf("Lista cheia! quantidade máxima de componentes: %d\n", capacidade);
        return 0;
    }

    printf("Digite o nome do componente (no maximo 30 caracteres): ");
    fgets(componentes[*quantidade].nome, 30, stdin);
    removerNewLine(componentes[*quantidade].nome);

    printf("Digite o tipo do componente (no maximo 20 caracteres): ");
    fgets(componentes[*quantidade].tipo, 20, stdin);
    removerNewLine(componentes[*quantidade].tipo);

    do {
        printf("Digite a prioridade do componente (1 a 10): ");
        scanf("%d", &componentes[*quantidade].prioridade);
        getchar();

        if (componentes[*quantidade].prioridade < 0 || componentes[*quantidade].prioridade > 10) {
            printf("Número inválido! Tente novamente.\n");
        }
    } while (componentes[*quantidade].prioridade < 0 || componentes[*quantidade].prioridade > 10);

    (*quantidade)++;

    return 1;
}

/**
 * @brief Função que lista todos os componentes presentes na lista
 * @param componentes ponteiro para o array de componentes
 * @param quantidade tamanho do array
 */
void mostrarComponentes(Componente *componentes, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("-----------------------------------\n");
        printf("%dº Componente:\n", i + 1);
        printf("Nome: %s\n", componentes[i].nome);
        printf("Tipo: %s\n", componentes[i].tipo);
        printf("Prioridade: %d\n", componentes[i].prioridade);
    }
}

/**
 * @brief Função que ordena os componentes por ordem alfabetica do nome
 * @param componentes ponteiro para o array de componentes
 * @param quantidade tamanho do array
 * @param comparacoes ponteiro para o numero de comparacoes
 */
void bubbleSortNome(Componente *componentes, int quantidade, int *comparacoes) {
    *comparacoes = 0;

    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            (*comparacoes)++;

            if (strcmp(componentes[j].nome, componentes[j + 1].nome) > 0) {
                Componente temp = componentes[j];
                componentes[j] = componentes[j + 1];
                componentes[j + 1] = temp;
            }
        }
    }
}

/**
 * @brief Função que ordena os componentes por ordem alfabetica do tipo
 * @param componentes ponteiro para o array de componentes
 * @param quantidade tamanho do array
 * @param comparacoes ponteiro para o numero de comparacoes
 */
void insertionSortTipo(Componente *componentes, int quantidade, int *comparacoes) {
    *comparacoes = 0;

    if (quantidade == 0) {
        printf("A lista esta vazia!\n");
        return;
    }

    for (int i = 1; i < quantidade; i++) {
        Componente chave = componentes[i];
        int j = i - 1;
        // Se o tipo do componente atual for maior que o tipo do componente anterior
        while (j >= 0 && strcmp(componentes[j].tipo, chave.tipo) > 0) {
            (*comparacoes)++;
            componentes[j + 1] = componentes[j];
            j--;
        }
        componentes[j + 1] = chave;
    }
}

/**
 * @brief Função que ordena os componentes por prioridade
 * @param componentes ponteiro para o array de componentes
 * @param quantidade tamanho do array
 * @param comparacoes ponteiro para o numero de comparacoes
 */
void selectionSortPrioridade(Componente *componentes, int quantidade, int *comparacoes) {
    *comparacoes = 0;

    if (quantidade == 0) {
        printf("A lista esta vazia!\n");
        return;
    }

    for (int i = 0; i < quantidade - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < quantidade; j++) {
            (*comparacoes)++;
            if (componentes[j].prioridade < componentes[menor].prioridade) {
                menor = j;
            }
        }
        if (menor != i) {
            Componente temp = componentes[i];
            componentes[i] = componentes[menor];
            componentes[menor] = temp;
        }
    }
}

/**
 * @brief Função que busca um componente pelo nome
 * @param componentes ponteiro para o array de componentes
 * @param quantidade tamanho do array
 * @param nome nome do componente a ser buscado
 */
int buscaBinariaNome(Componente *componentes, int quantidade, char *nome) {    
    int inicio = 0, fim = quantidade - 1, meio = (inicio + fim) / 2;

    while (inicio <= fim) {
        if(strcmp(componentes[meio].nome, nome) == 0) {
            return meio;
        }

        if (strcmp(componentes[meio].nome, nome) > 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }

        meio = (inicio + fim) / 2;
    }

    return -1;
}

/**
 * @brief Mede o tempo de execução de um algoritmo
 * @param algoritmo ponteiro para a funcao do algoritmo
 * @param componentes ponteiro para o array de componentes
 * @param quantidade tamanho do array
 * @param nomeAlgoritmo nome do algoritmo
 */
void medirTempo(
    void (*algoritmo) (Componente *, int, int *), 
    Componente *componentes, 
    int quantidade, 
    const char *nomeAlgoritmo) {

    // Inicialização de variáveis
    int comparacoes = 0;

    clock_t inicio = clock();
    algoritmo(componentes, quantidade, &comparacoes);
    clock_t fim = clock();

    double tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("\n Desempenho - %s\n", nomeAlgoritmo);
    printf(" Comparacoes realizadas: %d\n", comparacoes);
    printf(" Tempo de execucao:      %.6f segundos\n", tempo);
}