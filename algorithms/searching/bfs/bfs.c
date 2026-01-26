#include "bfs.h"

BFSResult bfs(Graph *g, size_t source, size_t destination) {
  BFSResult result = {false, NULL, NULL};
  if (g == NULL) {
    return result;
  }
  if (g->num_vertices > 100) {
    printf("Vertices more than 100!");
    return result;
  }

  Queue *q = q_init(g->num_vertices);
  if (q == NULL) {
    return result;
  }

  BFSState state = {0};
  state.visited[source] = true;
  state.parent[source] = -1;

  q_write(q, source);
  printf("BFS start searching path from %lld to %lld\n", source, destination);
  Result res = q_read(q);
  while (res.code != -1) {
    int curr = res.result;
    if (curr == destination) {
      printf("Path found!\n");
      result.found = true;
      size_t idx = 0;
      size_t path_curr = destination;
      while (path_curr != (size_t)-1) {
        result.path[idx++] = path_curr;
        path_curr = state.parent[path_curr];
      }
      result.path_length = idx;
      q_free(q);
      return result;
    }

    size_t neighborn[10];
    int neighborn_cnt = graph_get_neighbors(g, curr, neighborn, 10);

    for (int i = 0; i < neighborn_cnt; i++) {
      size_t next = neighborn[i];
      if (!state.visited[next]) {
        q_write(q, next);
        state.visited[next] = true;
        state.parent[next] = curr;
      }
    }
    res = q_read(q);
  }
  printf("No path found!\n");
  q_free(q);
  return result;
}