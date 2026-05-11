#ifndef PECAS_H
#define PECAS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIPOS_PECA "IOTL"
#define CAPACIDADE_FILA 5
#define CAPACIDADE_PILHA 3

typedef struct peca{
    char nome;
    int id;
} Peca;

// Struct que gerencia a fila circular
typedef struct {
    Peca pecas[CAPACIDADE_FILA];
    int inicio;
    int fim;
    int tamanho;
} FilaCircular;

// Struct que gerencia a pilha
typedef struct {
    Peca pecas[CAPACIDADE_PILHA];
    int topo;
} Pilha;

// === INICIALIZAÇÃO ===
void inicializar(FilaCircular *fila, Pilha *pilha);
Peca gerarPeca();

// === FILA CIRCULAR ===
void enfileirar(FilaCircular *fila, Peca peca);
Peca desenfileirar(FilaCircular *fila);

// === PILHA ===
void empilhar(Pilha *pilha, Peca peca);
Peca desempilhar(Pilha *pilha);

// === VISUALIZAÇÃO ===
void mostrarFila(FilaCircular *fila, Pilha *pilha);

// === OPERAÇÕES ===
void trocarPecaFila(FilaCircular *fila, Pilha *pilha);
void trocaMultipla();

#endif