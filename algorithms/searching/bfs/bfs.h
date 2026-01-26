#pragma once
#include "../../../data_structures/graph/graph.h"
#include "../../../data_structures/queue/que.h"

typedef struct {
  bool found;
  size_t path[100];
  size_t path_length;
} BFSResult;

typedef struct {
  size_t parent[100];
  bool visited[100];
} BFSState;

BFSResult bfs(Graph *g, size_t source, size_t destination);