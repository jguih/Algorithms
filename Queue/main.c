#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main()
{
    Queue *q = Queue_create();

    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);
    Enqueue(q, 40);
    Dequeue(q);
    Enqueue(q, 50);
    Dequeue(q);
    Dequeue(q);
    
    Queue_print(q);

    return 0;
}