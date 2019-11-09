
typedef int Type;

typedef struct NodeStruct
{
    Type key;
    struct NodeStruct *left;
    struct NodeStruct *right;

    int offset;
    int location;
} Node;

void TreePrint(Node *root);
void TreeFree(Node *root);
Node *TreeFind(Node *root, Type key);
Node *TreeFindMin(Node *root);
Node *TreeFindMax(Node *root);
Node *TreeInsert(Node *root, Type key);
Node *TreeDel(Node *root, Type key);
