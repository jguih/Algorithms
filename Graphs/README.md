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
