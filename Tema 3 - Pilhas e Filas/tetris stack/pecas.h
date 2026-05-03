#ifndef PECAS_H
#define PECAS_H

#include <stdio.h>
#include <stdlib.h>

#define TIPOS_PECA "IOTL"
#define CAPACIDADE 5

typedef struct peca{
    char nome;
    int id;
} Peca;

// Struct que gerencia a fila circular
typedef struct {
    Peca pecas[CAPACIDADE];
    int inicio;
    int fim;
    int tamanho;
    int proxId;
} FilaCircular;

// Protótipos das funções
void inicializarFila(FilaCircular *fila);
void gerarPecas(FilaCircular *fila);
void jogarPeca(FilaCircular *fila);
void mostrarFila(FilaCircular *fila);

#endif