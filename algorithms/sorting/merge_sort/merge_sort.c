#include "merge_sort.h"

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void merge_sort(int *array, size_t size) {
  if (size == 0) {
    return;
  }
  merge_recursion(array, 0, size - 1);
}

void merge_recursion(int *array, size_t left, size_t right) {
  if (left >= right) {
    return;
  }
  size_t mid = left + (right - left) / 2;
  merge_recursion(array, left, mid);
  merge_recursion(array, mid + 1, right);
  merge(array, left, mid, right);
}

void merge(int *array, size_t left, size_t mid, size_t right) {
  size_t l_curr = left;
  size_t r_curr = mid + 1;
  int *temp = (int *)malloc(sizeof(int) * (right - left));

  for (size_t i = left; i <= right; i++) {
    size_t temp_idx = i - left;
    if (l_curr <= mid && r_curr <= right) {
      if (array[l_curr] > array[r_curr]) {
        temp[temp_idx] = array[r_curr];
        r_curr++;
      } else {
        temp[temp_idx] = array[l_curr];
        l_curr++;
      }
    } else if (l_curr <= mid) {
      temp[temp_idx] = array[l_curr];
      l_curr++;
    } else {
      temp[temp_idx] = array[r_curr];
      r_curr++;
    }
  }
  memcpy(array + left, temp, (right - left + 1) * sizeof(int));
  free(temp);
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