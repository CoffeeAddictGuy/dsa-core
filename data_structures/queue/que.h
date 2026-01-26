#pragma once
#include <stdlib.h>

typedef struct {
  int *data;
  size_t readptr;
  size_t writeptr;
  size_t capacity;
  size_t size;
} Queue;

typedef struct {
  int code;
  int result;
} Result;

Queue *q_init(size_t capacity);
void q_write(Queue *queue, int value);
Result q_read(Queue *queue);
Result q_size(Queue *queue);
void q_free(Queue *queue);