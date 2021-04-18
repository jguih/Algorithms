#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Matrix
{
    int n_row;
    int n_col;
    int **mat;
}Matrix;

typedef struct Array
{
    int *array;
    int size;
}Array;

// Função para criar vetor
Array* Array_create(int size)
{
    Array *Array = malloc(sizeof(Array));
    Array->size = size;
    Array->array = (int*) malloc(size * sizeof(int));
    return Array;
}

// Função para criar a matriz
Matrix* Matrix_create(int n_row, int n_col)
{
    int i;
    Matrix *Matrix = (int*) malloc(sizeof(Matrix));

    Matrix->mat = (int**) malloc(n_row * sizeof(int*));
    Matrix->n_row = n_row;
    Matrix->n_col = n_col;

    for(i = 0; i < n_col; i++)
        Matrix->mat[i] = (int*) malloc(n_col * sizeof(int));

    return Matrix;
}

// Função para calcular o menor custo da multiplicação de matrizes
Matrix* MatrixChain_multiplication(Array *Dimensions)
{
    int i, j, k, min;
    Matrix *Matrix = Matrix_create(Dimensions->size - 1, Dimensions->size - 1);

    // inicializo a diagonal principal com 0's
    for(i = 0; i < Matrix->n_row; i++) 
        Matrix->mat[i][i] = 0;

    // a matriz é percorrida sempre de baixo para cima em cada coluna, ignorando a diagonal principal
    for(j = 1; j < Matrix->n_col; j++) // percorre as colunas
        for(i = j-1; i >= 0; i--) // percorre as linhas
            {
                if(j > i)
                {
                    for(k = i; k < j; k++)
                    { 
                        if(k == i)
                            min = Matrix->mat[i][k] + Matrix->mat[k+1][j] + ((Dimensions->array[i])*(Dimensions->array[k+1])*(Dimensions->array[j+1]));
                        if((Matrix->mat[i][k] + Matrix->mat[k+1][j] + (Dimensions->array[i]*Dimensions->array[k+1]*Dimensions->array[j+1])) < min)
                            min = Matrix->mat[i][k] + Matrix->mat[k+1][j] + (Dimensions->array[i]*Dimensions->array[k+1]*Dimensions->array[j+1]);
                    }
                    Matrix->mat[i][j] = min;
                }
            }
    return Matrix;
}

// Função para imprimir matriz
void Matrix_print(Matrix *Matrix)
{
    int i, j;

    for(i = 0; i < Matrix->n_row; i++)
    {
        for(j = 0; j < Matrix->n_col; j++)
        {
            if(j >= i)
                printf("[%d]",Matrix->mat[i][j]);
            else
                printf("[   ]");
        }
        printf("\n");
    }      
}

int main()
{
    int i; // auxiliar
    int matrix_count; // quantidade de matrizes
    Array *Dimensions; // vetor que armazena as dimensões das matrizes

    printf("Quantidade de matrizes: ");
    scanf("%d",&matrix_count);

    Dimensions = Array_create(matrix_count + 1);
    for(i = 0; i < Dimensions->size; i++)
        scanf("%d",&Dimensions->array[i]);
    
    Matrix_print(MatrixChain_multiplication(Dimensions));

    return 0;
}