#include "heap_sort.h"

void heap_sort(int *array, size_t size) {
  MinHeap *heap = heap_init(size);
  memcpy(heap->data, array, sizeof(int) * size);
  heap->size = size;
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify_down(heap, i);
  }
  heap_print(heap);
  for (size_t i = 0; i < size; i++) {
    array[i] = heap_extract_min(heap);
  }
}

void array_print(int *array, size_t size) {
  printf("[");
  for (size_t i = 0; i < size; i++) {
    if (i != size - 1) {
      printf("%d -> ", array[i]);
    } else {
      printf("%d]\n", array[i]);
    }
  }
}

bool is_sorted(int *array, size_t size) {
  for (size_t i = 1; i < size; i++) {
    if (array[i] < array[i - 1]) {
      return false;
    }
  }
  return true;
}
