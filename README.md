# Projetos de estrutura de dados

Aqui onde estão os meus trabalhos da disciplina de estrutura de dados.

## Estrutura das pastas
Cada atividade possui 3 arquivos: 
1. O principal (`main.c`) por onde o usuário interage.
2. O cabeçalho (arquivos que possui a extensão `.h`) possui os macros e as definições das funções que podem ser reutilizados em outros arquivos `.c`
3. A unidade de tradução, arquivo processado que contém o conteúdo das funções definidas pelo cabeçalho

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