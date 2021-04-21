#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{
    Llist *list = Llist_create();

    Llist_insert(list, 10);
    Llist_insert(list, 20);
    Llist_insert(list, 30);
    Llist_insert(list, 40);
    Llist_insert(list, 50);
    Llist_print(list);
    printf("\n");
    Llist_delete(list, 30);
    Llist_delete(list, 10);
    Llist_print(list);
    printf("\n");
    Llist_delete(list, 20);
    Llist_delete(list, 40);
    Llist_delete(list, 50);
    Llist_print(list);
    printf("\n");
    Llist_insert(list, 10);
    Llist_insert(list, 20);
    Llist_insert(list, 30);
    Llist_insert(list, 40);
    Llist_insert(list, 50);
    Llist_print(list);
    
    return 0;
}