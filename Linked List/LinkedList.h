typedef struct LLNode LLNode;
typedef struct LinkedList Llist;

LLNode* LLNode_create(int key); // funcao para criar um noh da lista
int LLNode_key(LLNode *Node); // retorna a key do noh
Llist* Llist_create(); // funcao para criar a lista
LLNode* Llist_insert(Llist *list, int new_key); // funcao pra inserir na lista
LLNode* Llist_insertend(Llist *list, LLNode *end, int key); // funcao para inserir no final da lista
LLNode* Llist_delete(Llist *list, int key); // funcao para deletar na lista
LLNode* Llist_deletehead(Llist *list); // funcao para remover a head da lista
void Llist_print(Llist *list); // funcao para printar a lista
int Llist_isempty(Llist *list); // funcao para verificar se a lista estah vazia
