#include "bst.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

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
  BST *p = bst_search_parent(bst, value);
  BST *srch = (value > p->value) ? p->right : p->left;

  if (p == bst) { // root
    if (p->right == NULL && p->left == NULL) {
      return NULL;
    } else if (p->left == NULL || p->right == NULL) {
      if (p->left != NULL) {
        p->value = p->left->value;
        p->left = p->left->left;
        p->right = p->left->right;
      } else {
        p->value = p->right->value;
        p->left = p->right->left;
        p->right = p->right->right;
      }
    } else if (p->left != NULL && p->right != NULL) {
      BST *rplc = bst_min(p->right);
      p->value = rplc->value;
      bst_delete(p->right, rplc->value);
    }
  } else if (srch->left == NULL && srch->right == NULL) { // no child
    if (p->left == srch) {
      p->left = NULL;
    }
    if (p->right == srch) {
      p->right = NULL;
    }
  } else if (srch->left == NULL || srch->right == NULL) { // one child
    if (srch->left == NULL) {
      if (p->left == srch) {
        p->left = srch->right;
      } else {
        p->right = srch->right;
      }
    } else {
      if (p->left == srch) {
        p->left = srch->left;
      } else {
        p->right = srch->left;
      }
    }
  } else if (srch->left != NULL && srch->right != NULL) { // two child
    BST *rplc = bst_min(srch->right);
    srch->value = rplc->value;
    bst_delete(srch->right, rplc->value);
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