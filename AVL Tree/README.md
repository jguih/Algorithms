# AVL Tree
 Implementação completa de uma árvore AVL em C. 
 
 O código inclui um menu para executar todas as funções facilmente.
## Estrutura dos nós da árvore AVL
```c
typedef struct Node
{
    int key; // number in node
    int bf; // balance factor
    int height; // height of node
    struct Node *left; 
    struct Node *right;
}Node;
```
## Funções
```c
Node* AVL_Tree_insert(int key, Node *Root) // Função para inserir na árvore AVL
```
```c
Node* AVL_Tree_delete(int key, Node *Root) // Função para deletar na árvore AVL
```
```c
int bf_calculator(Node *Root) // Calcula o fator de balanceamento e a altura a partir de uma raíz
```
```c
void AVL_Tree_print(Node *Root, int spaces) // Mostra a árvore AVL
```
```c
void AVL_Tree_destroy(Node *Root) // Destrói a árvore AVL
```
## Rotações de uma árvore AVL:

![AVL tree rotations](https://user-images.githubusercontent.com/62079543/115450372-2fbcec00-a1f2-11eb-94b0-8179c256b08c.png)

imagem tirada de: https://www.hackerrank.com
