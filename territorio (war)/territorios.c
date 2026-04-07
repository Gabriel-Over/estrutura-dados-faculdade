#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "territorios.h"

Territorio *criarTerritorio (int *quantidade) {
    int i;														//Variavel para iteração dos loops
	//Inicio do programa propriamente dito
	printf("---------------- Criacao de territorios ----------------\n");
	//Repete o "formulario" até o ultimo item do vetor
	printf("Quantos territorios voce deseja criar (no mínimo 3)? ");
	scanf("%d", quantidade);
	//Limpa o buffer
	getchar();
	if (*quantidade < 3) {
	    printf("Por favor, crie pelo menos 3 territorios\n");
	    return NULL;
	}
	
	Territorio *t = malloc((*quantidade) * sizeof(Territorio));
	
	if (t == NULL) {
	    printf("Erro na alocacao de memória\n");
	    exit(1);
	}
	
	for (i = 0; i < *quantidade; i++) {
		//Preenchimento do "formulario"
		printf("%dº Territorio\n", i+1);
		
		printf("Digite o nome do territorio: ");
		fgets(t[i].nome, 30, stdin);
		t[i].nome[strcspn(t[i].nome, "\n")] = 0; // Remove o \n do final
		
		int escolhaCor;
	    printf("Cores possiveis -> 1-Vermelho, 2-Azul 3-Verde 4-Amarelo 5-Roxo 6-Cinza\n");
		printf("Escolha a cor do territorio: ");
		scanf("%d", &escolhaCor);
		
		switch (escolhaCor) {
		    case 1:
		        strcpy(t[i].cor, "Vermelho");
		        break;
		    case 2:
		        strcpy(t[i].cor, "Azul");
		        break;
		    case 3:
		        strcpy(t[i].cor, "Verde");
		        break;
		    case 4:
		        strcpy(t[i].cor, "Amarelo");
		        break;
		    case 5:
		        strcpy(t[i].cor, "Roxo");
		        break;
		    case 6:
		        strcpy(t[i].cor, "Cinza");
		        break;
		    default:
		        printf("Digito invalido! Utilizando a cor cinza ao inves\n");
		        strcpy(t[i].cor, "Cinza");
		        //Limpar o buffer para caso o usuario digite uma letra
		        getchar();
		        break;
		}
		
		printf("Digite a quantidade de tropas do territorio: ");
		scanf("%d", &t[i].tropas);
		
		//Limpa o buffer
		getchar();
		t[i].missao = NULL;
		printf("-----------------------------------------\n");
		
	}
	//Retorna os dados do territorio
	return t;
}

void atacarTerritorio (Territorio *atacante, Territorio *defensor) {
    //Se a cor do atacante e defensor forem a mesma, então não pode atacar
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("Nao pode atacar territorio da mesma cor!\n");
        return;
    }    
    
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;
    
    printf("\n---------------- Resultado dos dados ----------------\n");
    printf("Dado atacante: %d\n", dadoAtacante);
    printf("Dado defensor: %d\n", dadoDefensor);
    printf("\n-----------------------------------------------------\n");
    //Lógica de vitória/derrota
    if (dadoAtacante > dadoDefensor) {
        printf("Vitoria do atacante!\n");
        // Transfere metade das tropas (divisão inteira)
        int tropasTransferidas = atacante->tropas / 2;
        defensor->tropas = tropasTransferidas;
        atacante->tropas -= tropasTransferidas;
        
        //Transfere a cor do atacante para o defensor
        strcpy(defensor->cor, atacante->cor);
        
        printf("Novas tropas - Atacante: %d | Defensor (conquistado): %d\n", atacante->tropas, defensor->tropas);
    } else {
        printf("DERROTA! O atacante perdeu.\n");
        atacante->tropas -= 1; // Reduz a tropa do atacante
        printf("Tropas restantes do atacante: %d\n", atacante->tropas);
    }
    
    // Garante que as tropas não fiquem negativas
    if (defensor->tropas < 0) defensor->tropas = 0;
    if (atacante->tropas < 0) atacante->tropas = 0;

    printf("---------------- Resultado da guerra ----------------\n");
    printf("Tropas atuais -> Atacante: %d | Defensor: %d\n", atacante->tropas, defensor->tropas);
    printf("Cor do territorio defensor: %s\n", defensor->cor);
    printf("Cor do territorio atacante: %s\n", atacante->cor);
    printf("-----------------------------------------\n");
}

void atribuirMissao(char **destino, char *missoes[], int totalMissoes) {
    int indice = rand() % totalMissoes;
    // Aloca memória para a string da missão sorteada
    *destino = (char *) malloc((strlen(missoes[indice]) + 1) * sizeof(char));
    if (*destino != NULL) {
        strcpy(*destino, missoes[indice]);
    }
}

int verificarMissao(char* missao, Territorio* mapa, int tamanho, char* corJogador) {
    // Exemplo: Missão "Conquistar 3 territorios"
    if (strcmp(missao, "Conquistar 3 territorios") == 0) {
        int cont = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0) cont++;
        }
        return (cont >= 3);
    }
    
    // Se não houver territórios dessa cor, ele venceu
    if (strcmp(missao, "Eliminar todas as tropas da cor vermelha") == 0) {
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "Vermelho") == 0) {
                return 1;
            } 
        }
        printf("Nao existe um territorio vermelho, voce venceu\n");
        return 1;
    }
    
    if (strcmp(missao, "Nao perder mais de 2 vezes") == 0) {
        
    }
    return 0; // Retorna falso por padrão
}