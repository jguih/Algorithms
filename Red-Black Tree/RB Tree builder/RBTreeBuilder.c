#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct RB_Node
{
    int key; // valor do noh
    char color; // cor do noh, 'r' vermelho e 'b' preto
    struct RB_Node *father;
    struct RB_Node *left; 
    struct RB_Node *right;
}RB_Node;

// LL Rotation
RB_Node* LL_Rotation(RB_Node *Unb_Node)
{
    RB_Node *pl = Unb_Node->left;

    Unb_Node->left = pl->right;  
    pl->right = Unb_Node;
    // atualizando os pais
    pl->father = Unb_Node->father;
    pl->left->father = pl->right->father = pl;
    // atualizando as cores
    pl->color = 'b';
    pl->right->color = 'r';

    return pl;
}

// LR Rotation
RB_Node* LR_Rotation(RB_Node *Unb_Node)
{
    RB_Node *plr = Unb_Node->left->right;
    RB_Node *pl = Unb_Node->left;

    Unb_Node->left = plr->right;
    pl->right = plr->left;
    plr->left = pl;
    plr->right = Unb_Node;
    // atualizando os pais
    plr->father = Unb_Node->father;
    plr->left->father = plr->right->father = plr;
    // atualizando as cores
    plr->color = 'b';
    plr->right->color = 'r';

    return plr;
}

// RR Rotation
RB_Node* RR_Rotation(RB_Node *Unb_Node)
{
    RB_Node *pr = Unb_Node->right;

    Unb_Node->right = pr->left;
    pr->left = Unb_Node;
    // atualizando os pais
    pr->father = Unb_Node->father;
    pr->left->father = pr->right->father = pr;
    // atualizando as cores
    pr->color = 'b';
    pr->left->color = 'r';

    return pr;
}

// RL Rotation
RB_Node* RL_Rotation(RB_Node *Unb_Node)
{
    RB_Node *prl = Unb_Node->right->left;
    RB_Node *pr = Unb_Node->right;

    Unb_Node->right = prl->left;
    pr->left = prl->right;
    prl->left = Unb_Node;
    prl->right = pr;
    // atualizando os pais
    prl->father = Unb_Node->father;
    prl->left->father = prl->right->father = prl;
    // atualizando as cores
    prl->color = 'b';
    prl->left->color = 'r';

    return prl;
}

// funcao recolor para a RB Tree
void RB_Recolor(RB_Node *Root)
{
    Root->color = 'r';
    Root->left->color = 'b';
    Root->right->color = 'b';
}

// variavel global para auxiliar a funcao inserir
// o tamanho do vetor pode ser equivalente a altura da arvore
RB_Node *prev_node[10];

void Initialize_GobalVals()
{
    int i;
    for(i = 0; i < 10; i++)
        prev_node[i] = NULL;
}

// funcao para inserir na RB Tree (baseado na insercao da arvore AVL)
RB_Node* RB_Tree_insert(int key, RB_Node *Root, int count)
{
    RB_Node *aux; // novo noh que sera inserido

    // prev_node armazena os enderecos dos nohs de iteracoes anteriores
    count++;
    prev_node[count] = Root;

    // cadeia de if/else para encontrar o lugar certo para inserir o novo noh
    if(Root == NULL)
    {
        // aloca o novo noh
        aux = (RB_Node*) malloc(sizeof(RB_Node));
        aux->key = key;
        aux->left = aux->right = NULL;

        if(count-1 >= 0)
            aux->father = prev_node[count-1]; // father recebe o noh anterior
        else
            aux->father = NULL;
        
        aux->color = 'r'; // todo novo noh eh vermelho
        return aux;
    }
    else if(key < Root->key)
        Root->left = RB_Tree_insert(key, Root->left, count);
    else if(key > Root->key)
        Root->right = RB_Tree_insert(key, Root->right, count);

    // para cada noh, eh verificado se houve falta de balanceamento
    if(Root->left != NULL && Root->left->left != NULL)
    {
        if(Root->left->color == 'r' && Root->left->left->color == 'r')
        {
            if(Root->right == NULL) // se o tio nulo
                Root = LL_Rotation(Root);
            else if(Root->right->color == 'b') // se o tio for preto
                Root = LL_Rotation(Root);
            else
                RB_Recolor(Root);
        }
    }
    if(Root->left != NULL && Root->left->right != NULL)
    {
        if(Root->left->color == 'r' && Root->left->right->color == 'r')
        {
            if(Root->right == NULL)
                Root = LR_Rotation(Root);
            else if (Root->right->color == 'b')
                Root = LR_Rotation(Root);
            else
                RB_Recolor(Root);
        }
    }
    if(Root->right != NULL && Root->right->right != NULL)
    {
        if(Root->right->color == 'r' && Root->right->right->color == 'r')
        {
            if(Root->left == NULL)
                Root = RR_Rotation(Root);
            else if(Root->left->color == 'b')
                Root = RR_Rotation(Root);
            else
                RB_Recolor(Root);
        }
    }
    if(Root->right != NULL && Root->right->left != NULL)
    {
        if(Root->right->color == 'r' && Root->right->left->color == 'r')
        {
            if(Root->left == NULL)
                Root = RL_Rotation(Root);
            else if(Root->left->color == 'b')
                Root = RL_Rotation(Root);
            else
                RB_Recolor(Root);
        }
    }

    if(count-1 < 0) // se eh raiz
            Root->color = 'b';

    return Root;
}

int i; // variavel global para a funcao RB_Tree_print
// funcao para imprimir a RB Tree
void RB_Tree_print(RB_Node *Root, int spaces)
{
    if(Root != NULL)
    {   
        spaces++;
        RB_Tree_print(Root->right, spaces);

        printf("\n");
        for(i = 1; i < spaces; i++)
            printf("\t"); 
        
        printf("%d:%c \n",Root->key,Root->color);

        RB_Tree_print(Root->left, spaces);
    }
}

// funcao para liberar a arvore
void RB_Tree_destroy(RB_Node *Root)
{
    if(Root != NULL)
    {
        RB_Tree_destroy(Root->left);
        RB_Tree_destroy(Root->right);
        free(Root);
    }
}

// funcao para calcular a altura negra
int RB_Tree_BHeight(RB_Node *Root)
{
    int height = 0;
    Root = Root->left; // a raiz nao eh considerada
    
    while(Root != NULL)
    {
        if(Root->color == 'b')
            height++;
        Root = Root->left;
    }
    
    return height+1; // contando o noh nulo
}

int main()
{
    RB_Node *Root = NULL;

    // sample input:
    Root = RB_Tree_insert(38, Root, -1);
    Initialize_GobalVals();
    Root = RB_Tree_insert(40, Root, -1);
    Initialize_GobalVals();
    Root = RB_Tree_insert(21, Root, -1);
    Initialize_GobalVals();
    Root = RB_Tree_insert(18, Root, -1);
    Initialize_GobalVals();
    Root = RB_Tree_insert(30, Root, -1);
    Initialize_GobalVals();
    Root = RB_Tree_insert(22, Root, -1);
    Initialize_GobalVals();
    Root = RB_Tree_insert(37, Root, -1);
    Initialize_GobalVals();
    Root = RB_Tree_insert(8, Root, -1);
    Initialize_GobalVals();
    Root = RB_Tree_insert(70, Root, -1);

    RB_Tree_print(Root, 0);
    printf("\nBlack Height: %d\n",RB_Tree_BHeight(Root));

    return 0;
}