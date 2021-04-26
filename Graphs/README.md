# Graph (Adjacency list)
Implementação de grafos por lista de adjacência.
## Estrutura
```c
struct GraphAL
{
   int V; // número de vertices
   int E; // número de arestas
   Llist **adj; // lista de adjacência
};
```
## Funções neste código
```c
Llist** AdjLlist_create(int n) // Função para criar a lista de adjacência
```
```c
GraphAL* GraphAL_create(int n); // Função para criar grafo
```
```c
int Edgeexists(GraphAL *G, int v1, int v2); // Verifica se existe uma aresta entre v1 e v2
```
```c
int Vortex_isvalid(GraphAL *G, int v1); // Verifica se o vértice é válido
```
```c
void Edge_insert(GraphAL *G, int v1, int v2); // Insere aresta no grafo
```
```c
void Edge_remove(GraphAL *G, int v1, int v2); // Remove aresta no grafo
```
```c
void Edge_print(GraphAL *G); // Mostra as arestas
```
```c
void BFS(GraphAL *G, int v1); // Breadth First Search
```

