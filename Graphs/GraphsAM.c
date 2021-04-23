#include <stdio.h>
#include <stdlib.h>
#include "GraphsAM.h"

// Grafo por matriz de adjacencia
struct GraphAM
{
   int V; // numero de vertices
   int E; // numero de arestas
   int **mat; // matriz de adjacencia
};

int** Matrix_create(int n)
{
    int **mat = malloc(n * sizeof(int*));
    int i, j; // auxiliares

    for(i = 0; i < n; i++)
        mat[i] = (int*) malloc(n * sizeof(int));

    // inicia a matriz com 0's
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            mat[i][j] = 0;    
    
    return mat;
}

// funcao para criar o grafo
GraphAM* GraphAM_create(int n)
{
    GraphAM *G = malloc(sizeof(GraphAM));

    G->V = n;
    G->E = 0;
    G->mat = Matrix_create(G->V);

    return G;
}

// funcao para verificar se o grafo eh valido
int Vortexisvalid(GraphAM *G, int v)
{
    return (G != NULL && v >= 0 && v < G->V) ? 1:0;
}

// funcao para verificar se a aresta existe
int Edgeexists(GraphAM *G, int v1, int v2)
{
    return (G != NULL && Vortexisvalid(G, v1) && Vortexisvalid(G, v2) && G->mat[v1][v2] == 1) ? 1:0;
}

// funcao para inserir uma aresta
void Edge_insert(GraphAM *G, int v1, int v2)
{
    if(G != NULL && Vortexisvalid(G, v1) && Vortexisvalid(G, v2) && !Edgeexists(G, v1, v2))
    {
        G->mat[v1][v2] = 1;
        G->E++;
    }
}

// funcao para remover uma aresta
void Edge_remove(GraphAM *G, int v1, int v2)
{
    if(G != NULL && Vortexisvalid(G, v1) && Vortexisvalid(G, v2) && Edgeexists(G, v1, v2))
    {
        G->mat[v1][v2] = 0;
        G->E--;
    }
}

// funcao para imprimir arestas
void Edge_print(GraphAM *G)
{
    int i, j;

    for(i = 0; i < G->V; i++)
        for(j = 0; j < G->V; j++)
            if(G->mat[i][j] == 1)
                printf("(%d,%d)\n",i,j);
}

// funcao para verificar se um grafo eh regular
int Graphisregular(GraphAM *G)
{
    int i, j;
    int degree[G->V];

    for(i = 0; i < G->V; i++)
    {
        degree[i] = 0;

        for(j = 0; j < G->V; j++)
        {
            if(G->mat[i][j] == 1)
            {
                if(i == j) // selfloop
                    degree[i] += 2;
                else
                    degree[i]++;
            }
        }
        if(i > 0)
            if(degree[i-1] != degree[i])
                return 0;
    }
    return 1;
}