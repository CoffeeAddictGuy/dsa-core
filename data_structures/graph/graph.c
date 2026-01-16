#include "graph.h"

Graph *graph_create(size_t num_vertices) {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->num_vertices = num_vertices;
  g->adjacency = ht_init(num_vertices * 2, HT_MODE_MULTIMAP);
  return g;
}

void graph_add_edge(Graph *g, size_t from, size_t to) {
  char c_from[32];
  snprintf(c_from, sizeof(c_from), "%lld", from);
  ht_insert(g->adjacency, c_from, to);
}

size_t graph_get_neighbors(Graph *g, size_t vertex, size_t *neighbors,
                           size_t max_neighbors) {
  char c_vertex[32];
  snprintf(c_vertex, sizeof(c_vertex), "%lld", vertex);

  unsigned int vertex_idx = hash_func(c_vertex, g->adjacency->capacity);
  HashNode *curr = g->adjacency->buckets[vertex_idx];
  size_t n_cnt = 0;
  while (curr != NULL && n_cnt < max_neighbors) {
    if (strcmp(curr->key, c_vertex) == 0) {
      neighbors[n_cnt] = curr->value;
      n_cnt++;
    }
    curr = curr->next;
  }
  return n_cnt;
}

void graph_print(Graph *g) {
  for (size_t i = 0; i < g->adjacency->capacity; i++) {
    HashNode *curr = g->adjacency->buckets[i];
    while (curr != NULL) {
      printf("Bucket %lld: From %s to %d\n", i, curr->key, curr->value);
      curr = curr->next;
    }
  }
  printf("---\n");
}

void graph_free(Graph *g) {
  ht_free(g->adjacency);
  free(g);
}