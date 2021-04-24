# Queue
Implementação de uma fila em C.
## Estrutura
Nó da Queue:
```c
struct QueueNode
{
    int key;
    struct QueueNode *next;
};
```
Queue:
```c
struct Queue
{
    QueueNode *front; // inicio
    QueueNode *back; // fim
};
```
## Funções neste código
```c
Queue* Queue_create(); // função para criar a fila
```
```c
void Enqueue(Queue *q, int key); // função para enfileirar
```
```c
int Dequeue(Queue *q); // função para desenfileirar
```
```c
void Queue_print(Queue *q); // função para imprimir a fila
```
