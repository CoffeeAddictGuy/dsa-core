#include "stk.h"

Stack *stk_init(size_t capacity) {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->dastack = da_init(capacity);
  return stack;
}

void stk_push(Stack *stack, int value) { da_push(stack->dastack, value); }

Result stk_pop(Stack *stack) {
  Result result;
  if (stack->dastack->size == 0) {
    result = (Result){-1, 0};
    return result;
  }
  int value = stack->dastack->value[stack->dastack->size - 1];
  da_pop(stack->dastack);
  result = (Result){0, value};
  return result;
}

Result stk_top(Stack *stack) {
  Result result;
  if (stack == NULL || stack->dastack->size == 0) {
    result = (Result){-1, 0};
    return result;
  }
  result = (Result){0, stack->dastack->value[stack->dastack->size - 1]};
  return result;
}

Result stk_get_at(Stack *stack, size_t index) {
  Result result;
  if (stack == NULL || stack->dastack->size == 0 || index >= stk_size(stack)) {
    result = (Result){-1, 0};
    return result;
  }
  result = (Result){0, stack->dastack->value[index]};
  return result;
}

bool stk_empty(Stack *stack) {
  if (stack->dastack == NULL || stack->dastack->size == 0 || stack == NULL)
    return true;
  return false;
}

size_t stk_size(Stack *stack) { return stack->dastack->size; }

void stk_free(Stack *stack) {
  da_free(stack->dastack);
  free(stack);
}
