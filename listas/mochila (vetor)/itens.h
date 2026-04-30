#ifndef ITENS_H
#define ITENS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct contendo os dados do item
typedef struct item {
    char nome[30];
    char tipo[20];	
    int quantidade;
} Item;

// Protótipos das funções
int adicionarItem(Item *itens, int *quantidade, int capacidade);
void listarItens(Item *itens, int quantidade);
int removerItem(Item *itens, int *quantidade);
int pesquisarItem(Item *itens, int quantidade);


#endif