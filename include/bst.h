
typedef struct BinarySearchTree {
  int value;
  struct BinarySearchTree *left;
  struct BinarySearchTree *right;
} BST;

BST *bst_init(int value);
BST *bst_insert(BST *bst, int value);
BST *bst_search(BST *bst, int value);
BST *bst_search_parent(BST *bst, int value);
BST *bst_delete(BST *bst, int value); // todo

void bst_inorder(BST *bst);
void bst_preorder(BST *bst);
void bst_postorder(BST *bst);

int bst_height(BST *bst);
BST *bst_min(BST *bst);
BST *bst_max(BST *bst);

void bst_free(BST *bst);