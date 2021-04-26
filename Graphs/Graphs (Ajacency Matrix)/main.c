#include <stdio.h>
#include <stdlib.h>
#include "GraphsAM.h"

int main()
{
    GraphAM *G = GraphAM_create(5);

    Edge_insert(G, 0, 2);
    Edge_insert(G, 1, 2);
    Edge_insert(G, 2, 3);
    Edge_insert(G, 2, 4);
    Edge_insert(G, 2, 0);
    Edge_insert(G, 3, 0);

    //Edge_print(G);

    if(DFS(G, 0))
        printf("\nGraph is cyclic\n");
    else
        printf("\nGraph is acyclic\n");

    if(Graphisregular(G))
        printf("Graph is regular");
    else   
        printf("Graph isn't regular");

    return 0;
}