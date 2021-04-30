#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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

    // inicia a matriz com INT_MAX's para permitir o uso da funcao Edge_insert
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            mat[i][j] = INT_MAX;   

    return mat;
}

// funcao para inserir matriz no grafo
void Matrix_insert(GraphAM *G)
{
    int i, j, edge; // auxiliares
    
    if(G != NULL)
    {
        // inicia a matriz
        for(i = 0; i < G->V; i++)
            for(j = 0; j < G->V; j++)
            {
                scanf("%d",&edge);
                if(edge == 0)
                    edge = INT_MAX;
                G->mat[i][j] = edge;
                G->E++;
            }
    }
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

// funcao para verificar se o vertice eh valido
int Vortexisvalid(GraphAM *G, int v)
{
    return (G != NULL && v >= 0 && v < G->V) ? 1:0;
}

// funcao para verificar se a aresta existe
int Edgeexists(GraphAM *G, int v1, int v2)
{
    return (G != NULL && Vortexisvalid(G, v1) && Vortexisvalid(G, v2) && G->mat[v1][v2] != INT_MAX) ? 1:0;
}

// funcao para inserir uma aresta
void Edge_insert(GraphAM *G, int v1, int v2, int c)
{
    if(G != NULL && Vortexisvalid(G, v1) && Vortexisvalid(G, v2) && !Edgeexists(G, v1, v2))
    {
        G->mat[v1][v2] = c;
        G->E++;
    }
}

// funcao para remover uma aresta
void Edge_remove(GraphAM *G, int v1, int v2)
{
    if(G != NULL && Vortexisvalid(G, v1) && Vortexisvalid(G, v2) && Edgeexists(G, v1, v2))
    {
        G->mat[v1][v2] = INT_MAX;
        G->E--;
    }
}

// funcao para imprimir arestas
void Edge_print(GraphAM *G)
{
    int i, j;

    for(i = 0; i < G->V; i++)
        for(j = 0; j < G->V; j++)
            if(G->mat[i][j] != INT_MAX)
                printf("(%d):%d:(%d) \n",i,G->mat[i][j],j); // (aresta):custo:(aresta)
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

int *visited; // marca os vertices jah visitados
int cycle; // verifica se ha um ciclo no grafo
int *descendent; // armazena os descendentes ja visitados
int j; // auxiliar

// funcao para iniciar as variaveis globais e chamar DFS
int DFS(GraphAM *G, int v1)
{
    int i;  

    visited = (int*) malloc(G->V * sizeof(int));
    descendent = (int*) malloc(G->V * sizeof(int));

    for(i = 0; i < G->V; i++)
    {
        visited[i] = 0;
        descendent[i] = -1;
    }

    cycle = 0;
    j = -1;

    i = DFS_Implementation(G, v1);

    free(visited);
    free(descendent);
    visited = descendent = NULL;
    
    return i;
}

// Depth First Search
int DFS_Implementation(GraphAM *G, int v1)
{
    int i;

    if(G == NULL)
        return -1;

    if(visited[v1] == 0)
    {
        j++;
        descendent[j] = v1;
        //printf("%d ",v1);
        visited[v1] = 1;
        for(i = 0; i < G->V; i++)
            if(Edgeexists(G, v1, i))
                DFS_Implementation(G, i);
    }
    else if(j-2 >= 0)
        if(v1 == descendent[j-2])
            cycle = 1;
    
    return cycle;
}

// funcao para alocar a matriz t
int** tmatrix(GraphAM *G)
{
    int **t = (int**) malloc(2 * sizeof(int*));
    int i;

    for(i = 0; i < 2; i++)
        t[i] = (int*) malloc( (G->V-1) * sizeof(int));
    
    return t;
}

// Prim's Algorithm
void PrimsAlg(GraphAM *G)
{
    int i, j, u, v, min = INT_MAX; // auxiliares
    /*
        t eh uma matriz que armazena as arestas de menor custo
    */
    int **t = tmatrix(G);
    /* 
        near eh um vetor que armazena o vertice mais proximo 
        de um vertice i, sendo i a posicao no vetor
    */
    int near[G->V]; 

    // inicia o vetor near
    for(i = 0; i < G->V; i++)
        near[i] = INT_MAX;

    // procura o menor custo na matriz do grafo
    for(i = 0; i < G->V; i++)
    {
        for(j = i; j < G->V; j++)
        {
            if(G->mat[i][j] != INT_MAX && G->mat[i][j] < min)
            {
                min = G->mat[i][j];
                u = i;
                v = j;
            }
        }
    }

    // atualiza o vetor near e a matriz t
    near[u] = near[v] = -1; // aresta jah incluida
    t[0][0] = u;
    t[1][0] = v;

    /*
        O vetor near eh atualizado mais uma vez,
        agora comparando a distancia de um vertice i
        (posisicao no vetor) entre u e v
    */
    for(i = 0; i < G->V; i++)
    {
        if(near[i] != -1)
        {
            if(G->mat[i][u] < G->mat[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }

    /* 
        percorre a matriz t comecando pela coluna 1,
        pois a coluna 0 jah foi preenchida
    */
    for(i = 1; i < G->V - 1; i++)
    {
        min = INT_MAX;

        // calcula o menor custo dentro do vetor near
        for(j = 0; j < G->V; j++) // percorre o vetor near
        {
            if(near[j] != -1)
            {
                if(G->mat[j][near[j]] < min)
                {
                    min = G->mat[j][near[j]];
                    u = j; // linha 0 da matriz t na coluna i
                }
            }
        }

        // atualiza a matriz t
        t[0][i] = u;
        t[1][i] = near[u]; 
        // atualiza o vetor near
        near[u] = -1; // aresta jah inclusa

        // atualiza o vetor near
        for(j = 0; j < G->V; j++)
        {
            if(near[j] != -1 && G->mat[j][u] < G->mat[j][near[j]])
                near[j] = u;
        }
    }
    tprint(G, t);
    FindFather(G, t);
}

void tprint(GraphAM *G, int **t)
{
    int i, j;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < G->V-1; j++)
            printf("[%d]",t[i][j]);
        printf("\n");
    }
}

void FindFather(GraphAM *G, int **t)
{
    int i, j;

    for(i = 0; i < G->V; i++)
    {
        if(i == 0)
            printf("%d: -\n",i);
        else if(i == 1)
            printf("%d: %d\n",i,t[0][i-1]);
        else
        {
            for(j = 1; j < G->V-1; j++)
            {
                if(t[0][j] == i)
                {
                    printf("%d: %d\n",i,t[1][j]);
                    break;
                }
            }
        }
    }
}