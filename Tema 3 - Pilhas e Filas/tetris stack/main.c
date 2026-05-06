#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pecas.h"

int main () {
    srand((unsigned)time(NULL));
    FilaCircular fila;
    Pilha pilha;
    int opcao;

    inicializar(&fila, &pilha);
    
    // Inicializa a fila com 5 peças
    for (int i = 0; i < ELEMENTOS_FILA; i++) {
        enfileirar(&fila, gerarPeca());
    }
    do {
        printf("------------------------------\n");
        mostrarFila(&fila, &pilha);
        printf("------------------------------\n");
        printf("1 - Jogar uma peca\n");
        printf("2 - Reservar uma peca\n");
        printf("3 - Usar peca reservada\n");
        printf("0 - Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);
        printf("------------------------------\n");

        switch (opcao) {
            case 1:
                desenfileirar(&fila);
                enfileirar(&fila, gerarPeca());
                printf("Peca jogada com sucesso!\n");
                break;
            case 2:
                if (pilha.topo < CAPACIDADE_PILHA - 1) {
                    Peca p = desenfileirar(&fila);
                    empilhar(&pilha, p);

                    printf("Peca reservada com sucesso!\n");
                    break;
                }
                printf("Pilha cheia!\n");
                break;
            case 3:
                if (pilha.topo == -1) {
                    printf("Pilha vazia!\n");
                    break;
                }

                Peca p = desempilhar(&pilha);
                enfileirar(&fila, p);
                printf("Peca usada com sucesso!\n");
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