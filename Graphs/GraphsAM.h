typedef struct GraphAM GraphAM;

int** Matrix_create(int n); // criar matriz
GraphAM* GraphAM_create(int n); // criar grafo
int Vortexisvalid(GraphAM *G, int v); // verifica se o vertice eh valido
int Edgeexists(GraphAM *G, int v1, int v2); // verifica se a aresta existe
void Edge_insert(GraphAM *G, int v1, int v2); // insere aresta
void Edge_remove(GraphAM *G, int v1, int v2); // remove aresta
void Edge_print(GraphAM *G); // printa arestas
int Graphisregular(GraphAM *G); // verifica se um grafo eh regular