#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedList {
  struct LinkedList *nextAddr;
  int key;
} LL;

LL *listInit(int key) {
  LL *newListElement = (struct LinkedList *)malloc(sizeof(LL));
  newListElement->key = key;
  newListElement->nextAddr = NULL;
  return newListElement;
}

LL *listAhead(LL *list, LL *value) {
  if (list == NULL || list->nextAddr == NULL)
    return NULL;
  if (list->nextAddr->key == value->key)
    return list;
  else
    return listAhead(list->nextAddr, value);
}

LL *listAdd(LL *list, int x) {
  if (list == NULL)
    return listInit(x);
  if (list->nextAddr != NULL)
    listAdd(list->nextAddr, x);
  else {
    LL *newList = listInit(x);
    list->nextAddr = newList;
  }
  return list;
}

void listAddAfter(LL **list, LL *target, LL *value) {
  if (list == NULL)
    return;

  LL *newList = listInit(value->key);
  if (target->nextAddr != NULL)
    newList->nextAddr = target->nextAddr;

  target->nextAddr = newList;
}

void listAddBefore(LL **list, LL *target, LL *value) {
  LL *p;
  LL *pred;

  p = *list;
  pred = listAhead(*list, target);

  if (pred == NULL) {
    value->nextAddr = *list;
    *list = value;
  } else {
    value->nextAddr = pred->nextAddr;
    pred->nextAddr = value;
  }
}

void listPrint(LL *list) {
  if (list != NULL && list->nextAddr != NULL) {
    printf("%d - ", list->key);
    return listPrint(list->nextAddr);
  } else {
    printf("%d\n", list->key);
  }
}

LL *listSearch(LL *list, LL *value) {
  if (list == NULL)
    return NULL;
  if (list->key == value->key)
    return list;
  else
    return listSearch(list->nextAddr, value);
}

int listLenght(LL *list) {
  if (list == NULL)
    return 0;
  int k = 0;
  while (list != NULL) {
    k++;
    list = list->nextAddr;
  }
  return k;
}

void listDelElement(LL **list, LL *value) {
  LL *p;
  LL *pred;
  LL *curr;

  p = *list;
  pred = listAhead(*list, value);
  curr = listSearch(*list, value);

  if (pred == NULL)
    *list = p->nextAddr;
  else
    pred->nextAddr = curr->nextAddr;

  free(curr);
}
