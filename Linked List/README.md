# Linked List
Implementação de uma lista encadeada em C.
## Estruturas
Nó da lista encadeada:
```c
struct LL_Node
{
    int key; // valor do nó
    struct LL_Node *next;
};
```
Lista encadeada:
```c
struct LinkedList
{
    int size; // quantidade de valores na lista
    LL_Node *head;
};
```
## Funções neste código
```c
LL_Node* LL_Node_create(int key); // Criar o nó
```
```c
Llist* Llist_create(); // Cria a lista
```
```c
Llist* Llist_insert(Llist *list, int new_key); // Insere na lista encadeada
```
```c
void Llist_delete(Llist *list, int key); // Deleta na lista encadeada
```
```c
void Llist_print(Llist *list); // Mostra a lista
```
