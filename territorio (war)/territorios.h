#ifndef TERRITORIOS_H
#define TERRITORIOS_H

//Struct contendo os dados do territorio
typedef struct terr {
	char nome[30];
	char cor[10];	
	int tropas;    
	char *missao;
} Territorio;

//Protótipos
Territorio *criarTerritorio (int *quantidade);
void atacarTerritorio (Territorio *atacante, Territorio *defensor);
void atribuirMissao(char **destino, char *missoes[], int totalMissoes);
int verificarMissao(char* missao, Territorio* mapa, int tamanho, char* corJogador);

#endif