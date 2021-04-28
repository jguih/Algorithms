#include <stdio.h>
#include <stdlib.h>
#include "GraphsAM.h"

int main()
{
    GraphAM *G = GraphAM_create(9);

    Matrix_insert(G);

    if(DFS(G, 0))
        printf("\nGraph is cyclic\n");
    else
        printf("\nGraph is acyclic\n");

    if(Graphisregular(G))
        printf("Graph is regular");
    else   
        printf("Graph isn't regular\n");

    PrimsAlg(G);

    return 0;
}