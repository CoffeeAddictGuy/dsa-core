#pragma once
#include "../../../data_structures/graph/graph.h"

typedef struct {
  bool found;
  size_t path[100];
  size_t path_length;
} DFSResult;

typedef struct {
  size_t parent[100];
  bool visited[100];
} DFSState;

DFSResult dfs(Graph *g, size_t source, size_t destination);
DFSResult *dfs_recurcive(Graph *g, size_t v, DFSState *state, DFSResult *result,
                         size_t end);