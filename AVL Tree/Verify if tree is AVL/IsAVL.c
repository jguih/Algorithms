#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Nó
typedef struct Node
{
    int key; // valor
    int bf; // fator de balanceamento
    struct Node *left;
    struct Node *right;
}Node;

// Árvore Binária
typedef struct Tree
{
    Node *Root; // nó raiz
    int Node_count; // quantidade de nós na árvore
}Tree;

// Função para criar nós a partir de uma key
Node* Node_create(int key)
{
    Node *Node = malloc(sizeof(Node));

    Node->left = NULL;
    Node->right = NULL;
    Node->key = key;

    return Node;
}

// Função para criar a árvore
Tree* Tree_create()
{
    Tree *Tree = malloc(sizeof(Tree));
    Tree->Node_count = 0;
    return Tree;
}

void Tree_insert(Tree *Tree, int key)
{
    Node *new_node, *aux = NULL, *aux_next;

    if(Tree == NULL)
        Tree = Tree_create();

    new_node = Node_create(key);
    
    // Se não houver nenhum nó na árvore
    if(Tree->Node_count == 0)
    {
        Tree->Root = new_node;
        Tree->Node_count++;
    }
    else 
    {
        if(key < Tree->Root->key) // Se o valor for menor, começa na esquerda
        {
            if(Tree->Root->left == NULL) // Caso não tenha nenhum valor na esquerda
                Tree->Root->left = new_node;
            else
            {
                aux = Tree->Root->left; // aux e aux_next começam no primeiro valor da esquerda
                aux_next = aux;
            }  
            
        }
        else // Valor maior, começa na direita
        {
            if(Tree->Root->right == NULL) // Caso não tenha nenhum valor na direita
                Tree->Root->right = new_node;
            else
            {
                aux = Tree->Root->right; // aux e aux_next começam no primeiro valor da direita
                aux_next = aux;
            }
            
        }
        if(aux != NULL) // Verifico se o aux foi iniciado
        {
            // aux_next para no endereço onde o novo nó deve ser inserido
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
                    
            Tree->Node_count++;
        }
    }
}

// função recursiva que calcula o bf de cada nó da árvore
int bf_calculator(Node *Node)
{
    if(Node == NULL)
        return 0;
    else
    {
        Node->bf = bf_calculator(Node->left) - bf_calculator(Node->right); 
        return fmax(bf_calculator(Node->left), bf_calculator(Node->right)) + 1; 
    }
}

// Verifica se a árvore é AVL, aux recebe o valor 0 caso seja
void Tree_is_AVL(Node *Node, int *aux)
{
    if(Node != NULL)
    {
        Tree_is_AVL(Node->left, aux);
        Tree_is_AVL(Node->right, aux);
        if(Node->bf < -1 || Node->bf > 1)
            *aux = 0;
    }
}

int main() {

    int Node_counter; // quantida de nós
    int i; // auxiliar
    int key; // valor inserido na árvore
    int *aux = malloc(sizeof(int)); // variável de retorno
    Tree *Tree = Tree_create();
    
    scanf("%d",&Node_counter);

    // Inserção de valores na árvore
    for(i = 0; i < Node_counter; i++)
    {
        scanf("%d",&key);
        Tree_insert(Tree, key);
    }

    bf_calculator(Tree->Root);

    *aux = 1; // dizemos que a árvore é AVL até que a função abaixo prove o contrário
    Tree_is_AVL(Tree->Root, aux);
    printf("%d",*aux);

    free(Tree);
    free(aux);

    return 0;
}
