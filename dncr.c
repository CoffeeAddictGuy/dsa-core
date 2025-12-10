#include "dncr.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DynamicArray *da_init(size_t initial_capacity) {
  DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));

  if (!array) {
    printf("Dynamic array can't malloc");
    return NULL;
  }

  array->value = malloc(sizeof(int) * initial_capacity);
  if (!array->value) {
    printf(stderr, "Array in DA can't malloc");
    free(array);
    return NULL;
  }

  array->size = 0;
  array->capacity = initial_capacity;
  return array;
}

void da_push(DynamicArray *array, int value) {
  size_t tSize = array->size;
  if (array->size < array->capacity) {
    array->value[array->size] = value;
    array->size = tSize + 1;
  } else {
    int *tArray = array->value;
    tArray = realloc(tArray, (array->capacity * 2) * sizeof(int));

    if (tArray != NULL) {
      array->value = tArray;
      array->value[array->size] = value;
      array->size = tSize + 1;
      array->capacity = array->capacity * 2;
    } else {
      int *nArray = (int *)malloc(sizeof(int) * (array->capacity * 2));
      memcpy(nArray, array->value, array->capacity);
      free(array->value);
      array->value = nArray;
      array->size = tSize + 1;
      array->capacity = array->capacity * 2;
    }
  }
}

void da_pop(DynamicArray *array) {
  if (array->size <= 0)
    return;
  size_t tSize = array->size;
  array->size = tSize - 1;
}

size_t da_get(DynamicArray *array, size_t index) {
  if (index <= array->size) {
    return array->value[index];
  }
  return NULL;
}

void da_set(DynamicArray *array, size_t index, int value) {
  if (index > array->size || index > array->capacity)
    return;
  array->value[index] = value;
}

void da_remove(DynamicArray *array, size_t index) {
  if (index > array->size)
    return;
  if (index == array->size) {
    da_pop(array);
  } else {
    memcpy(&array->value[index], &array->value[index + 1],
           sizeof(int) * (array->size - index));
    array->size -= 1;
  }
}

void da_free(DynamicArray *array) {
  free(array->value);
  free(array);
};