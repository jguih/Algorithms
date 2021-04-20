#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define N 5

typedef struct BTree_Node
{
    int key[N]; // vetor de valores que permite overflow
    int n_key; // quantidade de chaves armazenadas
    struct BTree_Node *child[N+1]; // vetor dos filhos
    int is_leaf; // 1 se é folha, 0 caso contrário
}BTree_Node;

BTree_Node* BTree_Node_Create()
{
    int i;
    BTree_Node *Node = malloc(sizeof(BTree_Node));

    Node->is_leaf = 1; // nó é folha
    Node->n_key = 0;

    // iniciando nós filho
    for(i = 0; i < N; i++)
        Node->child[i] = NULL;

    return Node;
}

// função de pesquisa binária auxiliar
int binary_search(BTree_Node *node, int key)
{
    int start, end, middle;

    if(node != NULL)
    {
        start = 0;
        end = node->n_key - 1;
    
        while(start <= end)
        {
            middle = (start + end)/2;

            if(node->key[middle] == key)
                return middle; // chave encontrada
            else if(key < node->key[middle])
                end = middle -1;
            else
                start = middle + 1;
        }

        return start; // se a chave não for encontrada então é retornada a posição do filho onde a chave possa estar
    }

    return -1; // se o nó for nulo
}

// função para pesquisar o valor na árvore
int BTree_Search(BTree_Node *tree, int key)
{
    int p = binary_search(tree, key);

    if(p >= 0) // -1 quando tree = NULL
    {
        if(tree->key[p] == key)
            return 1;
        else
            return BTree_Search(tree->child[p], key); // chamada recursiva para verificar o filho
    }

    return 0;
}

/* 
    father = nó pai do filho onde a tentativa de inserçào foi feita
    p_fullChild = posiçào do filho cheio
*/
BTree_Node* Split(BTree_Node *father, int p_fullChild)
{
    // o nó cheio vai ser dividido em esquerda e direita:
    BTree_Node *left; // irá conter os N/2 menores valores
    BTree_Node *right; // irá conter os N/2 maiores valores
    int i, j = 0; // auxiliares
    int meio = N/2;

    // inicia os nós resultantes do split
    left = BTree_Node_Create();
    right = BTree_Node_Create();
    
    // aloca os valores de left e right
    for(i = 0; i < meio; i++)
    {
        left->key[i] = father->child[p_fullChild]->key[i];
        left->n_key++;
    }
    for(i = meio + 1; i < N; i++)
    {
        right->key[j] = father->child[p_fullChild]->key[i];
        right->n_key++;
        j++;
    }
    j = 0;

    // se o filho que está cheio não for nó folha, então o Split ocorre em nós internos
    if(!father->child[p_fullChild]->is_leaf)
        left->is_leaf = right->is_leaf = 0;

    // se o split ocorrer em nós internos, é necessário que left e right receberam os filhos do nó cheio
    if(!left->is_leaf)
    {
        // alocando os filhos de left e right
        for(i = 0; i <= meio; i++)
            left->child[i] = father->child[p_fullChild]->child[i];
        for(i = meio + 1; i <= N; i++)
        {
            right->child[j] = father->child[p_fullChild]->child[i];
            j++;
        }
    }

    // realoca as chaves do pai para a inserção da chave promovida
    for (i = father->n_key; i > p_fullChild; i--)
        father->key[i] = father->key[i-1];
    
    // realoca os filhos do pai para a inserção do novo filho (right)
    for(i = father->n_key + 1; i > p_fullChild + 1; i--)
        father->child[i] = father->child[i-1];

    // pai recebe o valor promovido
    father->key[p_fullChild] = father->child[p_fullChild]->key[meio];
    father->n_key++;

    // filhos left e right são atualizados
    father->child[p_fullChild] = left;
    father->child[p_fullChild + 1] = right;
    
    /*
        Left é retornado devido a mudança no filho que estava cheio:
        father->child[p_fullChild] = left;
        logo este é o único filho que precisa ser retornado e atualizado
        na função BTree_Insert
    */
    return left;
}

// Variáveis auxiliares globais para a funçõa BTree_Insert
BTree_Node *aux[10];
int p[10];

// função para iniciar as variáveis globais, é obrigatório seu uso antes de uma inserção
void Initialize_GlobalVals()
{
    int i;

    for(i = 0; i < 10; i++)
    {
        aux[i] = NULL;
        p[i] = -1;
    }
}

// função para inserir na árvoreB
BTree_Node* BTree_Insert(BTree_Node *tree, int key, int count)
{
    BTree_Node *new_root; // Nova raíz
    int i; // Auxiliar

    /*
        A variável "count" conta a iteração desta função.
        Ela começa em -1 e é incrementada a cada chamada recursiva,
        portanto ela deve ser passada por parâmetro para que a função saiba
        qual iteração está sendo feita, pois assim caso "count-1" seja < 0
        sabemos que estamos na raíz
    */
    count++; 
    aux[count] = tree; // Auxiliar global que armazena todos os endereços da árvoreB, atual e anteriores
    p[count] = binary_search(tree, key); // Auxiliar global que armazena o "caminho" até a inserção
    

    if(tree == NULL)
        tree = BTree_Node_Create();
    if(!tree->is_leaf)
        // chamada recursiva até que a função alcançe um nó folha
        tree->child[p[count]] = BTree_Insert(tree->child[p[count]], key, count);
    else
    {
        // deslocamento nos elementos da página para a inserção da nova key
        for(i = tree->n_key; i > p[count]; i--)
            tree->key[i] = tree->key[i - 1];
        
        // a nova key é alocada idependente de ter espaço ou não
        tree->key[i] = key; 
        tree->n_key++;
    }

    // então é verificado se ocorreu um overflow
    if(tree->n_key == N)
    {
        /*
            Usando programação dinâmica, as variáveis aux e p
            armazenam os valores de iterações anteriores, pois
            é necessário ter acesso aos pais a qualquer momento
        */
        if(count-1 >= 0)
            /* 
                Como o filho em p é retornado caso não haja overflow,
                é necessário que o Split retorne o mesmo filho
                para que este seja atualizado.
                OBS: O Split atualiza o pai automaticamente e logo
                após a chamada recursiva todos os nós anteriores
                ao filho são verificados e sofrem Split se for necessário
            */
            return Split(aux[count-1], p[count-1]);
        else // overflow na raiz
        {
            new_root = BTree_Node_Create();
            new_root->is_leaf = 0;
            new_root->child[0] = tree;
            Split(new_root, 0);
            return new_root;
        }
    }

    return tree;
}

// função para a altura da arvore b
int BTree_Height(BTree_Node *tree)
{
    int height = 0;

    while(!tree->is_leaf)
    {
        tree = tree->child[0];
        height++;
    }

    return height;
}

// funcao para contar a quantidade de paginas da arvoreB
void BTree_PagesC(BTree_Node *tree, int *count)
{
    int i;

    if(tree != NULL)
    {
        for(i = 0; i <= tree->n_key; i++)
        {
            BTree_PagesC(tree->child[i], count);
            if(tree->child[i] != NULL)
                *count += 1;
        }
    }
}

// função para imprimir a árvoreB
void BTree_Print(BTree_Node *tree)
{
    int i;

    if(tree != NULL)
    {
        for(i = 0; i < tree->n_key; i++)
        {
            BTree_Print(tree->child[i]);
            if(tree->is_leaf)
                printf("->%d ",tree->key[i]);
            else
                printf("%d ",tree->key[i]);
        }
    }
    else
        return;
    BTree_Print(tree->child[i]);
}

int Leaf_Add = 0; 
int Leaf_Count = 0;
// funcao auxiliar para calcular a media entre os elementos dos nos folha
void BTree_Media(BTree_Node *tree)
{
    int i;

    if(tree != NULL)
    {
        for(i = 0; i < tree->n_key; i++)
        {
            BTree_Media(tree->child[i]);
            if(tree->is_leaf)
            {
                Leaf_Add += tree->key[i];
                Leaf_Count++;
            }
        }
    }
    else
        return;

    BTree_Media(tree->child[i]);
}

int main()
{
    BTree_Node *tree = BTree_Node_Create();
    int count = 0; // auxiliar para o contador de paginas
    int media;

    tree = BTree_Insert(tree, 20, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 10, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 15, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 30, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 40, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 50, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 60, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 70, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 80, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 90, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 100, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 110, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 120, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 130, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 140, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 150, -1);
    Initialize_GlobalVals();
    tree = BTree_Insert(tree, 160, -1);

    BTree_Print(tree);
    printf("\n");
    BTree_PagesC(tree, &count);
    printf("Pages: %d\n",count+1);
    printf("Height: %d\n",BTree_Height(tree));
    BTree_Media(tree);

    if(Leaf_Count > 0)
        media = Leaf_Add/Leaf_Count;
    
    printf("Leaf Nodes Average: %d",media);

    return 0;
}