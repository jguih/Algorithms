#include <stdio.h>
#include <stdlib.h>
#include "GraphsAL.h"

int main()
{
    GraphAL *G = GraphAL_create(6);
    
    Insertbymatrix(G);
    
    printf("\nBFS: ");
    BFS(G, 0);
    printf("\n");
    printf("DFS: ");
    DFS(G, 0);
    printf("\n\n");
    GraphAL_print(G);
    printf("\nPrims: ");
    PrimsAlg(G);
    printf("\nDijkstra: \n");
    Dijkstra(G, 0);

    return 0;
}