#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { HT_MODE_MAP, HT_MODE_MULTIMAP } HTMode;

typedef struct HashNode {
  char *key;
  int value;
  struct HashNode *next;
} HashNode;

typedef struct HashResult {
  struct HashNode *parent;
  struct HashNode *curr;
} HashResult;

typedef struct {
  HashNode **buckets;
  size_t capacity;
  size_t size;
  HTMode mode;
} HashTable;

unsigned int hash_func(const char *key, size_t table_size);

HashTable *ht_init(size_t capacity, HTMode mode);
HashTable *ht_insert(HashTable *ht, char *key, int value);
void *ht_delete(HashTable *ht, char *key, int value);

HashResult hn_search(HashNode *hn, char *key, int value);

void ht_free(HashTable *ht);

char *str_dublicator(char *src);
