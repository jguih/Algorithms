typedef struct LLNode LLNode;
typedef struct LinkedList Llist;
typedef struct GraphAL GraphAL;

// --------------------------------------------
//          Funcoes de lista encadeada

Llist* Llist_create(); // cria a lista 
void Llist_print(Llist *list); // mostra a lista
LLNode* LLNode_create(int edge, int cost); // cria o noh da lista
LLNode* Llist_search(Llist *l, int edge); // pesquisa aresta na lista
void Llist_insert(Llist *list, int edge, int cost); // insere na lista
void Llist_delete(Llist *list, int edge); // deleta aresta da lista

// ------------------------------------------

Llist** AdjLlist_create(int n); // funcao para criar a lista de adjacência
void AMtoAL(GraphAL *G, int **m); // funcao que converte uma matriz de adjacencia em uma lista de adjacencia
void Insertbymatrix(GraphAL *G); // funcao que leh uma matriz de adjacencia
GraphAL* GraphAL_create(int v); // funcao para criar o grafo
int Edgeexists(GraphAL *G, int v1, int v2); // funcao para verificar se a aresta existe
int Vortex_isvalid(GraphAL *G, int v1); // verifica se o vertice eh valido
int Vortex_cost(GraphAL *G, int v1, int v2); // retorna o custo do vertice
void Edge_insert(GraphAL *G, int v1, int v2, int c); // funcao para inserir aresta
void Edge_remove(GraphAL *G, int v1, int v2); // funcao para remover aresta
void GraphAL_print(GraphAL *G); // funcao para imprimir grafo
void BFS(GraphAL *G, int v1); // Breadth First Search
void BFS_Implementation(GraphAL *G, int v1); // implementacao da BFS
void DFS(GraphAL *G, int v1); // Depth First Search
void DFS_Implementation(GraphAL *G, int v1); // implementacao da DFS

//--------------------------------------------------------------------
//                  Funcoes para o Algoritmo de Prim

int** Prims_tmatrix(GraphAL *G); // gera a matriz t
void PrimsAlg(GraphAL *G); // Prim's Algorithm
void Prims_tprint(GraphAL *G, int **t); // mostra a matriz t
void Prims_FindFather(GraphAL *G, int **t); // mostra os pais dos vertices da arvore gerada pelo algoritmo de Prim

//------------------------------------------------------------------------
//                  Funcoes para o Algoritmo de Dijkstra

int Dijkstra_Qisempty(GraphAL *G, int Q[]); // verifica se o conjunto Q estah vazio
int Dijkstra_Qmin(GraphAL *G, int Q[], int d[]); // calcula a menor distancia do vetor d[] considerando os valores validos do conjunto Q[]
void Dijkstra_tprint(GraphAL *G, int **t); // mostra a matriz t
int Dijkstra_FinduFather(GraphAL *G, int d[], int Q[], int u); // acha o pai de u
int** Dijkstra_tmatrix(GraphAL *G); // aloca a matriz t
void Dijkstra_printfather(GraphAL *G, int **t, int v1); // mostra os pais dos vertices da arvore gerada por Dijkstra
void Dijkstra(GraphAL *G, int v1); // Dijkstra Algorithm

//------------------------------------------------------------------------