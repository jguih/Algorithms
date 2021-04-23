typedef struct LL_Node LL_Node;
typedef struct LinkedList Llist;

LL_Node* LL_Node_create(int key); // funcao para criar um noh da lista
int LL_Node_key(LL_Node *Node); // retorna a key do noh
Llist* Llist_create(); // funcao para criar a lista
LL_Node* Llist_insert(Llist *list, int new_key); // funcao pra inserir na lista
LL_Node* Llist_delete(Llist *list, int key); // funcao para deletar na lista
void Llist_print(Llist *list); // funcao para printar a lista
int Llist_isempty(Llist *list); // funcao para verificar se a lista estah vazia
LL_Node* Llist_deletehead(Llist *list); // funcao para remover a head da lista