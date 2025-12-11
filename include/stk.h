#include "dncr.h"
#include <stdbool.h>

typedef struct {
  DynamicArray *dastack;
} Stack;

Stack *stk_init(size_t capacity);
void stk_push(Stack *stack, int value);
Result stk_pop(Stack *stack);
Result stk_top(Stack *stack);
Result stk_get_at(Stack *stack, size_t index);
bool stk_empty(Stack *stack);
size_t stk_size(Stack *stack);
void stk_free(Stack *stack);