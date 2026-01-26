#include "dfs.h"

#define MAX_VERICES 10000

DFSResult dfs(Graph *g, size_t source, size_t destination) {
  DFSResult result = {false, NULL, NULL};
  if (g == NULL) {
    return result;
  }
  DFSState state = {0};
  return *dfs_recurcive(g, source, &state, &result, destination);
}

DFSResult *dfs_recurcive(Graph *g, size_t v, DFSState *state, DFSResult *result,
                         size_t end) {
  size_t neighborns[10];
  size_t n_cnt = graph_get_neighbors(g, v, neighborns, 10);
  if (v == end) {
    result->found = true;

    return result;
  }

  for (size_t i = 0; i < n_cnt; i++) {
    size_t next = neighborns[i];
    if (!state->visited[next]) {
      state->visited[next] = true;
      state->parent[next] = v;
      dfs_recurcive(g, next, state, result, end);
      if (result->found) {
        return result;
      }
    }
  }
  if (!result->found) {
    return result;
  }
}