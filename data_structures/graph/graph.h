#pragma once
#include "../hash_table_chain/ht_chaining.h"
#include <stdbool.h>

typedef struct {
  HashTable *adjacency;
  size_t num_vertices;
} Graph;

Graph *graph_create(size_t num_vertices);
void graph_add_edge(Graph *g, size_t from, size_t to);
size_t graph_get_neighbors(Graph *g, size_t vertex, size_t *neighbors,
                           size_t max_neighbors);
void graph_print(Graph *g);
void graph_free(Graph *g);