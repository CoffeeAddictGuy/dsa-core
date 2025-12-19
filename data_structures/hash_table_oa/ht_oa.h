#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { EMPTY, OCCUPIED, DELETE } State;

typedef struct {
  char *key;
  int value;
  State state;
} HashItem;

typedef struct {
  HashItem *items;
  size_t capacity;
  size_t size;
} HashTable;

unsigned int hash_func(const char *key, size_t table_size);

HashTable *ht_init(size_t capacity);
HashTable *ht_insert(HashTable *ht, char *key, int value);
HashItem *ht_search(HashTable *ht, char *key, int value);
void ht_delete(HashTable *ht, char *key, int value);
HashTable *ht_resize(HashTable *ht);

void ht_free(HashTable *ht);