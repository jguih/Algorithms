typedef struct Queue Queue;

Queue* Queue_create(); // funcao para criar a fila
void Enqueue(Queue *q, int key); // funcao para enfileirar
int Dequeue(Queue *q); // funcao para desenfileirar
void Queue_print(Queue *q); // funcao para imprimir a fila