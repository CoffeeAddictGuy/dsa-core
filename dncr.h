#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int *value;
  size_t size;
  size_t capacity;
} DynamicArray;

DynamicArray *da_init(size_t capacity);
void da_push(DynamicArray *array, int value);
void da_pop(DynamicArray *array);
void da_free(DynamicArray *array);

// TODO
size_t da_get(DynamicArray *array, size_t index);
void da_set(DynamicArray *array, size_t index, int value);
void da_insert(DynamicArray *array, size_t index, int value);
void da_remove(DynamicArray *array, size_t index);

void da_clear(DynamicArray *array);
void da_shrink(DynamicArray *array);
void da_resize(DynamicArray *array, size_t new_capacity);

#endif