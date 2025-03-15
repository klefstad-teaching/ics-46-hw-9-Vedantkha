#include "dijkstras.h"
#include <iostream>
#include <algorithm>  
using namespace std;

vector<int> dijkstra_shortest_path(const Graph &G, int source, vector<int> &previous) {
  vector<int> distances(G.numVertices, INF);
  distances[source] = 0;
  previous.resize(G.numVertices, -1);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
  Q.push(make_pair(0, source));
  
  while (!Q.empty()) {
    
    pair<int, int> top = Q.top();
    int dist = top.first;
    int u = top.second;
    Q.pop();
    
    if (dist > distances[u])
      continue;
    
    for (auto &&e : G[u]) {
      int v = e.dst;
      int w = e.weight;
      if (dist + w < distances[v]) {
        distances[v] = dist + w;
        previous[v] = u;
        Q.push(make_pair(distances[v], v));
      }
    }
  }
  return distances;
}

vector<int> extract_shortest_path(const vector<int> &distances,
                               const vector<int> &previous,
                               int destination) {
    
    if (distances[destination] == INF)
        return vector<int>();
        
    
    if (distances[destination] != 0 && previous[destination] == -1)
        return vector<int>();
        
    vector<int> path;
    for (int v = destination; v != -1; v = previous[v])
        path.push_back(v);
        
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int> &v, int total) {
  for (size_t i = 0; i < v.size(); i++)
    cout << v[i] << ' ';
  cout << endl;
  cout << "Total cost is " << total << endl;
}
