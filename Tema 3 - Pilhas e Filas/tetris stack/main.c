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
    
    printf("Inicializando fila com %d pecas...\n", CAPACIDADE_FILA);
    // Inicializa a fila com 5 peças
    for (int i = 0; i < CAPACIDADE_FILA; i++) {
        enfileirar(&fila, gerarPeca());
    }
    do {
        printf("------------------------------\n");
        mostrarFila(&fila, &pilha);
        printf("------------------------------\n");
        printf("1 - Jogar uma peca\n");
        printf("2 - Reservar uma peca\n");
        printf("3 - Usar peca reservada\n");
        printf("4 - Trocar peca (tirar um da fila e substituir pela da pilha)\n");
        printf("5 - Troca múltipla (tirar 3 da fila e 3 da pilha)\n");
        printf("6 - Limpar tela\n");
        printf("0 - Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);
        printf("------------------------------\n");

        switch (opcao) {
            case 1: {
                /* Joga (descarta) a peça da frente; gera uma nova para manter a fila cheia */
                Peca descartada = desenfileirar(&fila);
                printf("Peca [%c %d] jogada e descartada.\n", descartada.nome, descartada.id);
 
                Peca nova = gerarPeca();
                enfileirar(&fila, nova);
                printf("Nova peca gerada automaticamente: [%c %d]\n", nova.nome, nova.id);
                break;
            }

            case 2: {
                /* Move a frente da fila para a pilha */
                if (pilha.topo == CAPACIDADE_PILHA - 1) {
                    printf("Pilha cheia! Nao e possivel reservar.\n");
                    break;
                }
                Peca p = desenfileirar(&fila);

                empilhar(&pilha, p);
                
                enfileirar(&fila, gerarPeca());

                printf("Peca [%c %d] reservada na pilha. Nova peca gerada\n", p.nome, p.id);
                break;
            }

            case 3: {
                /* Move o topo da pilha, remove uma peca da fila e coloca de volta para o final da fila */
                if (pilha.topo == -1) {
                    printf("Pilha vazia!\n");
                    break;
                }
                Peca q = desenfileirar(&fila);
                Peca p = desempilhar(&pilha);
                enfileirar(&fila, p);
                printf("Peca [%c %d] retirada da fila.\n", q.nome, q.id);
                printf("Peca [%c %d] retirada da reserva e adicionada ao final da fila.\n", p.nome, p.id);
                break;
            }

            case 4: {
                /* Troca a peça da frente da fila com a peça do topo da pilha */
                trocarPecaFila(&fila, &pilha);
                break;
            }

            case 5: {
                /* Troca as 3 primeiras peças da fila com as 3 peças da pilha */
                trocaMultipla(&fila, &pilha);
                break;
            }

            case 6: {
                /* Limpa a tela, verifica se o sistema é Windows ou Linux */
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                break;
            }

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