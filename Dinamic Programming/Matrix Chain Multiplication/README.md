# Multiplicação de cadeia de matrizes
O programa gera uma matriz solução de todas as possibilidades de multiplicação entre matrizes e retorna sempre o menor custo
## Estruturas
Matriz:
```c
typedef struct Matrix
{
    int n_row;
    int n_col;
    int **mat;
}Matrix;
```
Vetor:
```c
typedef struct Array
{
    int *array;
    int size;
}Array;
```
## Funções neste código
```c
Matrix* Matrix_create(int n_row, int n_col) // cria a matriz
```
O vetor de dimensões recebe os valores sem repetições, por exemplo:

A multiplicação de matrizes de dimensões A1(2x3) x A2(3x4) x A3(4x5), possuem as dimensões: 2,3,4,5.
```c
Matrix* MatrixChain_multiplication(Array *Dimensions) // gera a matriz solução para o problema
```
```c
void Matrix_print(Matrix *Matrix) // imprime a matriz
```
