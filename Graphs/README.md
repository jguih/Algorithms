# Graph (Adjacency list)
Implementação de grafos por lista de adjacência.
## Estruturas

Nó da lista encadeada
```c
struct LLNode
{
    int edge; // aresta
    int cost; // custo da aresta
    struct LLNode *next;
};
```
Lista encadeada
```c
struct LinkedList
{
    LLNode *head;
};
```
Grafo
```c
struct GraphAL
{
   int V; // número de vertices
   int E; // número de arestas
   Llist **adj; // lista de adjacência
};
```
## Funções neste código

Funcões de lista encadeada
```c
Llist* Llist_create(); // Cria a lista 
```
```c
void Llist_print(Llist *list); // Mostra a lista
```
```c
LLNode* LLNode_create(int edge, int cost); // Cria o nó da lista
```
```c
LLNode* Llist_search(Llist *l, int edge); // Pesquisa aresta na lista
```
```c
void Llist_insert(Llist *list, int edge, int cost); // Insere na lista
```
```c
void Llist_delete(Llist *list, int edge); // Deleta aresta da lista
```
Funções principais (Grafo)
```c
Llist** AdjLlist_create(int n) // Função para criar a lista de adjacência
```
```c
void AMtoAL(GraphAL *G, int **m); // Converte uma matriz de adjacência em uma lista de adjacência
```
```c
void Insertbymatrix(GraphAL *G); // Lê uma matriz de adjacência e a converte para lista de adjacência
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
int Vortex_cost(GraphAL *G, int v1, int v2); // Retorna o custo do vertice
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
```c
void BFS_Implementation(GraphAL *G, int v1); // Implementação da BFS
```
```c
void DFS(GraphAL *G, int v1); // Depth First Search
```
```c
void DFS_Implementation(GraphAL *G, int v1); // Implementação da DFS
```
Funções para o Algoritmo de Prim
```c
int** tmatrix(GraphAL *G); // Gera a matriz t
```
```c
void PrimsAlg(GraphAL *G); // Prim's Algorithm
```
```c
void tprint(GraphAL *G, int **t); // Mostra a matriz t
```
```c
void FindFather(GraphAL *G, int **t); // Mostra os pais dos vértices da árvore gerada pelo algoritmo de Prim
```
Funções para o Algoritmo de Djikstra
```c
int Dijkstra_Qisempty(GraphAL *G, int Q[]); // Verifica se o conjunto Q está vazio
```
```c
int Dijkstra_Qmin(GraphAL *G, int Q[], int d[]); // Calcula a menor distancia do vetor d[] considerando os valores válidos do conjunto Q[]
```
```c
void Dijkstra_tprint(GraphAL *G, int **t); // Mostra a matriz t
```
```c
int Dijkstra_FinduFather(GraphAL *G, int d[], int Q[], int u); // Acha o pai de u
```
```c
int** Dijkstra_tmatrix(GraphAL *G); // Aloca a matriz t
```
```c
void Dijkstra_printfather(GraphAL *G, int **t, int v1); // Mostra os pais dos vertices da arvore gerada por Dijkstra
```
```c
void Dijkstra(GraphAL *G, int v1); // Dijkstra Algorithm
```