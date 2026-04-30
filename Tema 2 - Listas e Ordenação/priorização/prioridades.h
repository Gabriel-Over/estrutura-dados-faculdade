#ifndef PRIORIDADES_H
#define PRIORIDADES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMP 20

//Struct contendo os dados do componente
typedef struct cmp {
    char nome[30];
    char tipo[20];	
    int prioridade;
} Componente;

// === CADASTRO ===
int adicionarComponente(Componente *componentes, int *quantidade, int capacidade);
void mostrarComponentes(Componente *componentes, int quantidade);

// === ORDENAÇÃO ===
void bubbleSortNome(Componente *componentes, int quantidade, int *comparacoes);
void insertionSortTipo(Componente *componentes, int quantidade, int *comparacoes);
void selectionSortPrioridade(Componente *componentes, int quantidade, int *comparacoes);

// === BUSCA ===
int buscaBinariaNome(Componente *componentes, int quantidade, char *nome); // Aplicavel somente após a ordenação por nome

// === DESEMPENHO ===
void medirTempo(
    void (*algoritmo) (Componente *, int, int *), // Isso é um ponteiro para as funções de ordenação
    Componente *componentes,
    int quantidade,
    const char *nomeAlgoritmo
);

#endif