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
LL_Node* LL_Node_create(int key); // função para criar um nó da lista
```
```c
int LL_Node_key(LL_Node *Node); // retorna a key do nó
```
```c
Llist* Llist_create(); // função para criar a lista
```
```c
LL_Node* Llist_insert(Llist *list, int new_key); // função pra inserir na lista
```
```c
LL_Node* Llist_delete(Llist *list, int key); // função para deletar na lista
```
```c
void Llist_print(Llist *list); // função para printar a lista
```
```c
int Llist_isempty(Llist *list); // função para verificar se a lista está vazia
```
```c
LL_Node* Llist_deletehead(Llist *list); // função para remover a head da lista
```

