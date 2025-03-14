
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
    for (auto &&e : G[u]) {
      int v = e.dst;
      int w = e.weight;
      if (dist + w < distances[v]) {
        distances[v] = dist + w;
        previous[v] = u;
        Q.push({distances[v], v});
      }
    }
  }
  return distances;
}

vector<int> extract_shortest_path(const vector<int> &distances,
                                  const vector<int> &previous,
                                  int destination) {
  vector<int> path;
  for (int v = destination; v != -1; v = previous[v])
    path.push_back(v);
  reverse(path.begin(), path.end());
  return path;
}