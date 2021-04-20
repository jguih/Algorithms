# Red-Black Tree
Implementação da árvore Red-Black em C.
## Estrutura da árvore
```c
typedef struct RB_Node
{
    int key; // valor do noh
    char color; // cor do noh, 'r' vermelho e 'b' preto
    struct RB_Node *father;
    struct RB_Node *left; 
    struct RB_Node *right;
}RB_Node;
```
## Funções neste código
Para a função inserir é necessário informar 'count' como -1 e chamar a função Initialize_GobalVals() antes de cada inserção.
```c
RB_Node* RB_Tree_insert(int key, RB_Node *Root, int count) // inserir na árvore-RB
```
```c
void RB_Tree_print(RB_Node *Root, int spaces) // imprime a árvore RB
```
```c
void RB_Tree_destroy(RB_Node *Root) // destrói a árvore RB
```
```c
int RB_Tree_BHeight(RB_Node *Root) // calcula a altura negra de árvore RB
```
