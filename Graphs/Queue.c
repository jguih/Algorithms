#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct QueueNode
{
    int key;
    struct QueueNode *next;
};
struct Queue
{
    QueueNode *front; // inicio
    QueueNode *back; // fim
};

// funcao para criar um noh da queue
QueueNode* QueueNode_create(int key)
{
    QueueNode *new_node = malloc(sizeof(QueueNode));

    new_node->next = NULL;
    new_node->key = key;

    return new_node;
}

// funcao para criar a fila
Queue* Queue_create()
{
    Queue *q = malloc(sizeof(Queue));

    q->front = NULL;
    q->back = NULL;

    return q;
}

// funcao para enfileirar
void Enqueue(Queue *q, int key)
{
    if(q->front == NULL && q->back == NULL)
        q->back = q->front = QueueNode_create(key);
    else
    {
        q->back->next = QueueNode_create(key);
        q->back = q->back->next;
    }
}

// funcao para desenfileirar
int Dequeue(Queue *q)
{
    QueueNode *aux = q->front;
    int key;

    if(q != NULL && aux != NULL)
    {
        key = aux->key;
        q->front = q->front->next;

        if(q->front == NULL)
            q->back = NULL;
            
        free(aux);
        return key;
    }
    return -1; // Queue nula
}

// funcao para imprimir a fila
void Queue_print(Queue *q)
{
    QueueNode *aux = q->front;
    printf("->");
    while(aux != NULL)
    {
        printf("%d ",aux->key);
        aux = aux->next;
    }
}

// funcao para verificar se a fila estah vazia
int Queue_isempty(Queue *q)
{
    return q == NULL || q->front == NULL && q->back == NULL ? 1:0;
}
