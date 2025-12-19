#include "ht_oa.h"

unsigned int hash_func(const char *key, size_t table_size) {
  unsigned long hash = 5381;
  int i = 0;
  while (key[i] != '\0') {
    hash = (hash << 5) + hash + key[i];
    i++;
  }
  return hash % table_size;
}

HashTable *ht_init(size_t capacity) {
  HashTable *n_ht = (HashTable *)malloc(sizeof(HashTable));
  if (n_ht == NULL) {
    return NULL;
  }

  HashItem *n_hi = (HashItem *)calloc(capacity, sizeof(HashItem));
  if (n_hi == NULL) {
    free(n_ht);
    return NULL;
  }

  n_ht->capacity = capacity;
  n_ht->size = 0;
  n_ht->items = n_hi;

  return n_ht;
}

HashTable *ht_insert(HashTable *ht, char *key, int value) {
  if (ht == NULL) {
    return NULL;
  }

  if (ht->size >= ht->capacity * 0.7) {
    HashTable *temp = ht_resize(ht);
    if (temp == NULL) {
      return NULL;
    }
    *ht = *temp;
  }

  unsigned int index = hash_func(key, ht->capacity);
  HashItem *items = ht->items;
  // is not empty
  if (items[index].state == EMPTY || items[index].state == DELETE) {
    items[index].key = key;
    items[index].value = value;
    items[index].state = OCCUPIED;
    ht->size += 1;
    return ht;
  }
  if (items[index].state == OCCUPIED) {
    unsigned int start = index;
    index = (index + 1) % ht->capacity;
    while (index != start) {
      if (items[index].state == EMPTY || items[index].state == DELETE) {
        items[index].key = key;
        items[index].value = value;
        items[index].state = OCCUPIED;
        ht->size += 1;
        return ht;
      } else if (strcmp(items[index].key, key) == 0) {
        items[index].value = value;
        return ht;
      }

      index = (index + 1) % ht->capacity;
    }
  }
  return ht;
}

HashItem *ht_search(HashTable *ht, char *key, int value) {
  int index = hash_func(key, ht->capacity);
  HashItem *item = ht->items;
  if (item[index].state == EMPTY || item[index].state == DELETE) {
    return NULL;
  }
  if (strcmp(item[index].key, key) == 0 && item[index].value == value) {
    return &ht->items[index];
  } else {
    int start = index;
    index = (index + 1) % ht->capacity;
    while (index != start) {
      if (item[index].state == EMPTY) {
        return NULL;
      }
      if (item[index].state == OCCUPIED) {
        if (strcmp(item[index].key, key) == 0 && item[index].value == value) {
          return &ht->items[index];
        }
      }
      index = (index + 1) % ht->capacity;
    }
  }
  return NULL;
}

void ht_delete(HashTable *ht, char *key, int value) {
  HashItem *to_delete = ht_search(ht, key, value);
  if (to_delete != NULL) {
    to_delete->state = DELETE;
    ht->size -= 1;
  }
}

HashTable *ht_resize(HashTable *ht) {
  HashTable *new_table = malloc(sizeof(HashTable));
  if (new_table == NULL) {
    return NULL;
  }
  HashItem *new_items = calloc(ht->capacity * 2, sizeof(HashItem));
  if (new_items == NULL) {
    return NULL;
  }

  new_table->capacity = ht->capacity * 2;
  new_table->size = 0;
  new_table->items = new_items;

  for (size_t i = 0; i < ht->capacity; i++) {
    if (ht->items[i].state == OCCUPIED) {
      ht_insert(new_table, ht->items[i].key, ht->items[i].value);
    }
  }
  free(ht->items);
  ht->items = new_items;
  ht->capacity = new_table->capacity;
  ht->size = new_table->size;

  free(new_table);
  return ht;
}

void ht_free(HashTable *ht) {
  free(ht->items);
  free(ht);
}