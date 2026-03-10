#include <stdio.h>
#include <locale.h>

//Struct contendo os dados do territorio
typedef struct exc {
	char nome[30];	//Nome pode ter no maximo 30 caracteres
	char cor[10];	//Cor pode ter no maximo 10 caracteres
	int tropas;	
} Territorio;		//Nome da struct

int main () {
	//Permite o console imprimir caracteres da língua portuguesa, desnecessário pro funcionamento mas deixa mais bonito
	setlocale(LC_ALL, "Portuguese");
	
	//Declaração do vetor territorio com 5 espaços
	Territorio territorio[5];
	
	//Variaveis
	int tamanho = sizeof(territorio) / sizeof(territorio[0]);	//Tamanho do vetor
	int i;														//Variavel para iteração dos loops
	char gambiarra[2];											//Serve pra não pular o input
	
	//Inicio do programa propriamente dito
	printf("---------------- Criação de territorios ----------------\n");
	//Repete o "formulario" até o ultimo item do vetor
	for (i = 0; i < tamanho; i++) {
		//Isso aqui é uma forma de solucionar um problema em que, no segundo loop, o input pro nome do territorio é pulado
		if (i > 0) fgets(gambiarra, 2, stdin);
		
		//Preenchimento do "formulario"
		printf("%dº Territorio\n", i+1);
		printf("Digite o nome do territorio: ");
		fgets(territorio[i].nome, 30, stdin);
		printf("Digite a cor do territorio: ");
		fgets(territorio[i].cor, 10, stdin);
		printf("Digite a quantidade de tropas do territorio: ");
		scanf("%d", &territorio[i].tropas);
		printf("-----------------------------------------\n");
		
	}
	//Imprime todos os dados dos territorios
	for (i = 0; i < tamanho; i++) {
		printf("-----------------------------------------\n");
		printf("%dº Territorio\n", i+1);
		printf("Nome: %s", territorio[i].nome);
		printf("Cor: %s", territorio[i].cor);
		printf("Tropas: %d\n", territorio[i].tropas);
	}
	
	return 0;
}
