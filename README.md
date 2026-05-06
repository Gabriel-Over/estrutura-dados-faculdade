![Status](https://img.shields.io/badge/status-em_andamento-yellow)
# 📚 Projetos de Estrutura de Dados em C

Aqui onde estão os meus trabalhos da disciplina de estrutura de dados.

## 🚀 Como executar

Para compilar qualquer um dos projetos, navegue até a pasta desejada e utilize o GCC. Por exemplo, se você quiser compilar o projeto "mochila (vetor)" digite:
```bash
gcc main.c itens.c -o executavel
./executavel
```

## 📂 Organização do Repositório

O projeto está organizado por temas, cada tema possui algumas atividades como requeridas pelo SAVA. Cada atividade possui 3 arquivos: 
1. O principal (`main.c`) por onde o usuário interage.
2. O cabeçalho (arquivos que possui a extensão `.h`) possui os macros e as definições das funções que podem ser reutilizados em outros arquivos `.c`
3. A unidade de tradução, arquivo auxiliar que contém o conteúdo das funções definidas pelo cabeçalho

Esta é a estrutura das pastas:
```bash
estrutura-dados/
├───Tema 1 - Estruturas de Dados Conceitos e Representação
│   └───territorio (war)
├───Tema 2 - Listas e Ordenação
│   ├───mochila (lista encadeada)
│   ├───mochila (vetor)
│   └───priorização
└───Tema 3 - Pilhas e Filas
    └───tetris stack
```

## 🚧 Status do Projeto

Este repositório contém trabalhos acadêmicos desenvolvidos durante o 5º semestre de Ciência da Computação. Algumas implementações, como a lógica de combate no jogo de territórios ou a gestão de memória nas listas, ainda estão em fase de refinamento e podem passar por revisões. Além disso, faltam ser escritos mais algoritmos.