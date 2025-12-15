#include "bst.h"

BST *bst_init(int value) {
  BST *bst = (BST *)malloc(sizeof(BST));
  if (bst == NULL) {
    return NULL;
  }
  bst->value = value;
  bst->left = NULL;
  bst->right = NULL;
  return bst;
}

BST *bst_insert(BST *bst, int value) {
  if (bst == NULL) {
    return bst_init(value);
  }
  if (value < bst->value) {
    bst->left = bst_insert(bst->left, value);
  } else if (value > bst->value) {
    bst->right = bst_insert(bst->right, value);
  }
  return bst;
}

BST *bst_search(BST *bst, int value) {
  if (bst == NULL) {
    return NULL;
  }
  if (value > bst->value) {
    return bst_search(bst->right, value);
  } else if (value < bst->value) {
    return bst_search(bst->left, value);
  } else {
    return bst;
  }
}

BST *bst_search_parent(BST *bst, int value) {
  if (bst->left == NULL && bst->right == NULL) {
    return NULL;
  }

  if (bst->left != NULL) {
    if (bst->left->value == value) {
      return bst;
    }
  }
  if (bst->right != NULL) {
    if (bst->right->value == value) {
      return bst;
    }
  }

  if (value > bst->value) {
    return bst_search_parent(bst->right, value);
  } else if (value < bst->value) {
    return bst_search_parent(bst->left, value);
  } else {
    return bst;
  }
}

BST *bst_delete(BST *bst, int value) {
  if (bst == NULL) {
    return NULL;
  }
  BST *srch_node = bst_search(bst, value);
  BST *prnt_node = bst_search_parent(bst, srch_node->value);
  // root
  if (prnt_node == srch_node) {
    if (srch_node->left == NULL && srch_node->right == NULL) { // no child
      bst_free(bst);
    } else if (srch_node->left == NULL ||
               srch_node->right == NULL) { // one child
      if (srch_node->left != NULL) {
        prnt_node->value = prnt_node->left->value;
        prnt_node->left = prnt_node->left->left;
        prnt_node->right = prnt_node->right->right;
      } else if (srch_node->right != NULL) {
        prnt_node->value = prnt_node->right->value;
        prnt_node->left = prnt_node->right->left;
        prnt_node->right = prnt_node->right->right;
      }
    } else if (srch_node->left != NULL &&
               srch_node->right != NULL) { // two child
      BST *rmin = bst_min(srch_node->right);
      prnt_node->value = rmin->value;
      bst_delete(srch_node->right, rmin->value);
    }
  }
  //  nodes
  else if (prnt_node != srch_node) {
    if (srch_node->left == NULL && srch_node->right == NULL) { // no child
      if (srch_node->value > prnt_node->value) {
        prnt_node->right = NULL;
      } else if (srch_node->value < prnt_node->value) {
        prnt_node->left = NULL;
      }
    } else if (srch_node->left == NULL ||
               srch_node->right == NULL) { // one child
      if (srch_node->left != NULL) {
        if (srch_node->left->value > prnt_node->value) {
          prnt_node->right = srch_node->left;
        } else if (srch_node->left->value < prnt_node->value) {
          prnt_node->left = srch_node->left;
        }
      } else if (srch_node->right != NULL) {
        if (srch_node->right->value > prnt_node->value) {
          prnt_node->right = srch_node->right;
        } else if (srch_node->right->value < prnt_node->value) {
          prnt_node->left = srch_node->right;
        }
      }
    } else if (srch_node->left != NULL &&
               srch_node->right != NULL) { // two child
      BST *rmin = bst_min(srch_node->right);
      srch_node->value = rmin->value;
      bst_delete(srch_node->right, rmin->value);
    }
  }
  return bst;
}

int bst_height(BST *bst) {
  if (bst == NULL) {
    return 0;
  }
  int left_height = bst_height(bst->left);
  int right_height = bst_height(bst->right);

  return 1 + (left_height > right_height ? left_height : right_height);
}

size_t bst_count_nodes(BST *bst) {
  if (bst == NULL) {
    return 0;
  }

  size_t left = bst_count_nodes(bst->left);
  size_t right = bst_count_nodes(bst->right);

  return left + right + 1;
}

size_t bst_sum(BST *bst) {
  if (bst == NULL) {
    return 0;
  }

  size_t left = bst_sum(bst->left);
  size_t right = bst_sum(bst->right);
  size_t res = bst->value;

  return res + left + right;
}

BST *bst_min(BST *bst) {
  if (bst->left == NULL) {
    return bst;
  }
  return bst_min(bst->left);
}

BST *bst_max(BST *bst) {
  if (bst->right == NULL) {
    return bst;
  }
  return bst_max(bst->right);
}

void bst_inorder(BST *bst) {
  if (bst != NULL) {
    bst_inorder(bst->left);
    printf("%d\n", bst->value);
    bst_inorder(bst->right);
  }
}

void bst_preorder(BST *bst) {
  if (bst != NULL) {
    printf("%d\n", bst->value);
    bst_preorder(bst->left);
    bst_preorder(bst->right);
  }
}

void bst_postorder(BST *bst) {
  if (bst != NULL) {
    bst_postorder(bst->left);
    bst_postorder(bst->right);
    printf("%d\n", bst->value);
  }
}

void bst_free(BST *bst) { free(bst); }