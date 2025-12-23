#include "quick_sort.h"

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void quick_sort(int *array, size_t size) { quicksort(array, 0, size - 1); }

void quicksort(int *array, size_t left, size_t right) {
  if (left >= right) {
    return;
  }

  size_t pivot_idx = hoare_partition(array, left, right);
  if (pivot_idx > left) {
    quicksort(array, left, pivot_idx);
  }
  quicksort(array, pivot_idx + 1, right);
}

size_t lomuto_partition(int *array, size_t left, size_t right) {
  size_t pivot = right;
  size_t border = left;
  for (size_t j = left; j < right; j++) {
    if (array[j] < array[pivot]) {
      swap(&array[border], &array[j]);
      border++;
    }
  }
  swap(&array[border], &array[pivot]);
  return border;
}

size_t hoare_partition(int *array, size_t left, size_t right) {
  size_t pivot = left;
  size_t l = left;
  size_t r = right;

  while (true) {
    while (array[l] < array[pivot]) {
      l++;
    }
    while (array[r] > array[pivot]) {
      r--;
    }
    if (l >= r) {
      return r;
    }
    swap(&array[l++], &array[r--]);
  }
  return r;
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