# Maze
Problema do labirinto usando algoritmo guloso em C.

Ideia geral do código: sair de M[0][0] e chegar em M[n_row - 1][n_col -1]

## Estrutura da matriz
```c
typedef struct
{
    int n_row; // linhas
    int n_col; // colunas
    int **mat; // matrix
}Matrix;
```
## Funções neste código
```c
Matrix* Matrix_create(int n_row, int n_col) // criar a matriz (labirinto)
```
```c
void Matrix_print(Matrix *mat) // imprimir a matriz
```
```c
void path_cost(Matrix *matrix) // calcula o custo total de deslocamento
```
