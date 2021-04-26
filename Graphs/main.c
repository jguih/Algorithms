#include <stdio.h>
#include <stdlib.h>
#include "GraphsAL.h"

int main()
{
    GraphAL *G = GraphAL_create(5);

    Edge_insert(G, 0, 1);
    Edge_insert(G, 0, 2);
    Edge_insert(G, 0, 3);
    Edge_insert(G, 0, 4);
    Edge_insert(G, 4, 3);
    Edge_remove(G, 0, 2);

    GraphAL_print(G);

    return 0;
}