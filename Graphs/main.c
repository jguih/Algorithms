#include <stdio.h>
#include <stdlib.h>
#include "GraphsAL.h"

int main()
{
    GraphAL *G = GraphAL_create(5);

    Edge_insert(G, 0, 2);
    Edge_insert(G, 0, 3);
    Edge_insert(G, 1, 2);
    Edge_insert(G, 2, 0);
    Edge_insert(G, 2, 1);
    Edge_insert(G, 2, 3);
    Edge_insert(G, 2, 4);
    Edge_insert(G, 3, 2);
    Edge_insert(G, 3, 0);
    Edge_insert(G, 4, 2);
    
    BFS(G, 2);
    printf("\n");
    DFS(G, 3);

    return 0;
}