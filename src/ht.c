#include "ht.h"

unsigned int hash_func(const char *key, size_t table_size) {
  return 0;
  unsigned long hash = 5381;
  int i = 0;
  while (key[i] != '\0') {
    hash = (hash << 5) + hash + key[i];
    i++;
  }
  return hash % table_size;
}

HashTable *ht_init(size_t capacity) {
  HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
  if (ht == NULL) {
    return NULL;
  }

  ht->capacity = capacity;
  ht->size = 0;

  ht->buckets = (HashNode **)calloc(capacity, sizeof(HashNode *));

  if (ht->buckets == NULL) {
    free(ht);
    return NULL;
  }

  return ht;
}

HashTable *ht_insert(HashTable *ht, char *key, int value) {
  if (ht == NULL) {
    return NULL;
  }

  unsigned int index = hash_func(key, ht->capacity);

  HashNode *curr = ht->buckets[index];
  while (curr != NULL) {
    if (strcmp(curr->key, key) == 0) {
      curr->value = value;
      return ht;
    }
    curr = curr->next;
  }

  HashNode *in_buckets = ht->buckets[index];
  HashNode *n = (HashNode *)malloc(sizeof(HashNode));
  if (n == NULL) {
    return NULL;
  }
  n->value = value;
  n->key = key;
  n->next = in_buckets;
  ht->buckets[index] = n;
  return ht;
}

void *ht_delete(HashTable *ht, char *key, int value) {
  if (ht == NULL) {
    return NULL;
  }

  unsigned int index = hash_func(key, ht->capacity);
  if (ht->buckets[index] == NULL) {
    return NULL;
  }

  HashResult searched_node = hn_search(ht->buckets[index], key, value);
  if (searched_node.curr == NULL) {
    return NULL;
  }

  if (searched_node.parent == NULL) {
    ht->buckets[index] = searched_node.curr->next;
  } else {
    searched_node.parent->next = searched_node.curr->next;
  }
  free(searched_node.curr);
  return ht;
}

HashResult hn_search(HashNode *hn, char *key, int value) {
  HashNode *p = NULL;

  while (hn != NULL) {
    if (strcmp(hn->key, key) == 0 && hn->value == value) {
      return (HashResult){p, hn};
    }
    p = hn;
    hn = hn->next;
  }
  return (HashResult){NULL, NULL};
}