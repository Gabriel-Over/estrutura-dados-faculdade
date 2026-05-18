# Compilador
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -pedantic -std=c11

# Caminhos dos arquivos
TERRITORIO_PATH = ./Tema_1/territorio_war/
MOCHILA_LISTA_PATH = ./Tema_2/mochila_lista_encadeada/
MOCHILA_VETOR_PATH = ./Tema_2/mochila_vetor/
MOCHILA_PRIORIZACAO_PATH = ./Tema_2/priorizacao/
TETRIS_PATH = ./Tema_3/tetris_stack/

territorio: $(TERRITORIO_PATH)main.c $(TERRITORIO_PATH)territorios.c
	$(CC) $(CFLAGS) $^ -o territorio

mochila_lista: $(MOCHILA_LISTA_PATH)main.c $(MOCHILA_LISTA_PATH)itens.c
	$(CC) $(CFLAGS) $^ -o mochila_lista

mochila_vetor: $(MOCHILA_VETOR_PATH)main.c $(MOCHILA_VETOR_PATH)itens.c
	$(CC) $(CFLAGS) $^ -o mochila_vetor

mochila_priorizacao: $(MOCHILA_PRIORIZACAO_PATH)main.c $(MOCHILA_PRIORIZACAO_PATH)prioridades.c
	$(CC) $(CFLAGS) $^ -o mochila_priorizacao

tetris: $(TETRIS_PATH)main.c $(TETRIS_PATH)pecas.c
	$(CC) $(CFLAGS) $^ -o tetris

all: territorio mochila_lista mochila_vetor mochila_priorizacao tetris