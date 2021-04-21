#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "LinkedList.h"

struct LL_Node
{
    int key; // valor do noh
    struct LL_Node *next;
};

struct LinkedList
{
    int size; // quantidade de valores na lista
    LL_Node *head;
};

// funcao para criar o noh da lista
LL_Node* LL_Node_create(int key)
{
    LL_Node *new_node = malloc(sizeof(LL_Node));

    new_node->next = NULL;
    new_node->key = key;

    return new_node;
}

// funcao para criar a lista
Llist* Llist_create()
{
    Llist *list = malloc(sizeof(Llist));

    list->size = 0;
    list->head = NULL;

    return list;
}

// funcao para inserir na lista
Llist* Llist_insert(Llist *list, int new_key)
{
    LL_Node *new_node = LL_Node_create(new_key);
    LL_Node *p;

    if(list == NULL)
        list = Llist_create();
    if(list->head == NULL)
    {
        list->head = new_node;
        list->size++;
    }
    else
    {
        p = list->head;

        while(p->next != NULL)
            p = p->next;

        p->next = new_node;
        list->size++;
    }
}

// funcao para deletar noh da lista
void Llist_delete(Llist *list, int key)
{
    LL_Node *p, *deleted;

    if(list != NULL && list->head != NULL)
    {
        p = list->head; // aponta para a head a lista

        if(p->key == key)
        {
            // se a key que sera deletada estiver na head, esta aponta para o proximo elemento
            list->head = p->next;
            free(p);
            list->size--;
        }
        else
        {
            while(p->next != NULL)
            {
                if(p->next->key == key)
                {
                    deleted = p->next; // o noh que sera deletado
                    p->next = deleted->next; // p aponta para o valor a frente do noh que sera deletado
                }
                p = p->next; // p vai para o proximo
            }
            free(deleted);
            list->size--;
        }
    }
}

// funcao para imprimir a lista
void Llist_print(Llist *list)
{
    LL_Node *p;

    if(list != NULL && list->head != NULL)
    {
        p = list->head;

        while(p != NULL)
        {
            printf("%d ",p->key);
            p = p->next;
        }
    }
}