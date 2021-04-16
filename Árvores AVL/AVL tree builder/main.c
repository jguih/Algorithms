#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node
{
    int key; // number in node
    int bf; // balance factor
    int height; // height of node
    struct Node *left; 
    struct Node *right;
}Node;

// perform LL Rotation
Node* LL_Rotation(Node *Unb_Node)
{
    Node *pl = Unb_Node->left;

    Unb_Node->left = pl->right;  
    pl->right = Unb_Node;

    bf_calculator(pl);

    return pl;
}

// perform LR Rotation
Node* LR_Rotation(Node *Unb_Node)
{
    Node *plr = Unb_Node->left->right;
    Node *pl = Unb_Node->left;

    Unb_Node->left = plr->right;
    pl->right = plr->left;
    plr->left = pl;
    plr->right = Unb_Node;

    bf_calculator(plr);

    return plr;
}

// perform RR Rotation
Node* RR_Rotation(Node *Unb_Node)
{
    Node *pr = Unb_Node->right;

    Unb_Node->right = pr->left;
    pr->left = Unb_Node;

    bf_calculator(pr);

    return pr;
}

// perform RL Rotation
Node* RL_Rotation(Node *Unb_Node)
{
    Node *prl = Unb_Node->right->left;
    Node *pr = Unb_Node->right;

    Unb_Node->right = prl->left;
    pr->left = prl->right;
    prl->left = Unb_Node;
    prl->right = pr;

    bf_calculator(prl);

    return prl;
}

// function to insert into the tree
Node* AVL_Tree_insert(int key, Node *Root)
{
    Node *aux;

    // if/else chain to look for the right place to insert the new node
    if(Root == NULL)
    {
        // allocating the new node
        aux = (Node*) malloc(sizeof(Node));
        aux->key = key;
        aux->left = aux->right = NULL;
        // calculate the balance factor for the new (leaf) node
        bf_calculator(aux);
        return aux;
    }
    else if(key < Root->key)
        Root->left = AVL_Tree_insert(key, Root->left);
    else if(key > Root->key)
        Root->right = AVL_Tree_insert(key, Root->right);

    // calculate the balance factor for each node
    bf_calculator(Root);

    // perform rotations
    if(Root->bf == 2 && Root->left->bf == 1)
        Root = LL_Rotation(Root);
    else if(Root->bf == 2 && Root->left->bf == -1)
        Root = LR_Rotation(Root);
    else if(Root->bf == 2 && Root->left->bf == 0)
        Root = LL_Rotation(Root); // here it could be both rotations
    else if(Root->bf == -2 && Root->right->bf == -1)
        Root = RR_Rotation(Root);
    else if(Root->bf == -2 && Root->right->bf == 1)
        Root = RL_Rotation(Root);
    else if(Root->bf == -2 && Root->right->bf == 0)
        Root = RR_Rotation(Root); // here it could be both rotations

    return Root;
}

// function to return the Successor
Node* InOrderSuccessor(Node *Right)
{
    while(Right != NULL && Right->left != NULL)
        Right = Right->left;
    return Right;
}

// function to return the Predecessor
Node* InOrderPredecessor(Node *Left)
{
    while(Left != NULL && Left->right != NULL)
        Left = Left->right;
    return Left;
}

char first = 'y';
// function to delete in the tree
Node* AVL_Tree_delete(int key, Node *Root)
{
    Node *aux;
    
    if(Root == NULL)
        return NULL;
    
    // if/else chain to look for the node to delete
    if(key < Root->key)
        Root->left = AVL_Tree_delete(key, Root->left);
    else if(key > Root->key)
        Root->right = AVL_Tree_delete(key, Root->right);
    else
    {
        // if the node was found, then it's printed and deleted
        if(first == 'y')
        {
            printf("Node %d deleted\n",Root->key);
            first = 'n';
        }

        if(Root->left == NULL && Root->right == NULL)
        {
            // if the node can be deleted
            
            free(Root);
            return NULL;
        }
        else // if it can't
        {
            // it's necessary to find a successor or a predecessor to replace the node to be deleted
            if(Root->right == NULL && Root->left != NULL)
            {
                aux = InOrderPredecessor(Root->left); // aux node is replacing the node to be deleted
                Root->key = aux->key; // the predecessor key is replaced in the node to be deleted
                Root->left = AVL_Tree_delete(aux->key, Root->left); // call the function again to look for the predecessor and delete it
            }
            else if(Root->left == NULL && Root->right != NULL)
            {
                aux = InOrderSuccessor(Root->right);
                Root->key = aux->key; // the successor key is replaced in the node to be deleted
                Root->right = AVL_Tree_delete(aux->key, Root->right); // call the function again to look for the successor and delete it
            }
            else if(Root->left != NULL && Root->right != NULL)
            {
                // if there are both left and right subtrees, then it's decided by the height
                if(Root->left->height > Root->right->height)
                {
                    aux = InOrderPredecessor(Root->left); 
                    Root->key = aux->key;
                    Root->left = AVL_Tree_delete(aux->key, Root->left);
                }
                else
                {
                    aux = InOrderSuccessor(Root->right); 
                    Root->key = aux->key;
                    Root->right = AVL_Tree_delete(aux->key, Root->right);
                }
            }
        }
    }

    // calculate the balance factor for each node
    bf_calculator(Root);

    // perform rotations
    if(Root->bf == 2 && Root->left->bf == 1)
        Root = LL_Rotation(Root);
    else if(Root->bf == 2 && Root->left->bf == -1)
        Root = LR_Rotation(Root);
    else if(Root->bf == 2 && Root->left->bf == 0)
        Root = LL_Rotation(Root); // here it could be both rotations
    else if(Root->bf == -2 && Root->right->bf == -1)
        Root = RR_Rotation(Root);
    else if(Root->bf == -2 && Root->right->bf == 1)
        Root = RL_Rotation(Root);
    else if(Root->bf == -2 && Root->right->bf == 0)
        Root = RR_Rotation(Root); // here it could be both rotations

    return Root;
}

// function to calculate and update the balance factor and height of nodes
int bf_calculator(Node *Root)
{
    if(Root == NULL)
        return 0;
    else
    {
        Root->height = fmax(bf_calculator(Root->left),bf_calculator(Root->right)) + 1;

        if(Root->left == NULL && Root->right != NULL)
            Root->bf = (-1) * (Root->right->height);
        else if(Root->right == NULL && Root->left != NULL)
            Root->bf = Root->left->height;
        else if(Root->left != NULL && Root->right != NULL)
            Root->bf = Root->left->height - Root->right->height;
        else // both are NULL
            Root->bf = 0;
        
        return Root->height;
    }
}

int i; // global val for print

// function to print the tree
void AVL_Tree_print(Node *Root, int spaces)
{
    if(Root != NULL)
    {   
        spaces++;
        AVL_Tree_print(Root->right, spaces);

        printf("\n");
        for(i = 1; i < spaces; i++)
            printf("\t"); 
        
        printf("%d:%d:%d \n",Root->key,Root->bf,Root->height);

        AVL_Tree_print(Root->left, spaces);
    }
}

// function to free the entire tree
void AVL_Tree_destroy(Node *Root)
{
    if(Root != NULL)
    {
        AVL_Tree_destroy(Root->left);
        AVL_Tree_destroy(Root->right);
        free(Root);
    }
}

int main()
{
    int answer;
    int key;
    Node *Root = NULL;
    
    do
    {
        printf("Select an option:\n");
        printf("1-Insert into the tree\n");
        printf("2-Print the tree\n");
        printf("3-Remove element from tree\n");
        printf("4-Clear Screen\n");
        printf("5-Detroy Tree\n");
        printf("6-Finish program\n");
        printf("Option: ");
        scanf("%d",&answer);

        switch (answer)
        {
        case 1: // insert
            printf("The tree will be printed each time you insert a new value, if you want to stop insert any negative number\n");
            do
            {
                printf("Insert value: ");
                scanf("%d",&key);
                if(key >= 0)
                {
                    Root = AVL_Tree_insert(key, Root);
                    AVL_Tree_print(Root, 0);
                    printf("\n");
                    printf("subtitle -> number:balanceFactor:height\n\n");
                }
            } while (key >= 0);
            system("cls");
            break;
        case 2: // print
            AVL_Tree_print(Root, 0);
            printf("\n");
            printf("subtitle -> number:balanceFactor:height\n\n");
            break;
        case 3: // delete node
            system("cls");
            printf("Insert the number to be deleted: ");
            scanf("%d",&key);
            first = 'y';
            Root = AVL_Tree_delete(key, Root);
            AVL_Tree_print(Root, 0);
            printf("\n");
            printf("subtitle -> number:balanceFactor:height\n\n");
            break;
        case 4: // clear screen
            system("cls");
            break;
        case 5: // detroy the tree
            AVL_Tree_destroy(Root);
            Root = NULL;
            system("cls");
        }
    } while (answer != 6);

    return 0;
}