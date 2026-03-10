#include <stdio.h>
#include <locale.h>

typedef struct exc {
	char nome[30];
	char cor[10];
	int tropas;
} Territorio;

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	Territorio territorio[5];
	
	int tamanho = sizeof(territorio) / sizeof(territorio[0]);
	int i;
	//Serve pra não pular o input
	char gambiarra[2];
	
	printf("---------------- Criação de territorios ----------------\n");
	
	for (i = 0; i < tamanho; i++) {
		
		if (i > 0) fgets(gambiarra, 2, stdin);
		
		printf("Digite o nome do territorio: ");
		fgets(territorio[i].nome, 30, stdin);
		printf("Digite a cor do territorio: ");
		fgets(territorio[i].cor, 10, stdin);
		printf("Digite a quantidade de tropas do territorio: ");
		scanf("%d", &territorio[i].tropas);
		printf("\n");
	}
	
	for (i = 0; i < tamanho; i++) {
		printf("-----------------------------------------\n");
		printf("Territorio %d:\n", i);
		printf("Nome: %s", territorio[i].nome);
		printf("Cor: %s", territorio[i].cor);
		printf("Tropas: %d\n", territorio[i].tropas);
	}
	
	return 0;
}
