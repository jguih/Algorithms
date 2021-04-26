#include "LinkedList.h"

typedef struct GraphAL GraphAL;

Llist** AdjLlist_create(int n); // funcao para criar a lista de adjacência
GraphAL* GraphAL_create(int v); // funcao para criar o grafo
int Edgeexists(GraphAL *G, int v1, int v2); // funcao para verificar se a aresta existe
int Vortex_isvalid(GraphAL *G, int v1); // verifica se o vertice eh valido
void Edge_insert(GraphAL *G, int v1, int v2); // funcao para inserir aresta
void Edge_remove(GraphAL *G, int v1, int v2); // funcao para remover aresta
void GraphAL_print(GraphAL *G); // funcao para imprimir grafo
void BFS(GraphAL *G, int v1); // Breadth First Search
void BFS_Implementation(GraphAL *G, int v1); // implementacao da BFS
void DFS(GraphAL *G, int v1); // Depth First Search
void DFS_Implementation(GraphAL *G, int v1); // implementacao da DFS
