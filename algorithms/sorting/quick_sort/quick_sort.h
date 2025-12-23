#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void quick_sort(int *array, size_t size);
void quicksort(int *array, size_t left, size_t right);
size_t lomuto_partition(int *array, size_t left, size_t right);
size_t hoare_partition(int *array, size_t left, size_t right);
void array_print(int *array, size_t size);
bool is_sorted(int *array, size_t size);