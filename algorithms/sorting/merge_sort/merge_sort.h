#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void merge_sort(int *array, size_t size);
void merge_recursion(int *array, size_t left, size_t right);
void merge(int *array, size_t left, size_t mid, size_t right);
void array_print(int *array, size_t size);
bool is_sorted(int *array, size_t size);