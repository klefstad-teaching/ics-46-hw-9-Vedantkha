
#include "dijkstras.h"
#include <iostream>

vector<int> dijkstra_shortest_path(const Graph &G, int source,
                                   vector<int> &previous) {
  vector<int> distances(G.numVertices, INF);
  distances[source] = 0;
  previous.resize(G.numVertices, -1);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      Q;
  Q.push({0, source});
  while (!Q.empty()) {
    auto [dist, u] = Q.top();
    Q.pop();
    if (dist > distances[u])
      continue;
  }