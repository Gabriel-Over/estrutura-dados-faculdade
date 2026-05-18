![Status](https://img.shields.io/badge/status-em_andamento-yellow)
# 📚 Projetos de Estrutura de Dados em C

Aqui onde estão os meus trabalhos da disciplina de estrutura de dados.

## 🛠️ Pré-requisitos

Para compilar e rodar os programas deste repositório, necessita de ter instalado no seu sistema:
- Um compilador C moderno compatível com a norma C11 (preferencialmente o GCC).
- A ferramenta GNU Make para automatizar o processo através do Makefile.

**Como instalar no Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install build-essential
```

## 🚀 Como Compilar e Executar

O projeto utiliza um Makefile configurado com as flags mais rigorosas de compilação (`-Wall -Wextra -pedantic -std=c11`), assegurando que o código esteja livre de avisos perigosos e erros ocultos.

**Compilar Tudo de uma Vez** 

Para gerar os binários de todos os projetos simultaneamente, execute:
```bash
make all
```
**Compilar um programa específico**
```bash
make territorio
make mochila_lista
make mochila_vetor
make mochila_priorizacao
make tetris
```
**Executar o Programa**

Após a compilação, o executável gerado estará pronto. Pode executá-lo a partir do terminal com o comando:
```bash
# Aqui esta escrito tetris, mas pode ser qualquer outro programa
./tetris.exe
```

## 📂 Organização do Repositório

Cada projeto segue uma arquitetura modular baseada em boas práticas de programação em C, dividida em três arquivos fundamentais:
1.  **Principal (`main.c`):** Responsável pelo fluxo de execução e interação com o utilizador.
2.  **Cabeçalho (`.h`):** Onde estão centralizados os macros, assinaturas de funções e definições de `structs`.
3.  **Implementação (`.c`):** Unidade auxiliar de tradução com o corpo lógico de todas as funções.

### Árvore de Diretórios
```bash
estrutura-dados-faculdade/
├── Tema_1/
│   └── territorio_war/            # Jogo de territórios e estratégias
├── Tema_2/
│   ├── mochila_lista_encadeada/   # Armazenamento dinâmico em nós
│   ├── mochila_vetor/             # Armazenamento em arrays contíguos
│   └── priorizacao/               # Lógica de pesos e prioridades
├── Tema_3/
│   └── tetris_stack/              # Jogo lógico com pilhas e filas circulares
└── Makefile                       # Script automatizado de compilação
```
## 🚧 Status do Projeto

Este repositório contém trabalhos acadêmicos desenvolvidos durante o 5º semestre de Ciência da Computação. Algumas implementações, como a lógica de combate no jogo de territórios ou a gestão de memória nas listas, ainda estão em fase de refinamento e podem passar por revisões. Além disso, faltam ser escritos mais algoritmos.