#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int *w; // peso
    int *c; // custo
    int Item_size; // quantidade de itens
}Item;

// gera um vetor binário de tamanho n (número de itens)
int* vetor_binario(int Item_size, int i_num) 
{
    int i;
    int *v = malloc(Item_size * sizeof(int)); // vetor para armazenar a combinação a partir de um binário

    for(i = Item_size - 1; i >= 0; i--)
    {
        v[i] = i_num % 2; // sempre retorna 0 para pares e 1 para ímpares
        i_num /= 2;
    }

    return v;
}

// gera uma matriz com 2^n vetores binários de tamanho n, onde n é o número de itens
int** get_candidates(int Item_size) 
{
    int i; 
    int size = pow(2 , Item_size); // número de soluções possíveis 
    int **mat = malloc(size * sizeof(int*)); // matriz para armazenar as soluções possíveis

    for(i = 0; i < size; i++)
        mat[i] = vetor_binario(Item_size, i); // armazena um vetor binário em cada linha da matriz

    return mat;
}

// retorna o maior custo entre os candidatos válidos, onde 'c' é a capacidade da mochila
int max_cost_mochila_binaria(Item *Item, int c) 
{
    int size = pow(2 , Item->Item_size); // número de soluções possíveis
    int max_cost; // custo máximo
    int max_weight; // peso máximo
    int total_max_cost = 0; // custo total máximo entre todos os vetores
    int i, j;
    int **mat_candidates = get_candidates(Item->Item_size);


    for(i = 0; i < size; i++) // percorre as linhas da matriz
    {
        max_cost = 0;
        max_weight = 0;

        for(j = 0; j < Item->Item_size; j++) // percorre as colunas da matriz (vetor binário)
        {
            // dentro do vetor binário, 1 representa um item inserido e 0 não inserido, portanto:
            max_cost += mat_candidates[i][j] * Item->c[j]; // calcula o custo máximo dos itens inseridos
            max_weight += mat_candidates[i][j] * Item->w[j]; // calcula o peso máximo dos itens inseridos
        }

        // filtra apenas resultados válidos e gera o custo total máximo
        if( (max_weight <= c) && (max_cost > total_max_cost))
            total_max_cost = max_cost;
    }

    return total_max_cost;
}

int main() {

    int c; // capacidade da mochila
    scanf("%d",&c);

    int n; // quantidade de itens
    scanf("%d",&n);

    int i;

    Item *Item = malloc(sizeof(Item));
    Item->Item_size = n;
    Item->c = (int*) malloc(n * sizeof(int));
    Item->w = (int*) malloc(n * sizeof(int));

    for(i = 0; i < Item->Item_size; i++)
    {
        scanf("%d",Item->w+i); 
        scanf("%d",Item->c+i); 
    }

    printf("%d", max_cost_mochila_binaria(Item, c) );

    return 0;
}
