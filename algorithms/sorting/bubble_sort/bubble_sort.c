#include "bubble_sort.h"

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void bubble_sort(int *array, size_t size) {
  int swapped = 1;
  size_t limit = size;
  while (swapped) {
    swapped = 0;
    for (size_t i = 1; i < limit; i++) {
      if (array[i] < array[i - 1]) {
        swap(&array[i], &array[i - 1]);
        swapped = 1;
      }
    }
    limit--;
  }
}

void array_print(int *array, size_t size) {
  for (size_t i = 0; i < size; i++) {
    if (i != size - 1) {
      printf("%d -> ", array[i]);
    } else {
      printf("%d", array[i]);
    }
  }
}