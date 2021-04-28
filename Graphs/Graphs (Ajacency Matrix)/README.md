# Graph (Adjacency matrix)
Implementação de grafos por matriz de adjacência.
## Estrutura
```c
struct GraphAM
{
   int V; // número de vertices
   int E; // número de arestas
   int **mat; // matriz de adjacência
};
```
## Funções neste código
```c
int** Matrix_create(int n); // Função para criar matriz
```
```c
void Matrix_insert(GraphAM *G); // Função para inserir matriz no grafo
```
```c
GraphAM* GraphAM_create(int n); // Função para criar grafo
```
```c
int Vortexisvalid(GraphAM *G, int v); // Verifica se o vértice é valido
```
```c
int Edgeexists(GraphAM *G, int v1, int v2); // Verifica se existe uma aresta entre v1 e v2
```
```c
void Edge_insert(GraphAM *G, int v1, int v2); // Insere aresta no grafo
```
```c
void Edge_remove(GraphAM *G, int v1, int v2); // Remove aresta no grafo
```
```c
void Edge_print(GraphAM *G); // Mostra as arestas
```
```c
int Graphisregular(GraphAM *G); // Verifica se o grafo é regular
```
O Algoritmo Depth First Search neste código verifica se o grafo é cíclico ou acíclico
```c
int DFS(GraphAM *G, int v1); // Depth First Search
```
```c
int DFS_Implementation(GraphAM *G, int v1); // Implementacao da DFS
```
```c
int** tmatrix(GraphAM *G); // Aloca a matriz t (auxiliar para Prim's Alg)
```
```c
void PrimsAlg(GraphAM *G); // Prim's Algorithm
```
```c
void tprint(GraphAM *G, int **t); // Mostra a matriz t
```
```c
void FindFather(GraphAM *G, int **t); // Mostra os pais de cada vertice da árvore do algoritmo de Prim
```
