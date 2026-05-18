#include "pecas.h"

// Variavel global estatica limitando o escopo a este arquivo
static int id = 0;

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
    
    return nova;
}

void enfileirar(FilaCircular *fila, Peca peca) {
    if (fila->tamanho == CAPACIDADE_FILA) {
        printf("Fila circular cheia!\n");
        return;
    }
    
    // Atualiza os controles
    fila->pecas[fila->fim] = peca;
    fila->fim = (fila->fim + 1) % CAPACIDADE_FILA;   // Logica circular
    fila->tamanho++;
}

/**
 * @brief Insere uma peça no final da fila circular.
 *        Não faz nada se a fila estiver cheia.
 */
Peca desenfileirar(FilaCircular *fila) {
    // Armazena o valor da peca inicial (aquela que sera removida)
    Peca p = fila->pecas[fila->inicio];

    fila->inicio = (fila->inicio + 1) % CAPACIDADE_FILA;   // Logica circular
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
        int idx = (fila->inicio + i) % CAPACIDADE_FILA;
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

/**
 * @brief Troca as peças da fila circular e da pilha
 * @param fila ponteiro para a fila
 * @param pilha ponteiro para a pilha
 */
void trocarPecaFila(FilaCircular *fila, Pilha *pilha) {
    if (fila->tamanho == 0) {
        printf("Fila vazia!\n");
        return;
    }
    if (pilha->topo == -1) {
        printf("Pilha vazia!\n");
        return;
    }
    Peca da_fila  = desenfileirar(fila);
    Peca da_pilha = desempilhar(pilha);
    
    /*
     * Reinsere em posições opostas:
     * - peça que estava na fila vai para o topo da pilha
     * - peça que estava na pilha vai para o final da fila
     *
     * Para colocar a peça da pilha na FRENTE da fila (posição original),
     * é necessario reconstruir a fila com ela na frente.
     * Estratégia: esvaziar temporariamente, inserir a nova frente, reinserir as demais.
     */
    Peca temp[CAPACIDADE_FILA];
    int restante = fila->tamanho;

    for (int i = 0; i < restante; i++) {
        temp[i] =desenfileirar(fila);
    }

    /* Reconstrói: primeiro a peça vinda da pilha (nova frente) */
    enfileirar(fila, da_pilha);
    for (int i = 0; i < restante; i++) {
        enfileirar(fila, temp[i]);
    }

    /* Peça que saiu da fila vai para a pilha */
    empilhar(pilha, da_fila);
 
    printf("Troca realizada: [%c %d] (fila) <-> [%c %d] (pilha)\n",
           da_fila.nome,  da_fila.id,
           da_pilha.nome, da_pilha.id);

}

/**
 * @brief Troca as 3 primeiras peças da fila com as 3 peças da pilha (fila ↔ pilha).
 *        Requer fila.tamanho >= 3 e pilha cheia (3 peças).
 *
 * As 3 peças do topo da pilha vão para a frente da fila (na mesma ordem de topo→base).
 * As 3 peças da frente da fila vão para a pilha (a primeira da fila fica no topo).
 */
void trocaMultipla(FilaCircular *fila, Pilha *pilha) {
    if (fila->tamanho < 3) {
        printf("Fila precisa ter ao menos 3 pecas para troca multipla.\n");
        return;
    }
    if (pilha->topo != CAPACIDADE_PILHA - 1) {
        printf("Pilha precisa estar cheia (3 pecas) para troca multipla.\n");
        return;
    }
 
    /* Retira as 3 primeiras da fila */
    Peca da_fila[3];
    for (int i = 0; i < 3; i++) {
        da_fila[i] = desenfileirar(fila);
    }
 
    /* Retira as 3 da pilha (topo → base: índices 2, 1, 0) */
    Peca da_pilha[3];
    for (int i = 0; i < 3; i++) {
        da_pilha[i] = desempilhar(pilha); /* da_pilha[0] = topo original */
    }
 
    /*
     * Reconstrói a fila: peças da pilha vão para a frente.
     * da_pilha[2] era a base → vai ser a nova posição 0 da frente?
     * Mantemos a ordem lógica: topo da pilha vira frente da fila.
     * Então: da_pilha[0](era topo), da_pilha[1], da_pilha[2](era base).
     */
    Peca restante_fila[CAPACIDADE_FILA];
    int qtd_restante = fila->tamanho;
    for (int i = 0; i < qtd_restante; i++) {
        restante_fila[i] = desenfileirar(fila);
    }
 
    /* Insere as 3 da pilha na frente */
    for (int i = 0; i < 3; i++) {
        enfileirar(fila, da_pilha[i]);
    }
    /* Reinsere o restante */
    for (int i = 0; i < qtd_restante; i++) {
        enfileirar(fila, restante_fila[i]);
    }
 
    /*
     * Empilha as 3 que saíram da fila.
     * A frente da fila (da_fila[0]) deve ficar no TOPO da pilha após a troca,
     * então empilhamos de trás para frente: da_fila[2] primeiro, da_fila[0] por último.
     */
    for (int i = 2; i >= 0; i--) {
        empilhar(pilha, da_fila[i]);
    }
 
    printf("Troca multipla realizada!\n");
    printf("  Fila recebeu (nova frente): [%c %d] [%c %d] [%c %d]\n",
           da_pilha[0].nome, da_pilha[0].id,
           da_pilha[1].nome, da_pilha[1].id,
           da_pilha[2].nome, da_pilha[2].id);
    printf("  Pilha recebeu (novo topo):  [%c %d] [%c %d] [%c %d]\n",
           da_fila[0].nome,  da_fila[0].id,
           da_fila[1].nome,  da_fila[1].id,
           da_fila[2].nome,  da_fila[2].id);
}
