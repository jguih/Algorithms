#include <stdio.h>
#include <stdlib.h>
#include "GraphsAM.h"

int main()
{
    GraphAM *G = GraphAM_create(3);

    Edge_insert(G, 0, 1);
    Edge_insert(G, 0, 2);
    Edge_insert(G, 1, 0);
    Edge_insert(G, 1, 2);
    Edge_insert(G, 2, 0);
    Edge_insert(G, 2, 1);  

    Edge_print(G);

    if(Graphisregular(G))
        printf("Graph is regular");
    else
        printf("Graph isn't regular");

    return 0;
}