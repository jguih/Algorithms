typedef struct GraphAM GraphAM;

int** Matrix_create(int n); // criar matriz
void Matrix_insert(GraphAM *G); // funcao para inserir matriz no grafo
GraphAM* GraphAM_create(int n); // criar grafo
int Vortexisvalid(GraphAM *G, int v); // verifica se o vertice eh valido
int Edgeexists(GraphAM *G, int v1, int v2); // verifica se a aresta existe
void Edge_insert(GraphAM *G, int v1, int v2, int c); // insere aresta com custo c
void Edge_remove(GraphAM *G, int v1, int v2); // remove aresta
void Edge_print(GraphAM *G); // printa arestas
int Graphisregular(GraphAM *G); // verifica se um grafo eh regular
int DFS(GraphAM *G, int v1); // Depth First Search (verifica se o grafo eh ciclico ou aciclico)
int DFS_Implementation(GraphAM *G, int v1); // Implementacao da DFS
int** tmatrix(GraphAM *G); // Aloca a matriz t (auxiliar para Prim's Alg)
void PrimsAlg(GraphAM *G); // Prim's Algorithm
void tprint(GraphAM *G, int **t); // mostra a matriz t (auxiliar para Prim's Alg)
void FindFather(GraphAM *G, int **t); // mostra os pais de cada vertice da arvore do algoritmo de Prim