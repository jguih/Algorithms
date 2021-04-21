# Mochila Binária (Dinamic Programming)
O programa resolve o problema da mochila binária usando programação dinâmica, gerando todas as soluções possíveis

https://pt.wikipedia.org/wiki/Problema_da_mochila#Solu%C3%A7%C3%A3o_usando_Programa%C3%A7%C3%A3o_Din%C3%A2mica
## Estruturas
Matriz:
```c
typedef struct 
{
    int n_row; // nº de linhas
    int n_col; // nº de colunas
    int **mat; // matriz
}Matrix;
```
Item:
```c
typedef struct
{
    int *a; // peso
    int *c; // custo
    int Item_size; // tamanho da lista de itens
}Item;
```
## Funções
```c
Matrix* Matrix_Create(int n_row, int n_col) // cria a matriz
```
```c
void Matrix_print(Matrix *mat) // imprime a matriz
```
```c
int mochila_binaria(Item *item, int bag_size) // gera uma matriz solução e retorna a melhor
```
