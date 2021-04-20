# B-Tree
Implementação de uma árvore-B em C.
## Estrutura dos nós da árvore-B
```c
typedef struct BTree_Node
{
    int key[N]; // vetor de valores
    int n_key; // quantidade de chaves armazenadas
    struct BTree_Node *child[N+1]; // vetor dos filhos
    int is_leaf; // 1 se é folha, 0 caso contrário
}BTree_Node;
```
## Funções neste código
A função inserir precisa receber -1 na variável count. E é necessário utilizar a função Initialize_GlobalVals() para seu correto funcionamento
```c
BTree_Node* BTree_Insert(BTree_Node *tree, int key, int count) // inserir na árvore-B
```
Outras funções:
```c
int binary_search(BTree_Node *node, int key) // pesquisa binária
```
```c
int BTree_Search(BTree_Node *tree, int key) // pesquisar valores na árvore-B
```
```c
BTree_Node* Split(BTree_Node *father, int p_fullChild) // função Split da árvore-B
```
```c
int BTree_Height(BTree_Node *tree) // calcula a altura de uma árvore-B
```
```c
void BTree_PagesC(BTree_Node *tree, int *count) // conta a quantidade de páginas da árvore-B
```
```c
void BTree_Print(BTree_Node *tree) // imprime a árvore-B
```
```c
void BTree_Media(BTree_Node *tree) // função recursiva auxiliar para calcular a média dos elementos dos nós folha
```
