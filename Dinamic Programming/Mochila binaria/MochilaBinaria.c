#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Ideia: fazer uma matriz para armazenar os valores máximos de peso para diferentes capacidades da mochila

typedef struct 
{
    int n_row; // nº de linhas
    int n_col; // nº de colunas
    int **mat; // matriz
}Matrix;

typedef struct
{
    int *a; // peso
    int *c; // custo
    int Item_size; // tamanho da lista de itens
}Item;

Matrix* Matrix_Create(int n_row, int n_col)
{
    int i;
    Matrix *mat = malloc(sizeof(Matrix));
    
    mat->n_row = n_row;
    mat->n_col = n_col;
    mat->mat = (int**) malloc(n_row * sizeof(int*));
    
    for(i = 0; i < n_row; i++)
        mat->mat[i] = (int*) malloc(n_col * sizeof(int));
    
    return mat;
}

// Função para imprimir matrix (apenas para testes)
void Matrix_print(Matrix *mat)
{
    int i, j;

    for(i = 0; i < mat->n_row; i++)
        for(j = 0; j < mat->n_col; j++){
            printf("[%d]",mat->mat[i][j]);
            if(j == mat->n_col - 1)
                printf("\n");
        }
}

int mochila_binaria(Item *item, int bag_size)
{
    int n_col, n_row;
    int i, j, k = 0, aux;

    // É necessário que a Matriz tenha uma coluna e uma linha a mais
    // para armazenar o custo máximo para uma mochila de capacidade 0 
    // e um item de custo 0

    n_row = bag_size + 1; 
    n_col= item->Item_size + 1;

    Matrix *mat = Matrix_Create(n_row, n_col);
    
    for(i = 0; i < mat->n_row; i++) // Inicio a primeira coluna da matriz com 0's
        mat->mat[i][0] = 0;
    
    for(j = 0; j < mat->n_col - 1; j++) // Percorre as colunas, como a coluna atual preenche a próxima, este for não precisa alcançar a última coluna
    {
        for(i = 0; i < mat->n_row; i++) // Percorre as linhas
            {
                aux = i - item->a[k]; // aux representa a linha da matriz com o peso restante

                if(aux >= 0)
                {
                    if(mat->mat[i][j] > (item->c[k] + mat->mat[aux][j]))
                        mat->mat[i][j+1] = mat->mat[i][j];
                    else
                        mat->mat[i][j+1] = (item->c[k] + mat->mat[aux][j]);
                }
                else // se aux for negativo
                    mat->mat[i][j+1] = mat->mat[i][j];
            }
        k++; 
    }
    return mat->mat[mat->n_row-1][mat->n_col-1];
}

int main() 
{
    int n, i, bag_size;
    scanf("%d",&bag_size);
    scanf("%d",&n);
    
    Item *item = malloc(sizeof(Item));
    item->a = (int*) malloc(n * sizeof(int));
    item->c = (int*) malloc(n * sizeof(int));
    item->Item_size = n;
    
    for(i = 0; i < n; i++)
        scanf("%d %d",item->a+i, item->c+i);
    
    printf("%d",mochila_binaria(item, bag_size));
        
    return 0;
}
