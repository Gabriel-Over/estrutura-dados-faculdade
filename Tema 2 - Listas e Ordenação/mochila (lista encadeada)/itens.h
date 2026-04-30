#ifndef ITENS_H
#define ITENS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[30];
    char tipo[20];	
    int quantidade;
    struct no *prox;
} Item;

void criarItem(Item **cabeca);
void listarItens(Item *cabeca);
void pesquisarItem(Item *cabeca);
void removerItem(Item **cabeca);
void limparLista(Item **cabeca);

#endif