#include "que.h"

Queue *q_init(size_t capacity) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  if (q == NULL) {
    return NULL;
  }

  q->data = (int *)malloc(sizeof(int) * capacity);
  q->readptr = 0;
  q->writeptr = 0;
  q->size = 0;
  q->capacity = capacity;
  return q;
}

void q_write(Queue *queue, int value) {
  if ((queue->writeptr + 1) % queue->capacity == queue->readptr) {
    return;
  }
  queue->data[queue->writeptr] = value;
  queue->writeptr = (queue->writeptr + 1) % queue->capacity;
  if (queue->size < queue->capacity) {
    queue->size += 1;
  }
}

Result q_read(Queue *queue) {
  Result result;
  if (queue->readptr == queue->writeptr) {
    result = (Result){-1, 0};
    return result;
  }
  result = (Result){0, queue->data[queue->readptr]};
  queue->readptr = (queue->readptr + 1) % queue->capacity;
  queue->size -= 1;
  return result;
}

Result q_size(Queue *queue) {
  Result result;
  if (queue->size == 0) {
    result = (Result){-1, 0};
    return result;
  }
  result = (Result){0, queue->size};
  return result;
}

void q_free(Queue *queue) {
  free(queue->data);
  free(queue);
}