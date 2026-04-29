![Status](https://img.shields.io/badge/status-em_revisão-yellow)
# 📚 Projetos de Estrutura de Dados em C

Aqui onde estão os meus trabalhos da disciplina de estrutura de dados.

## 🚀 Como executar

Para compilar qualquer um dos projetos, navegue até a pasta desejada e utilize o GCC. Por exemplo, se você quiser compilar o projeto "mochila (vetor)" digite:
```bash
gcc main.c itens.c -o executavel
./executavel
```

## 📂 Organização do Repositório

Cada atividade possui 3 arquivos: 
1. O principal (`main.c`) por onde o usuário interage.
2. O cabeçalho (arquivos que possui a extensão `.h`) possui os macros e as definições das funções que podem ser reutilizados em outros arquivos `.c`
3. A unidade de tradução, arquivo auxiliar que contém o conteúdo das funções definidas pelo cabeçalho

```bash
|   .gitignore
|   README.md
|
+---listas                          # Tema 2 - Listas e ordenação
|   |   README.md
|   |
|   +---mochila (lista encadeada)   # Versão lista encadeada
|   |       itens.c
|   |       itens.h
|   |       main.c
|   |
|   +---mochila (vetor)             # Versão vetor
|   |       itens.c
|   |       itens.h
|   |       main.c
|   |
|   \---priorização                 # Versão prioridades
|           main.c
|           prioridades.c           
|           prioridades.h
|
\---territorio (war)                # Tema 1 - Estruturas
        main.c
        territorios.c
        territorios.h
```

## 🚧 Status do Projeto

Este repositório contém trabalhos acadêmicos desenvolvidos durante o 5º semestre de Ciência da Computação. Algumas implementações, como a lógica de combate no jogo de territórios ou a gestão de memória nas listas, ainda estão em fase de refinamento e podem passar por revisões. Além disso, faltam ser escritos mais algoritmos.