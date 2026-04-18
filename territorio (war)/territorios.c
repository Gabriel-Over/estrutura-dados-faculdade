#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "territorios.h"

/**
 * @brief Função que cria um array de Territorios com a quantidade desejada
 * @param quantidade informa o tamanho do array a ser criado
 * @return Um ponteiro para um array de Territorios
 * @details Essa função pergunta ao usuario quantos territorios ele deseja criar e alocacao de memória para o array.
 * Em seguida, ela pergunta ao usuario o nome e a cor de cada um dos territorialios e alocacao para o nome e a cor.
 * Por fim, a função retorna o ponteiro para o array de Territorios.
 */
Territorio *criarTerritorio (int *quantidade) {
    int i;														//Variavel para iteração dos loops
	//Inicio do programa propriamente dito
	printf("---------------- Criacao de territorios ----------------\n");
	//Repete o "formulario" até o ultimo item do vetor
	printf("Quantos territorios voce deseja criar? (no minimo 3): ");
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
    
	printf("------------------------------------------------------\n");
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

/**
 * @brief Função que simula um ataque entre dois territórios
 * @param atacante ponteiro para o território que está atacando
 * @param defensor ponteiro para o território que está sendo atacado
 * @return 1 se o atacante venceu, 0 se o atacante perdeu e -1 se as cores forem iguais
 */
int atacarTerritorio (Territorio *atacante, Territorio *defensor) {
    //Se a cor do atacante e defensor forem a mesma, então não pode atacar
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("Nao pode atacar territorio da mesma cor!\n");
        return -1;
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
        return 1; // Vitoria
    } else {
        printf("DERROTA! O atacante perdeu.\n");
        atacante->tropas -= 1; // Reduz a tropa do atacante
        printf("Tropas restantes do atacante: %d\n", atacante->tropas);
        if (atacante->tropas < 0) atacante->tropas = 0; //Garante que as tropas nao fiquem negativas
        return 0; //Derrota
    }
}

/**
 * @brief Função que atribui uma missão aleatória para um jogador
 * @details Atribui uma missão para um jogador, escolhendo aleatóriamente
 * um item da lista de missões.
 * @param destino ponteiro para a string que irá conter a missão
 * @param missoes lista de strings contendo as missões
 * @param totalMissoes tamanho da lista de missões
 */
void atribuirMissao(char **destino, char *missoes[], int totalMissoes) {
    int indice = rand() % totalMissoes;
    // Aloca memória para a string da missão sorteada
    *destino = (char *) malloc((strlen(missoes[indice]) + 1) * sizeof(char));
    if (*destino != NULL) {
        strcpy(*destino, missoes[indice]);
    }
}

/**
 * @brief Função que verifica se um jogador cumpriu uma missão
 * @details Verifica se um jogador cumpriu uma missão, verificando se a condição
 * da missão foi satisfeita.
 * @param missao string contendo a missão
 * @param mapa array de structs contendo os dados dos territórios
 * @param tamanho tamanho do array de structs
 * @param corJogador string contendo a cor do jogador
 * @param derrotas número de derrotas do jogador
 * @param conquistas número de territórios conquistados pelo jogador
 * @return 1 se o jogador cumpriu a missão, 0 caso contrário
 */
int verificarMissao(char* missao, Territorio* mapa, int tamanho, char* corJogador, int derrotas, int conquistas) {
    // 1. Conquistar X territórios
    if (strstr(missao, "Conquistar") != NULL) {
        int objetivo;
        sscanf(missao, "Conquistar %d territorios", &objetivo);
        
        int cont = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0) cont++;
        }
        return (cont >= objetivo);
    }
    
    // 2. Eliminar cor vermelha
    if (strcmp(missao, "Elimine todas as tropas da cor vermelha") == 0) {
        for (int i = 0; i < tamanho; i++) {
            // Se alguém ainda for vermelho e não for o próprio jogador
            if (strcmp(mapa[i].cor, "Vermelho") == 0 && strcmp(corJogador, "Vermelho") != 0) {
                return 0; // Ainda não ganhou
            }
        }
        return 1; // Ninguém mais é vermelho!
    }
    
    // 3. Não perder mais de X vezes (E ter pelo menos 1 território conquistado além do inicial)
    if (strcmp(missao, "Nao perder mais de 2 vezes") == 0) {
        if (derrotas > 2) return 0; // Perdeu a chance de cumprir essa missão
        return (conquistas >= 1); // Exemplo de condição: ganhar pelo menos uma vez sem exceder derrotas
    }

    // 4. Destruir X exércitos (Conquistas totais)
    if (strcmp(missao, "Destruir 2 exercitos") == 0) {
        return (conquistas >= 2);
    }
    return 0; // Retorna falso por padrão
}