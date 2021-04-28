#include <stdio.h>
#include <stdlib.h>
#include "GraphsAL.h"

int main()
{
    GraphAL *G = GraphAL_create(9);

    Insertbymatrix(G);
    
    printf("\nBFS: ");
    BFS(G, 2);
    printf("\n");
    printf("DFS: ");
    DFS(G, 3);
    printf("\n\n");
    GraphAL_print(G);
    PrimsAlg(G);

    return 0;
}