#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Item
{
    int *w; // peso
    int *c; // custo
    int Item_size; // quantidade de itens
}Item;

typedef struct Matrix
{
    int n_row; // n de linhas
    int n_col; // n de colunas
    int **mat; // matrix
}Matrix;

// gera um vetor binário de tamanho n (número de itens)
int* vetor_binario(Item *Item, int i_num) 
{
    int i;
    int *v = malloc(Item->Item_size * sizeof(int)); // vetor para armazenar a combinação a partir de um binário

    for(i = Item->Item_size - 1; i >= 0; i--)
    {
        v[i] = i_num % 2; // sempre retorna 0 para pares e 1 para ímpares
        i_num /= 2;
    }

    return v;
}

// Função que valida o candidato, onde "c" é a capacidade da mochila
int validate_candidate(int *v, Item *Item, int c)
{
    int max_weight = 0;
    int i;

    for(i = 0; i < Item->Item_size; i++)
        max_weight += v[i] * Item->w[i]; // peso máximo para o candidato
    
    if(max_weight <= c && max_weight > 0) 
        return 1; // candidato válido
    else 
        return 0; // candidato inválido
}

// Função que gera apenas candidatos válidos para a solução, onde "c" é a capacidade da mochila
Matrix* get_candidates(Item *Item, int c) 
{
    int i, j = 0; 
    int size = pow(2 , Item->Item_size); // número de soluções possíveis 
    int *v; // vetor binário
    Matrix *Matrix = malloc(sizeof(Matrix));
    
    Matrix->n_col = Item->Item_size; // numero de colunas é o numero de itens
    
    // verificar quantos quandidatos válido existem
    Matrix->n_row = 0; // inicia a contagem de linhas
    for(i = 0; i < size; i++)
    {
        v = vetor_binario(Item, i);
        if((validate_candidate(v, Item, c)) == 1)
            Matrix->n_row++;
    }

    // aloca memória de acordo com a quantidade de candidatos encontrados
    Matrix->mat = (int**) malloc(Matrix->n_row * sizeof(int*));

    for(i = 0; i < size; i++)
    {
        v = vetor_binario(Item, i);
        if((validate_candidate(v, Item, c)) == 1)
        {
            Matrix->mat[j] = v; // armazena um vetor binário em cada linha da matriz
            j++;
        }
    }

    return Matrix;
}

// retorna o maior custo entre os candidatos válidos, onde 'c' é a capacidade da mochila
int max_cost_mochila_binaria(Item *Item, int c) 
{
    int max_cost; // custo máximo
    int total_max_cost = 0; // custo total máximo entre todos os vetores
    int i, j;
    Matrix *Candidates = get_candidates(Item, c);


    for(i = 0; i < Candidates->n_row; i++) // percorre as linhas/candidatos da matriz
    {
        max_cost = 0;
    
        for(j = 0; j < Candidates->n_col; j++) // percorre as colunas da matriz (vetor binário)
        {
            // dentro do vetor binário, 1 representa um item inserido e 0 não inserido, portanto:
            max_cost += Candidates->mat[i][j] * Item->c[j]; // calcula o custo máximo dos itens inseridos
        }

        // gera o custo total máximo
        if( max_cost > total_max_cost )
            total_max_cost = max_cost;
    }

    return total_max_cost;
}

int main() {

    int c; // capacidade da mochila
    scanf("%d",&c);

    int n; // quantidade de itens
    scanf("%d",&n);

    int i; // auxiliar

    Item *Item = malloc(sizeof(Item));
    Item->Item_size = n;
    Item->c = (int*) malloc(n * sizeof(int)); // custo
    Item->w = (int*) malloc(n * sizeof(int)); // peso

    for(i = 0; i < Item->Item_size; i++)
    {
        scanf("%d",Item->w+i); 
        scanf("%d",Item->c+i); 
    }

    printf("%d", max_cost_mochila_binaria(Item, c));

    return 0;
}

