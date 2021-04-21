#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct BT_Node
{
    int key; // valor do noh
    struct BT_Node *left;
    struct BT_Node *right;
}BT_Node;

// funcao para criar o noh da arvore binaria
BT_Node* BTNode_create(int key)
{
    BT_Node *Node = malloc(sizeof(BT_Node));

    Node->left = NULL;
    Node->right = NULL;
    Node->key = key;

    return Node;
}

// funcao para inserir na arvore binaria
BT_Node* BT_insert(BT_Node *Root, int key)
{
    if(Root == NULL)
        return Root = BTNode_create(key);
    else if(key > Root->key)
        Root->right = BT_insert(Root->right, key);
    else if(key < Root->key)
        Root->left = BT_insert(Root->left, key);
    return Root;
}

// funcao para buscar na arvore binaria
int BT_search(BT_Node *Root, int key)
{
    if(Root == NULL)
        return 0;

    else if(key < Root->key)
        BT_search(Root->left, key);
    else if(key > Root->key)
        BT_search(Root->right, key);
    else
        return 1;
}

int i;      
// funcao para imprimir a arvore binaria
void BT_print(BT_Node *Root, int spaces)
{
    if(Root != NULL)
    {
        spaces++;
        BT_print(Root->right, spaces);
        
        // imprime os espacos
        printf("\n");
        for(i = 1; i < spaces; i++)
            printf("\t");
        // imprime o valor do noh
        printf("%d\n", Root->key);

        BT_print(Root->left, spaces);
    }
}

// funcao para calcular a altura da arvore binaria
int BT_height(BT_Node *Root)
{
    if(Root == NULL)
        return -1;
    else
        return fmax(BT_height(Root->left), BT_height(Root->right)) + 1;
}

// funcao que retorna o sucessor
BT_Node* InOrderSuccessor(BT_Node *Right)
{
    while(Right != NULL && Right->left != NULL)
        Right = Right->left;
    return Right;
}

// funcao que retorna o predecessor
BT_Node* InOrderPredecessor(BT_Node *Left)
{
    while(Left != NULL && Left->right != NULL)
        Left = Left->right;
    return Left;
}

char first; // variavel auxiliar para a funcao BT_delete
void Initialize_GlobalVals()
{
    first = 'y';
}

// funcao para deletar um noh na arvore binaria
BT_Node* BT_delete(BT_Node *Root, int key)
{
    BT_Node *aux; // noh auxiliar
    
    if(Root == NULL)
        return NULL;
    
    // cadeia de if/else para procurar o noh a ser deletado
    if(key < Root->key)
        Root->left = BT_delete(Root->left, key);
    else if(key > Root->key)
        Root->right = BT_delete(Root->right, key);
    else // se o noh foi encontrado
    {
        if(first == 'y')
        {
            printf("\nNode %d deleted\n",Root->key);
            first = 'n';
        }

        // se o noh puder ser deletado
        if(Root->left == NULL && Root->right == NULL)
        {
            free(Root);
            return NULL;
        }
        else // caso hajam subarvores, eh necessario encontrar um sucessor ou predecessor
        {
            if(Root->right == NULL && Root->left != NULL)
            {
                aux = InOrderPredecessor(Root->left); // aux substitui o noh que sera deletado
                Root->key = aux->key; // a key do predecessor eh transferida para o noh que seria deletado
                Root->left = BT_delete(Root->left, aux->key); // chama a funcao novamente para deletar o predecessor
            }
            else if(Root->left == NULL && Root->right != NULL)
            {
                aux = InOrderSuccessor(Root->right);
                Root->key = aux->key; // a key do sucessor eh transferida para o noh que seria deletado
                Root->right = BT_delete(Root->right, aux->key); // chama a funcao novamente para deletar o sucessor
            }
            else if(Root->left != NULL && Root->right != NULL)
            {
                // se houverem ambas as subtrees entao eh decidido pela altura delas
                if(BT_height(Root->left) > BT_height(Root->right))
                {
                    aux = InOrderPredecessor(Root->left); 
                    Root->key = aux->key;
                    Root->left = BT_delete(Root->left, aux->key);
                }
                else
                {
                    aux = InOrderSuccessor(Root->right); 
                    Root->key = aux->key;
                    Root->right = BT_delete(Root->right, aux->key);
                }
            }
        }
    }
    return Root;
}

int main() {
    BT_Node *Root = NULL;

    // sample input:
    Root = BT_insert(Root, 10);
    Root = BT_insert(Root, 20);
    Root = BT_insert(Root, 5);
    Root = BT_insert(Root, 30);
    Root = BT_insert(Root, 4);
    Root = BT_insert(Root, 32);

    BT_print(Root, 0);
    printf("\nHeight: %d",BT_height(Root));

    if(BT_search(Root, 32))
        printf("\n32 found");
    else
        printf("32 not found");

    Initialize_GlobalVals();
    BT_delete(Root, 32);

    if(BT_search(Root, 32))
        printf("\n32 found");
    else
        printf("32 not found");

    BT_print(Root, 0);
    printf("\nHeight: %d",BT_height(Root));

    Initialize_GlobalVals();
    BT_delete(Root, 10);

    BT_print(Root, 0);
    printf("\nHeight: %d",BT_height(Root));

    return 0;
}
