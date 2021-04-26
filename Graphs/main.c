#include <stdio.h>
#include <stdlib.h>
#include "GraphsAL.h"

int main()
{
    GraphAL *G = GraphAL_create(5);

    Edge_insert(G, 0, 1);
    Edge_insert(G, 0, 2);
    Edge_insert(G, 2, 3);
    Edge_insert(G, 3, 4);
    Edge_insert(G, 4, 0);
    Edge_insert(G, 4, 1);
    
    BFS(G, 2);

    return 0;
}