#include <stdio.h>
#include <stdlib.h>
#include "GraphsAL.h"
#include "Queue.h"

// Noh da lista encadeada
struct LLNode
{
    int edge; // aresta
    int cost; // custo da aresta
    struct LLNode *next;
};

// Lista encadeada
struct LinkedList
{
    LLNode *head;
};

// Grafo por lista de adjacencia
struct GraphAL
{
   int V; // numero de vertices
   int E; // numero de arestas
   Llist **adj; // lista de adjacencia
};

//----------------------------------------------
//          Funcoes de Lista Encadeada

//funcao para criar a lista encadeada
Llist* Llist_create()
{
    Llist *list = malloc(sizeof(Llist));
    list->head = NULL;

    return list;
}

// funcao para imprimir a lista encadeada
void Llist_print(Llist *list)
{
    LLNode *p;

    if(list != NULL && list->head != NULL)
    {
        p = list->head;

        while(p != NULL)
        {
            printf("%d:%d ",p->edge, p->cost);
            p = p->next;
        }
    }
}

// funcao para criar o noh da lista encadeada
LLNode* LLNode_create(int edge, int cost)
{
    LLNode *new_node = malloc(sizeof(LLNode));

    new_node->next = NULL;
    new_node->edge = edge;
    new_node->cost = cost;

    return new_node;
}

// funcao para procurar na lista encadeada
LLNode* Llist_search(Llist *l, int edge)
{
    LLNode *aux;

    if(l != NULL && l->head != NULL)
    {
        aux = l->head;

        while(aux != NULL)
        {
            if(aux->edge == edge)
                return aux;
            aux = aux->next;
        }
    }
    return NULL;
}

// funcao para inserir na lista encadeada
void Llist_insert(Llist *list, int edge, int cost)
{
    LLNode *new_node = LLNode_create(edge, cost);
    LLNode *p;

    if(list == NULL)
        list = Llist_create();
    if(list->head == NULL)
        list->head = new_node;
    else
    {
        p = list->head;

        while(p->next != NULL)
            p = p->next;

        p->next = new_node;
    }
}

// funcao para deletar noh da lista encadeada
void Llist_delete(Llist *list, int edge)
{
    LLNode *p, *deleted;

    if(list != NULL && list->head != NULL)
    {
        p = list->head; // aponta para a head a lista

        if(p->edge == edge)
        {
            // se a key que sera deletada estiver na head, esta aponta para o proximo elemento
            list->head = p->next;
            free(p);
        }
        else
        {
            while(p->next != NULL)
            {
                if(p->next->edge == edge)
                {
                    deleted = p->next; // o noh que sera deletado
                    p->next = deleted->next; // p aponta para o valor a frente do noh que sera deletado
                }
                p = p->next; // p vai para o proximo
            }
        }
    }
    free(deleted);
    free(p);
}
//----------------------------------------------

// funcao para criar a lista de adjacencia
Llist** Adjlist_create(int n)
{
    Llist **l = (Llist**) malloc(n * sizeof(Llist*));
    int i;

    for(i = 0; i < n; i++)
        l[i] = Llist_create();
    
    return l;
}

// funcao para converter matriz de adjacencia em lista de adjacencia
void AMtoAL(GraphAL *G, int **m)
{
    int i, j;

    for(i = 0; i < G->V; i++)
        for(j = 0; j < G->V; j++)
        {
            if(m[i][j] != INT_MAX)
                Edge_insert(G, i, j, m[i][j]);
        }
}

// funcao para inserir no grafo a partir de uma matriz
void Insertbymatrix(GraphAL *G)
{
    int **m = (int**) malloc(G->V * sizeof(int*));
    int i, j, edge;

    for(i = 0; i < G->V; i++)
        m[i] = (int*) malloc(G->V * sizeof(int));
    
    printf("Informe a matriz %dx%d: \n",G->V,G->V);
    for(i = 0; i < G->V; i++)
        for(j = 0; j < G->V; j++)
        {
            scanf("%d",&edge);
            if(edge == 0)
                edge = INT_MAX;
            m[i][j] = edge;
        }
    AMtoAL(G, m);
}

// funcao para criar o grafo
GraphAL* GraphAL_create(int v)
{
    GraphAL *G = malloc(sizeof(GraphAL));

    G->V = v;
    G->E = 0;
    G->adj = Adjlist_create(G->V);

    return G;
}

// funcao para verificar se a aresta existe
int Edgeexists(GraphAL *G, int v1, int v2)
{
    if(G != NULL && G->adj[v1]->head != NULL)
        return Llist_search(G->adj[v1], v2) == NULL ? 0:1;
}

// funcao para verificar se vertice eh valido
int Vortex_isvalid(GraphAL *G, int v1)
{
    return (G != NULL && v1 >= 0 && v1 < G->V) ? 1:0;
}

int Vortex_cost(GraphAL *G, int v1, int v2)
{
    LLNode *aux = Llist_search(G->adj[v1], v2);
    return aux != NULL ? aux->cost:INT_MAX;
}

// funcao para inserir aresta
void Edge_insert(GraphAL *G, int v1, int v2, int c)
{
    if(!Edgeexists(G, v1, v2) && Vortex_isvalid(G, v1) && Vortex_isvalid(G, v2))
    {
        Llist_insert(G->adj[v1], v2, c);
        G->E++;
    }
}

// funcao para remover aresta
void Edge_remove(GraphAL *G, int v1, int v2)
{
    if( Vortex_isvalid(G, v1) && Vortex_isvalid(G, v2) && Edgeexists(G, v1, v2) )
    {
        Llist_delete(G->adj[v1], v2);
        G->E--;
    }
}

// funcao para imprimir grafo
void GraphAL_print(GraphAL *G)
{
    int i;

    for(i = 0; i < G->V; i++)
    {
        printf("%d -> ",i);
        Llist_print(G->adj[i]);
        printf("\n");
    }
}

int *visited; // variavel global para uso na BFS e DFS

// funcao para iniciar a variavel global e chamar BFS
void BFS(GraphAL *G, int v1)
{
    int i;

    visited = (int*) malloc(G->V * sizeof(int));

    for(i = 0; i < G->V; i++)
        visited[i] = 0;

    BFS_Implementation(G, v1);

    free(visited);
    visited = NULL;
}

// Breadth Fist Search
void BFS_Implementation(GraphAL *G, int v1)
{
    Queue *q = Queue_create(); // fila
    int i, u; // auxiliares

    printf("%d ",v1);
    visited[v1] = 1;
    Enqueue(q, v1);
    while(!Queue_isempty(q))
    {
        u = Dequeue(q); // vertice
        for(i = 0; i < G->V; i++) // arestas do vertice em 'u'
        {
            if(visited[i] == 0 && Edgeexists(G, u, i))
            {
                printf("%d ",i);
                visited[i] = 1;
                Enqueue(q, i);
            }
        }
    }
}

// funcao para iniciar a variavel global e chamar DFS
void DFS(GraphAL *G, int v1)
{
    int i;

    visited = (int*) malloc(G->V * sizeof(int));

    for(i = 0; i < G->V; i++)
        visited[i] = 0;

    DFS_Implementation(G, v1);

    free(visited);
    visited = NULL;
}

// Depth First Search
void DFS_Implementation(GraphAL *G, int v1)
{
    int i;

    if(visited[v1] == 0)
    {
        printf("%d ",v1);
        visited[v1] = 1;
        for(i = 0; i < G->V; i++)
            if(visited[i] == 0 && Edgeexists(G, v1, i))
                DFS_Implementation(G, i);
    }
}

//--------------------------------------------------------------------
//                  Funcoes para o Algoritmo de Prim

// funcao para alocar a matriz t
int** tmatrix(GraphAL *G)
{
    int **t = (int**) malloc(2 * sizeof(int*));
    int i;

    for(i = 0; i < 2; i++)
        t[i] = (int*) malloc( (G->V-1) * sizeof(int));
    
    return t;
}

// Prim's Algorithm
void PrimsAlg(GraphAL *G)
{
    int i, j, u, v, min = INT_MAX; // auxiliares
    /*
        t eh uma matriz que armazena as arestas de menor custo
    */
    int **t = tmatrix(G);
    /* 
        near eh um vetor que armazena o vertice mais proximo 
        de um vertice i, sendo i a posicao no vetor
    */
    int near[G->V]; 

    // inicia o vetor near
    for(i = 0; i < G->V; i++)
        near[i] = INT_MAX;

    // procura o menor custo na matriz do grafo
    for(i = 0; i < 1; i++)
    {
        for(j = i; j < G->V; j++)
        {
            if(Vortex_cost(G,i,j) != INT_MAX && Vortex_cost(G,i,j) < min)
            {
                min = Vortex_cost(G,i,j);
                u = i;
                v = j;
            }
        }
    }

    // atualiza o vetor near e a matriz t
    near[u] = near[v] = -1; // aresta jah incluida
    t[0][0] = u;
    t[1][0] = v;

    /*
        O vetor near eh atualizado mais uma vez,
        agora comparando a distancia de um vertice i
        (posisicao no vetor) entre u e v
    */
    for(i = 0; i < G->V; i++)
    {
        if(near[i] != -1)
        {
            if(Vortex_cost(G,i,u) < Vortex_cost(G,i,v))
                near[i] = u;
            else
                near[i] = v;
        }
    }

    /* 
        percorre a matriz t comecando pela coluna 1,
        pois a coluna 0 jah foi preenchida
    */
    for(i = 1; i < G->V - 1; i++)
    {
        min = INT_MAX;

        // calcula o menor custo dentro do vetor near
        for(j = 0; j < G->V; j++) // percorre o vetor near
        {
            if(near[j] != -1)
            {
                if(Vortex_cost(G,j,near[j]) < min)
                {
                    min = Vortex_cost(G,j,near[j]);
                    u = j; // linha 0 da matriz t na coluna i
                }
            }
        }

        // atualiza a matriz t
        t[0][i] = u;
        t[1][i] = near[u]; 
        // atualiza o vetor near
        near[u] = -1; // aresta jah inclusa

        // atualiza o vetor near
        for(j = 0; j < G->V; j++)
        {
            if(near[j] != -1 && Vortex_cost(G,j,u) < Vortex_cost(G,j,near[j]))
                near[j] = u;
        }
    }
    printf("\n");
    tprint(G, t);
    //FindFather(G, t);
}

void tprint(GraphAL *G, int **t)
{
    int i, j;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < G->V-1; j++)
            printf("[%d]",t[i][j]);
        printf("\n");
    }
}

void FindFather(GraphAL *G, int **t)
{
    int i, j;

    for(i = 0; i < G->V; i++)
    {
        if(i == 0)
            printf("%d: -\n",i);
        else if(i == 1)
            printf("%d: %d\n",i,t[0][i-1]);
        else
        {
            for(j = 1; j < G->V-1; j++)
            {
                if(t[0][j] == i)
                {
                    printf("%d: %d\n",i,t[1][j]);
                    break;
                }
            }
        }
    }
}
//--------------------------------------------------------------------