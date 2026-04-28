#ifndef ITENS_H
#define ITENS_H

//Struct contendo os dados do item
typedef struct item {
    char nome[30];
    char tipo[20];	
    int quantidade;
} Item;

// Protótipos das funções
int adicionarItem(Item *itens, int *quantidade, int capacidade);
int removerItem(Item *itens, int *quantidade);
int pesquisarItem(Item *itens, int quantidade);
void listarItens(Item *itens, int quantidade);

#endif