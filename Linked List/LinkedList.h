typedef struct LL_Node LL_Node;
typedef struct LinkedList Llist;

LL_Node* LL_Node_create(int key);
Llist* Llist_create();
Llist* Llist_insert(Llist *list, int new_key);
void Llist_delete(Llist *list, int key);
void Llist_print(Llist *list);