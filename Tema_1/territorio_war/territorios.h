#ifndef TERRITORIOS_H
#define TERRITORIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct contendo os dados do territorio
typedef struct terr {
	char nome[30];
	char cor[10];	
	int tropas;    
	char *missao;
} Territorio;

//Protótipos
Territorio *criarTerritorio (int *quantidade);
int atacarTerritorio (Territorio *atacante, Territorio *defensor);
void atribuirMissao(char **destino, char *missoes[], int totalMissoes);
int verificarMissao(char* missao, Territorio* mapa, int tamanho, char* corJogador, int derrotas, int conquistas);

#endif