#include "pecas.h"

int id = 0;

/**
 * @brief Inicia os controles da fila circular
 * @param fila ponteiro para a fila
 */
void inicializar(FilaCircular *fila, Pilha *pilha) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    pilha->topo = -1;
}

/**
 * @brief Insere uma nova peca na fila circular
 * @return Nova peca
 */
Peca gerarPeca() {
    Peca nova;

    // Sorteia o tipo de peca
    int nAleatorio = rand() % 4;

    // Insere no final atual da fila circular
    nova.nome = TIPOS_PECA[nAleatorio];
    nova.id = id++;
    
    printf("Peca inserida com sucesso!\n");
    
    return nova;
}

void enfileirar(FilaCircular *fila, Peca peca) {
    if (fila->tamanho == ELEMENTOS_FILA) {
        printf("Fila circular cheia!\n");
        return;
    }
    
    // Atualiza os controles
    fila->pecas[fila->fim] = peca;
    fila->fim = (fila->fim + 1) % ELEMENTOS_FILA;   // Logica circular
    fila->tamanho++;
}

/**
 * @brief Remove uma peca da fila circular
 * @param fila ponteiro para a fila
 */
Peca desenfileirar(FilaCircular *fila) {
    // Armazena o valor da peca inicial (aquela que sera removida)
    Peca p = fila->pecas[fila->inicio];

    fila->inicio = (fila->inicio + 1) % ELEMENTOS_FILA;   // Logica circular
    fila->tamanho--;
    return p;
}

/**
 * @brief Empilha uma peca na pilha
 * @param pilha ponteiro para a pilha
 * @param peca peca a ser empilhada, nesse caso, aquela que foi removida da fila
 */
void empilhar(Pilha *pilha, Peca peca) {
    if (pilha->topo == CAPACIDADE_PILHA - 1) {
        printf("Pilha cheia!\n");
        return;
    }
    
    pilha->pecas[++(pilha->topo)] = peca;
    printf("Peca empilhada com sucesso!\n");
}

/**
 * @brief Desempilha uma peca da pilha
 * @param pilha ponteiro para a pilha
 * @return Peca desempilhada
 */
Peca desempilhar(Pilha *pilha) {
    Peca p = pilha->pecas[pilha->topo--];
    return p;
}

/**
 * @brief Mostra a fila circular
 * @param fila ponteiro para a fila
 */
void mostrarFila(FilaCircular *fila, Pilha *pilha) {
    printf("\n--- ESTADO ATUAL ---\n");
    
    // Exibir Fila
    printf("Fila de pecas: ");
    for (int i = 0; i < fila->tamanho; i++) {
        int idx = (fila->inicio + i) % ELEMENTOS_FILA;
        printf("[%c %d] ", fila->pecas[idx].nome, fila->pecas[idx].id);
    }
    
    // Exibir Pilha (do topo para a base)
    printf("\nPilha de reserva (Topo -> Base): ");
    if (pilha->topo == -1) printf("(vazia)");
    for (int i = pilha->topo; i >= 0; i--) {
        printf("[%c %d] ", pilha->pecas[i].nome, pilha->pecas[i].id);
    }
    printf("\n--------------------\n");
}