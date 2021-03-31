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
    Node *new_node, *aux = NULL, *aux_next;

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
            }  
            
        }
        else // Valor maior, começa na direita
        {
            if(Tree->Node->right == NULL) // Caso não tenha nenhum valor na direita
                Tree->Node->right = new_node;
            else
            {
                aux = Tree->Node->right; // aux e aux_next começam no primeiro valor da direita
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
                    
            Tree->Tree_size++;
        }
    }
}

// Algoritmo de busca para calcular a distancia entre um nó folha e a raiz da árvore
int Tree_search(Tree *Tree, int key)
{
    int hight = 0;
    Node *aux;

    if(Tree != NULL)  
    {
        if(Tree->Tree_size <= 1) // se ativer apenas a raiz ou nenhum valor, a altura é zero
            return hight;
        else
        {
            if(key < Tree->Node->key) // se key está na esquerda da árvore
            {
                aux = Tree->Node->left;
                hight++;
            }
            else // se key está na direita da árvore
            {
                aux = Tree->Node->right;
                hight++;
            } 
            
            while(aux->key != key)
            {
                if(key < aux->key) // esquerda
                    aux = aux->left;
                else // direita
                    aux = aux->right;

                hight++;
            }
            
        }
    }
    return hight;
}
           
// Algoritmo de percurso modificado para procurar nós-folha
void posfix(Node *Node, int *v, int *size) // retorna um vetor com os nós-folha e seu tamanho
{
    if(Node != NULL)
    {
        posfix(Node->left, v, size);
        posfix(Node->right, v, size);
        if(Node->left == NULL && Node->right == NULL) // nó-folha
        {
            // como o vetor já tem espaço para 1 int, então é realocado apenas após a inserção do primeiro valor
            if(*size > 0)
                v = realloc(v, sizeof(v) + sizeof(int));
            v[*size] = Node->key;
            *size = *size + 1;
        }
    }
}

int main() {

    int Tree_size; // tamanho da árvore
    int i; // auxiliar
    int key; // valor a ser inserido na árvore
    int *v = malloc(sizeof(int)); // vetor que armazena os nós-folha
    int *size = malloc(sizeof(int)); // tamanho do vetor
    int max_hight = 0; // altura máxima da árvore
    Tree *Tree = Tree_create(0);

    scanf("%d",&Tree_size);

    // insere valores na árvore
    for(i = 0; i < Tree_size; i++)
    {
        scanf("%d",&key);
        Tree_insert(Tree, key);
    }

    *size = 0;
    posfix(Tree->Node, v, size);
    
    // calcular todas as alturas a partir dos nó-folha e retorna a maior
    for(i = 0; i < *size; i++)
        if(Tree_search(Tree, v[i]) > max_hight)
            max_hight = Tree_search(Tree, v[i]);

    printf("%d",max_hight);

    return 0;
}
