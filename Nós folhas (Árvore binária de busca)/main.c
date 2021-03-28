#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Nó
typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
}Node;

// Árvore Binária
typedef struct Tree
{
    Node *Node; 
    int Tree_size; // tamanho da árvore
}Tree;

Node* Node_create(int key)
{
    Node *Node = malloc(sizeof(Node));

    Node->left = NULL;
    Node->right = NULL;
    Node->key = key;

    return Node;
}

Tree* Tree_create(int Tree_size)
{
    Tree *Tree = malloc(sizeof(Tree));
    Tree->Tree_size = Tree_size;
    return Tree;
}

void Tree_insert(Tree *Tree, int key)
{
    Node *new_node, *aux, *aux_next;

    if(Tree == NULL)
        Tree = Tree_create(0);

    new_node = Node_create(key);
    
    // Se não houver nenhum nó na árvore
    if(Tree->Tree_size == 0)
    {
        Tree->Node = new_node;
        Tree->Tree_size++;
    }
    else 
    {
        if(key < Tree->Node->key) // Se o valor for menor, começa na esquerda
        {
            if(Tree->Node->left == NULL) // Caso não tenha nenhum valor na esquerda
                Tree->Node->left = new_node;
            else
            {
                aux = Tree->Node->left; // aux e aux_next começam no primeiro valor da esquerda
                aux_next = aux;

                // aux_next para no endereço onde o novo valor deve ser inserido
                // aux sempre para no nó anterior
                while(aux_next != NULL)
                {
                    if(key < aux_next->key) // esquerda
                    {
                        aux = aux_next;
                        aux_next = aux_next->left;
                    }
                    else // direita
                    {
                        aux = aux_next;
                        aux_next = aux_next->right;
                    }
                        
                }
                aux_next = new_node; // aux_next recebe o novo nó
                
                // faz o aux apontar para aux_next
                if(aux_next->key < aux->key) // esquerda
                    aux->left = aux_next;
                else // direita
                    aux->right = aux_next;

                Tree->Tree_size++;
            }  
            
        }
        else // Valor maior, começa na direita
        {
            if(Tree->Node->right == NULL)
                Tree->Node->right = new_node;
            else
            {
                aux = Tree->Node->right;
                aux_next = aux;

                // aux_next para no endereço onde o novo valor deve ser inserido
                // aux sempre para no nó anterior
                while(aux_next != NULL)
                {
                    if(key < aux_next->key) // esquerda
                    {
                        aux = aux_next;
                        aux_next = aux_next->left;
                    }
                    else // direita
                    {
                        aux = aux_next;
                        aux_next = aux_next->right;
                    }
                        
                }
                aux_next = new_node; // aux_next recebe o novo nó

                // faz o aux apontar para aux_next
                if(aux_next->key < aux->key) // esquerda
                    aux->left = aux_next;
                else // direita
                    aux->right = aux_next;
                    
                Tree->Tree_size++;
            }
            
        }
    }
}

// Algoritmo de percurso modificado para procurar nós-folha
void posfix(Node *Node)
{
    if(Node != NULL)
    {
        posfix(Node->left);
        posfix(Node->right);
        if(Node->left == NULL && Node->right == NULL) 
            printf("%d ",Node->key);
    }
}

int main() {

    Node *aux;
    int Tree_size, i, key;
    Tree *Tree = Tree_create(0);

    scanf("%d",&Tree_size);

    for(i = 0; i < Tree_size; i++)
    {
        scanf("%d",&key);
        Tree_insert(Tree, key);
    }

    posfix(Tree->Node);

    return 0;
}
