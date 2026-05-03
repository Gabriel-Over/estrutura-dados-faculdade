#include "pecas.h"

/**
 * @brief Inicia os controles da fila circular
 * @param fila ponteiro para a fila
 */
void inicializarFila(FilaCircular *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->proxId = 0;
}

/**
 * @brief Insere uma nova peca na fila circular
 * @param fila ponteiro para a fila
 */
void gerarPecas(FilaCircular *fila) {
    // Verifica se a capacidade foi atingida
    if (fila->tamanho >= CAPACIDADE) {
        printf("Capacidade maxima atingida!\n");
        return;
    }
    // Sorteia o tipo de peca
    int nAleatorio = rand() % 4;

    // Insere no final atual da fila circular
    fila->pecas[fila->fim].nome = TIPOS_PECA[nAleatorio];
    fila->pecas[fila->fim].id = fila->proxId;                  
    
    // Atualiza controles
    fila->proxId++;
    fila->fim = (fila->fim + 1) % CAPACIDADE;   // Incremento circular
    fila->tamanho++;

    printf("Peca inserida com sucesso!\n");
}

/**
 * @brief Remove uma peca da fila circular
 * @param fila ponteiro para a fila
 */
void jogarPeca(FilaCircular *fila) {
    if (fila->tamanho == 0) {
        printf("Nenhuma peca na fila!\n");
        return;
    }

    Peca pecaRemovida = fila->pecas[fila->inicio];
    printf("Jogando peca [%c %d]...\n", pecaRemovida.nome, pecaRemovida.id);
    fila->inicio = (fila->inicio + 1) % CAPACIDADE;
    fila->tamanho--;
}

/**
 * @brief Mostra a fila circular
 * @param fila ponteiro para a fila
 */
void mostrarFila(FilaCircular *fila) {
    if (fila->tamanho == 0) {
        printf("Fila de pecas: (vazia)\n");
        return;
    }

    printf("Fila de pecas: ");
    for (int i = 0; i < fila->tamanho; i++) {
        // Mapeia o índice virtual 'i' para a posição física real no vetor circular
        int indiceReal = (fila->inicio + i) % CAPACIDADE;
        printf("[%c %d] ", fila->pecas[indiceReal].nome, fila->pecas[indiceReal].id);
    }
    printf("\n");
}