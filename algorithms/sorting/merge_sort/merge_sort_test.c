#include "merge_sort.h"

bool is_sorted(int *array, size_t size);

int main() {
  printf("=== Insertion Sort Tests ===\n\n");

  // First test: Unsorted array
  printf("Test 1: Unsorted [5,2,4,6,1,3]\n");
  int test1[] = {5, 2, 4, 6, 1, 3};
  size_t size1 = sizeof(test1) / sizeof(test1[0]);
  printf("Before: ");
  array_print(test1, size1);
  merge_sort(test1, size1);
  printf("After:  ");
  array_print(test1, size1);
  printf("Sorted: %s\n\n", is_sorted(test1, size1) ? "PASS" : "FAIL");

  // Second test: sorted array
  printf("Test 1: Sorted [1,2,3,4,5,6]\n");
  int test2[] = {1, 2, 3, 4, 5, 6};
  size_t size2 = sizeof(test2) / sizeof(test2[0]);
  printf("Before: ");
  array_print(test2, size2);
  merge_sort(test2, size2);
  printf("After:  ");
  array_print(test2, size2);
  printf("Sorted: %s\n\n", is_sorted(test2, size2) ? "PASS" : "FAIL");

  // Third test: reverse
  printf("Test 1: Reverse [6,5,4,3,2,1]\n");
  int test3[] = {6, 5, 4, 3, 2, 1};
  size_t size3 = sizeof(test3) / sizeof(test3[0]);
  printf("Before: ");
  array_print(test3, size3);
  merge_sort(test3, size3);
  printf("After:  ");
  array_print(test3, size3);
  printf("Sorted: %s\n\n", is_sorted(test3, size3) ? "PASS" : "FAIL");

  // Fourth test: one element
  printf("Test 1: One element [42]\n");
  int test4[] = {42};
  size_t size4 = sizeof(test4) / sizeof(test4[0]);
  printf("Before: ");
  array_print(test4, size4);
  merge_sort(test4, size4);
  printf("After:  ");
  array_print(test4, size4);
  printf("Sorted: %s\n\n", is_sorted(test4, size4) ? "PASS" : "FAIL");

  // Fifth test: doubles
  printf("Test 1: Doubles [3,1,3,2,3]\n");
  int test5[] = {3, 1, 3, 2, 3};
  size_t size5 = sizeof(test5) / sizeof(test5[0]);
  printf("Before: ");
  array_print(test5, size5);
  merge_sort(test5, size5);
  printf("After:  ");
  array_print(test5, size5);
  printf("Sorted: %s\n\n", is_sorted(test5, size5) ? "PASS" : "FAIL");

  return 0;
}