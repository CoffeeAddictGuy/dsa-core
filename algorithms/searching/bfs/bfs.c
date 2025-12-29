#include "bfs.h"

BFSResult bfs(Graph *g, size_t source, size_t destination) {
  Queue *q = q_init(10);
  if (q == NULL) {
    return (BFSResult){.found = false};
  }

  BFSState state = {0};
  BFSResult result = {0};

  q_write(q, source);
  state.visited[source] = true;
  state.parent[source] = -1;

  printf("BFS: %zu -> %zu\n", source, destination);

  while (q_size(q).result != 0) {
    int curr = q_read(q).result;

    printf("Visit: %d\n", curr);
    if (curr == destination) {
      printf("Found destination!\n");
      result.found = true;

      size_t idx = 0;
      size_t current = destination;
      while (current != (size_t)-1) {
        result.path[idx++] = current;
        current = state.parent[current];
      }
      result.path_length = idx;
      q_free(q);
      return result;
    }

    size_t neighbors[10];
    size_t count = graph_get_neighbors(g, curr, neighbors, 10);

    for (size_t i = 0; i < count; i++) {
      size_t next = neighbors[i];
      if (next >= 100) {
        continue;
      }
      if (!state.visited[next]) {
        q_write(q, next);
        state.visited[next] = true;
        state.parent[next] = curr;
      }
    }
  }
  printf("No path found\n");
  q_free(q);
  return result;
}