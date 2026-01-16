#include "bfs.h"

int main() {
  // Test 1. Simple graph
  Graph *test1 = graph_create(5);
  graph_add_edge(test1, 0, 1);
  graph_add_edge(test1, 0, 2);

  graph_add_edge(test1, 1, 3);
  graph_add_edge(test1, 2, 4);

  printf("Graph 0->1->3\n");
  printf("Graph 0->2->4\n");

  BFSResult result1 = bfs(test1, 0, 3);
  printf("Simple graph from 0 to 3 - %s\n", (result1.found) ? "PASS" : "FAIL");

  result1 = bfs(test1, 0, 4);
  printf("Simple graph from 0 to 4 - %s\n", (result1.found) ? "PASS" : "FAIL");

  result1 = bfs(test1, 0, 5);
  printf("Simple graph from 0 to 5 - %s\n", (!result1.found) ? "PASS" : "FAIL");

  graph_free(test1);

  // Test 2. Circle graph
  Graph *test2 = graph_create(3);
  graph_add_edge(test2, 0, 1);
  graph_add_edge(test2, 1, 2);
  graph_add_edge(test2, 2, 0);

  BFSResult result2 = bfs(test2, 0, 2);
  printf("Graph 0->1->2->0\n");
  printf("Circle graph from 0 to 2 - %s\n", (result2.found) ? "PASS" : "FAIL");

  graph_free(test2);

  // Test 3. Disconnected graph
  Graph *test3 = graph_create(4);
  graph_add_edge(test3, 0, 1);
  graph_add_edge(test3, 3, 4);

  BFSResult result3 = bfs(test2, 0, 3);
  printf("Graph 0->1 | 3->4\n");
  printf("Circle graph from 0 to 3 not valid - %s\n",
         (!result3.found) ? "PASS" : "FAIL");

  graph_free(test3);

  return 0;
}