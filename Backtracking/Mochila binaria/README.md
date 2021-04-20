# Mochila Binária (Backtracking)
O código resolve o problema da mochila binária ultilizando backtracking.
## Estruturas
Itens que serão inseridos na mochila:
```c
typedef struct Item
{
    int *w; // peso
    int *c; // custo
    int Item_size; // quantidade de itens
}Item;
```
Matriz para armazenar as soluções válidas:
```c
typedef struct Matrix
{
    int n_row; // n de linhas
    int n_col; // n de colunas
    int **mat; // matrix
}Matrix;
```
## Funções neste código
'c' Representa a capacidade da mochila
```c
int* vetor_binario(Item *Item, int i_num) // gera um vetor binário de tamanho Item->Item_size
```
```c
int validate_candidate(int *v, Item *Item, int c) // valida a solução gerada
```
```c
Matrix* get_candidates(Item *Item, int c) // gera as possíveis soluções
```
```c
int max_cost_mochila_binaria(Item *Item, int c) // calcula o custo máximo entre os candidatos válidos
```
