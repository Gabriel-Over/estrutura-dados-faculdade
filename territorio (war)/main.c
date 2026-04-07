#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "territorios.h"

//Struct contendo os dados do territorio
int main () {
	//Permite o console imprimir caracteres da língua portuguesa, desnecessário pro funcionamento mas deixa mais bonito
	srand(time(NULL));
	
	//Variaveis
	int i;
	int tamanho;
	int quantidade = 0;
	Territorio *territorios = NULL;
	char *poolMissoes[] = {
        "Conquistar 3 territorios",
        "Nao perder mais de 2 vezes",
        "Elimine todas as tropas da cor vermelha",
        "Destruir 2 exercitos",
        "Conquistar 18 territorios"
    };
    int totalMissoes = 5;
	
	//Criação de territorios, caso não consiga criar, ele continua no loop
	do {
	    territorios = criarTerritorio(&quantidade);
	} while (territorios == NULL);
	
	//Imprime todos os dados dos territorios
	for (i = 0; i < quantidade; i++) {
		printf("-----------------------------------------\n");
		printf("%dº Territorio\n", i+1);
		printf("Nome: %s\n", territorios[i].nome);
		printf("Cor: %s\n", territorios[i].cor);
		printf("Tropas: %d\n", territorios[i].tropas);
	}
	
	bool rodando = true;
	int atacante, defensor;
	
	// Atribuindo missão ao "Jogador 1" (dono do primeiro território criado)
    atribuirMissao(&territorios[0].missao, poolMissoes, totalMissoes);
    printf("\nSua Missão (1º território): %s\n", territorios[0].missao);
	
	while (rodando) {
    	printf("\n--- Turno de Ataque ---\n");
        printf("Indice do atacante (1 a %d): ", quantidade);
        scanf("%d", &atacante);
        printf("Indice do defensor: ");
        scanf("%d", &defensor);

        if (atacante > 0 && atacante <= quantidade && defensor > 0 && defensor <= quantidade) {
            // Realiza o ataque
            // atacarTerritorio(&territorios[atacante-1], &territorios[defensor-1]);
            
            // Verificação Condicional de Vitória
            if (verificarMissao(territorios[0].missao, territorios, quantidade, territorios[0].cor)) {
                printf("\n====================================\n");
                printf("PARABÉNS! A missão [%s] foi cumprida!\n", territorios[0].missao);
                printf("====================================\n");
                rodando = false;
            } else {
                printf("\nMissão ainda não cumprida. Próximo turno...\n");
                // Para testes, vamos sair após o primeiro turno se não quiser loop infinito
                printf("Deseja continuar? (1-Sim / 0-Sair): ");
                int cont; scanf("%d", &cont);
                if (cont == 0) rodando = false;
            }
        }
	}
	
	// Liberação de memória
    for(int i = 0; i < quantidade; i++) {
        if(territorios[i].missao != NULL) free(territorios[i].missao);
    }
    free(territorios);
	return 0;
}