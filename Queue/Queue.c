#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Queue.h"

struct Queue
{
    Llist *list; // lista encadeada
    LL_Node *front; // inicio
    LL_Node *back; // fim
};

// funcao para criar a fila
Queue* Queue_create()
{
    Queue *q = malloc(sizeof(Queue));

    q->list = Llist_create();
    q->front = NULL;
    q->back = NULL;
}

// funcao para enfileirar
void Enqueue(Queue *q, int key)
{
    if(q->back == NULL && q->front == NULL)
        q->back = q->front = Llist_insert(q->list, key);
    else
        q->back = Llist_insert(q->list, key);
}

// funcao para desenfileirar
int Dequeue(Queue *q)
{
    int key = LL_Node_key(q->front);

    if(q == NULL)
        return -1;
    if(q->list == NULL)
        return -1;

    q->front = Llist_deletehead(q->list);

    if(q->front == NULL)
        q->back = NULL;

    return key;
}

// funcao para imprimir a fila
void Queue_print(Queue *q)
{
    printf("->");
    Llist_print(q->list);
}