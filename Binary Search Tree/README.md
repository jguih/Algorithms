# Binary Search Tree
 Implementação completa de uma árvore binária de busca em C. 

 https://en.wikipedia.org/wiki/Binary_search_tree
 
## Estrutura
```c
typedef struct BT_Node
{
    int key; // valor do nó
    struct BT_Node *left;
    struct BT_Node *right;
}BT_Node;
```
## Funções neste código
```c
BT_Node* BTNode_create(int key) // Função para criar o nó da BSTree
```
```c
BT_Node* BT_insert(BT_Node *Root, int key) // Função para inserir na BSTree
```
```c
int BT_search(BT_Node *Root, int key) // Função para procurar um valor na BSTree
```
A função BT_print precisa receber 0 em spaces sempre que for chamada
```c
void BT_print(BT_Node *Root, int spaces) // Função para mostrar a BSTree
```
```c
int BT_height(BT_Node *Root) // Função para calcular a altura a partir de uma raíz
```
A função void Initialize_GlobalVals() precisa ser chamada antes de um nó ser deletado
```c
BT_Node* BT_delete(BT_Node *Root, int key) // Função para deleter um nó da BSTree
```

