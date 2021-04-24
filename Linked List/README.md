# Linked List
Implementação de uma lista encadeada em C.
## Estruturas
Nó da lista encadeada:
```c
struct LLNode
{
    int key; // valor do nó
    struct LL_Node *next;
};
```
Lista encadeada:
```c
struct LinkedList
{
    LLNode *head;
};
```
## Funções neste código
```c
LLNode* LLNode_create(int key); // função para criar um nó da lista
```
```c
int LLNode_key(LLNode *Node); // retorna a key do nó
```
```c
Llist* Llist_create(); // função para criar a lista
```
```c
LLNode* Llist_insert(Llist *list, int new_key); // função pra inserir na lista
```
```c
LLNode* Llist_insertend(Llist *list, LLNode *end, int key); // função para inserir no final da lista
```
```c
LLNode* Llist_delete(Llist *list, int key); // função para deletar na lista
```
```c
LLNode* Llist_deletehead(Llist *list); // função para remover a head da lista
```
```c
void Llist_print(Llist *list); // função para printar a lista
```
```c
int Llist_isempty(Llist *list); // função para verificar se a lista está vazia
```


