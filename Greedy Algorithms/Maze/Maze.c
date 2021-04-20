#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int n_row; // linhas
    int n_col; // colunas
    int **mat; // matrix
}Matrix;

Matrix* Matrix_create(int n_row, int n_col)
{
    int i;
    Matrix *matrix = malloc(sizeof(Matrix));
    int **mat = (int**) malloc(n_row * sizeof(int*));

    for(i = 0; i < n_col; i++)
        mat[i] = (int*) malloc(n_col * sizeof(int));

    matrix->n_col = n_col;
    matrix->n_row = n_row;
    matrix->mat = mat;

    return matrix;
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

void path_cost(Matrix *matrix)
{
    // ideia: sair de M[0][0] e chegar em M[n_row - 1][n_col - 1]

    int i = 0, j = 0;
    char dead_end = 'n'; // verifica se foi alcançado um dead end
    char final_reached = 'n'; // verifica se o final foi alcançado
    int lower_cost; // menor custo
    int path_cost = matrix->mat[0][0]; // custo total
    int direction; // marca a próxima direção a ser seguida

    do
    {
        direction = -1;
        lower_cost = 200;

        if( (j+1) < matrix->n_col && matrix->mat[i][j+1] < lower_cost && matrix->mat[i][j+1] != -1)
        {
            lower_cost = matrix->mat[i][j+1];
            direction = 1; // direita
        }
        if( (j-1) >= 0 && matrix->mat[i][j-1] < lower_cost && matrix->mat[i][j-1] != -1)
        {
            lower_cost = matrix->mat[i][j-1];
            direction = 2; // esquerda
        }
        if( (i+1) < matrix->n_row && matrix->mat[i+1][j] < lower_cost && matrix->mat[i+1][j] != -1)
        {
            lower_cost = matrix->mat[i+1][j];
            direction = 3; // baixo
        }
        if( (i-1) >= 0 && matrix->mat[i-1][j] < lower_cost && matrix->mat[i-1][j] != -1)
        {
            lower_cost = matrix->mat[i-1][j];
            direction = 4; // cima
        }

        if(direction == -1) // dead end alcançado
            dead_end = 'y';
        else
        {
            matrix->mat[i][j] = -1; // marca os lugares já percorridos
            path_cost += lower_cost; // soma o menor custo encontrado para o próximo movimento

            // incremento de acordo com a direação apontada
            if(direction == 1)
                j++;
            else if(direction == 2)
                j--;
            else if(direction == 3)
                i++;
            else
                i--;
        }  
        // final alcançado
        if(i == (matrix->n_row - 1))
            if(j == (matrix->n_col -1))
            {
                matrix->mat[i][j] = -1;
                final_reached = 'y';
            }

    }while(final_reached == 'n' && dead_end == 'n');

    if(dead_end == 'y')
        printf("sem solucao");
    else
        printf("%d",path_cost);
}

int main() {
    
    int i, j;
    int n_row, n_col;

    //scanf("%d %d",&n_row, &n_col);

    // sample input:
    n_row = 6;
    n_col = 6;
    Matrix *matrix = Matrix_create(n_row, n_col);

    for(i = 0; i < matrix->n_row; i++)
        for(j = 0; j < matrix->n_col; j++)
        {
            //scanf("%d",&matrix->mat[i][j]);
            matrix->mat[i][j] = rand() % 5;
        }
            
    Matrix_print(matrix);
    path_cost(matrix);
    printf("\n");
    Matrix_print(matrix);

    return 0;
}
