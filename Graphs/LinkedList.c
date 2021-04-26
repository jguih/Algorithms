#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "LinkedList.h"

struct LLNode
{
    int key; // valor do noh
    struct LLNode *next;
};

struct LinkedList
{
    LLNode *head;
};

// funcao para criar o noh da lista
LLNode* LLNode_create(int key)
{
    LLNode *new_node = malloc(sizeof(LLNode));

    new_node->next = NULL;
    new_node->key = key;

    return new_node;
}

// funcao para retornar a key do noh
int LLNode_key(LLNode *Node)
{
    return Node->key;
}

// funcao para criar a lista
Llist* Llist_create()
{
    Llist *list = malloc(sizeof(Llist));
    list->head = NULL;

    return list;
}

// funcao para procurar na lista
int Llist_search(Llist *l, int key)
{
    LLNode *aux;

    if(l != NULL && l->head != NULL)
    {
        aux = l->head;

        while(aux != NULL)
        {
            if(aux->key == key)
                return 1;
            aux = aux->next;
        }
    }
    return 0;
}

// funcao para inserir na lista
LLNode* Llist_insert(Llist *list, int new_key)
{
    LLNode *new_node = LLNode_create(new_key);
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
    return new_node;
}

// funcao para inserir no final da lista
LLNode* Llist_insertend(Llist *list, LLNode *end, int key)
{
    LLNode *new_node = LLNode_create(key);

    if(list == NULL)
        list = Llist_create();
    if(list->head == NULL)
        return Llist_insert(list, key);
    else if(end != NULL)
    {
        end->next = new_node;
        return new_node;
    }
}

// funcao para deletar noh da lista
LLNode* Llist_delete(Llist *list, int key)
{
    LLNode *p, *deleted;

    if(list != NULL && list->head != NULL)
    {
        p = list->head; // aponta para a head a lista

        if(p->key == key)
        {
            // se a key que sera deletada estiver na head, esta aponta para o proximo elemento
            list->head = p->next;
            free(p);
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
        }
    }
    return deleted;
}

// funcao para remover a head da lista
LLNode* Llist_deletehead(Llist *list)
{
    if(list->head == NULL)
        return NULL;
    
    list->head = list->head->next;

    return list->head;
}

// funcao para imprimir a lista
void Llist_print(Llist *list)
{
    LLNode *p;

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

// funcao para verificar se a lista estah vazia
int Llist_isempty(Llist *list)
{
    return list->head == NULL ? 1:0;
}