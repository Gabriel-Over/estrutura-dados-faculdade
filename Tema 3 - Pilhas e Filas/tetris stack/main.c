#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pecas.h"

int main () {
    srand((unsigned)time(NULL));

    FilaCircular fila;
    inicializarFila(&fila);
    int opcao;

    do {
        printf("------------------------------\n");
        mostrarFila(&fila);
        printf("------------------------------\n");
        printf("1 - Inserir nova peca (enqueue)\n");
        printf("2 - Jogar uma peca (dequeue)\n");
        printf("0 - Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);
        printf("------------------------------\n");

        switch (opcao) {
            case 1:
                gerarPecas(&fila);
                break;
            case 2:
                jogarPeca(&fila);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}