#include "dncr.h"

DynamicArray *da_init(size_t initial_capacity) {
  DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));

  if (!array) {
    printf("Dynamic array can't malloc");
    return NULL;
  }

  array->value = malloc(sizeof(int) * initial_capacity);
  if (!array->value) {
    printf("Array in DA can't malloc");
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

Result da_get(DynamicArray *array, size_t index) {
  Result result;
  if (index < array->size) {
    result = (Result){0, array->value[index]};
    return result;
  }
  result = (Result){-1, 0};
  return result;
}

void da_set(DynamicArray *array, size_t index, int value) {
  if (index >= array->size)
    return;
  array->value[index] = value;
}

void da_insert(DynamicArray *array, size_t index, int value) {
  if (index >= array->size) {
    return;
  }
  if (index == array->size - 1) {
    da_push(array, value);
  } else {
    if (array->size + 1 < array->capacity) {
      memcpy(&array->value[index + 1], &array->value[index],
             sizeof(int) * (array->size - index));
      array->value[index] = value;
      array->size += 1;
    } else if (array->size + 1 > array->capacity) {
      int *tArray = array->value;
      tArray = realloc(tArray, (array->capacity * 2) * sizeof(int));
      if (tArray != NULL) {
        memcpy(&array->value[index + 1], &array->value[index],
               sizeof(int) * (array->size - index));
        array->value[index] = value;
        array->size += 1;
        array->capacity = array->capacity * 2;
      } else {
        int *nArray = (int *)malloc(sizeof(int) * (array->capacity * 2));
        memcpy(nArray, array->value, array->size);
        free(array->value);
        array->value = nArray;
        memcpy(&array->value[index + 1], &array->value[index],
               sizeof(int) * (array->size - index));
        array->value[index] = value;
        array->size += 1;
        array->capacity = array->capacity * 2;
      }
    }
  }
}

void da_remove(DynamicArray *array, size_t index) {
  if (index >= array->size)
    return;
  if (index == array->size - 1) {
    da_pop(array);
  } else {
    memcpy(&array->value[index], &array->value[index + 1],
           sizeof(int) * (array->size - index));
    array->size -= 1;
  }
}

void da_clear(DynamicArray *array) { array->size = 0; }

void da_shrink(DynamicArray *array) {
  if (array->capacity > array->size) {
    int *tArray = array->value;
    tArray = realloc(tArray, sizeof(int) * array->size);
    if (tArray != NULL) {
      array->value = tArray;
      array->capacity = array->size;
    } else {
      int *nArray = (int *)malloc(sizeof(int) * array->size);
      memcpy(nArray, array->value, array->size);
      free(array->value);
      array->value = nArray;
      array->capacity = array->size;
    }
  } else {
    return;
  }
}

void da_resize(DynamicArray *array, size_t new_capacity) {
  if (new_capacity > array->capacity || new_capacity >= array->size) {
    int *tArray = array->value;
    tArray = realloc(tArray, sizeof(int) * new_capacity);
    if (tArray != NULL) {
      array->value = tArray;
      array->capacity = new_capacity;
    } else {
      int *nArray = (int *)malloc(sizeof(int) * new_capacity);
      memcpy(nArray, array->value, array->capacity);
      free(array->value);
      array->value = nArray;
      array->capacity = new_capacity;
    }
  } else {
    return;
  }
}

void da_free(DynamicArray *array) {
  free(array->value);
  free(array);
};