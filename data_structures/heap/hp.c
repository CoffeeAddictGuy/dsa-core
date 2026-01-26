#include "hp.h"

MinHeap *heap_init(size_t capacity) {
  MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
  if (heap == NULL) {
    return NULL;
  }
  int *data = (int *)malloc(sizeof(int) * capacity);
  if (data == NULL) {
    printf("Space cannot be allocated!");
    return NULL;
  }
  heap->data = data;
  heap->size = 0;
  heap->capacity = capacity;
  return heap;
}

void heap_insert(MinHeap *heap, int value) {
  if (heap == NULL) {
    return;
  }
  if (heap->size + 1 >= heap->capacity) {
    int *t = realloc(heap->data, sizeof(int) * (heap->capacity * 2));
    if (t == NULL) {
      return;
    }
    heap->data = t;
    heap->capacity = heap->capacity * 2;
  } else {
    heap->data[heap->size++] = value;
  }
  heapify_up(heap, heap->size - 1);
}

int heap_extract_min(MinHeap *heap) {
  int t = heap->data[0];
  int last = heap->data[heap->size - 1];
  heap->data[0] = last;
  heap->size = heap->size - 1;
  heapify_down(heap, 0);
  return t;
}

void heapify_up(MinHeap *heap, size_t index) {
  if (index == 0) {
    return;
  }

  size_t p_index = (index - 1) / 2;
  if (heap->data[p_index] > heap->data[index]) {
    int t = heap->data[p_index];
    heap->data[p_index] = heap->data[index];
    heap->data[index] = t;
    heapify_up(heap, p_index);
  }
}

void heapify_down(MinHeap *heap, size_t index) {
  size_t p = index;
  size_t l_c = (2 * index) + 1;
  size_t r_c = (2 * index) + 2;
  if (l_c >= heap->size) {
    return;
  }

  if (r_c < heap->size) {
    if (heap->data[p] < heap->data[l_c] && heap->data[p] < heap->data[r_c]) {
      return;
    }
  } else {
    if (heap->data[p] < heap->data[l_c]) {
      return;
    }
  }

  size_t lowest = 0;
  if (r_c < heap->size) { // two child
    lowest = (heap->data[l_c] > heap->data[r_c]) ? r_c : l_c;
  } else { // one child
    if (l_c < heap->size) {
      lowest = l_c;
    } else {
      lowest = r_c;
    }
  }
  int t = heap->data[p];
  heap->data[p] = heap->data[lowest];
  heap->data[lowest] = t;
  heapify_down(heap, lowest);
}

void heap_print(MinHeap *heap) {
  // printf("Index : Value\n");
  for (size_t i = 0; i < heap->size; i++) {
    printf("%d ", heap->data[i]);
  }
  printf("\n");
}

void heap_free(MinHeap *heap) {
  free(heap->data);
  free(heap);
}
