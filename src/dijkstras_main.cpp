

#include "dijkstras.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  string filename = argc > 1 ? argv[1] : "small.txt";
  Graph G;
  // cout << "Reading graph from " << filename << endl;
  filename = "src/" + filename;
  file_to_graph(filename, G);
  // for (int i = 0; i < G.numVertices; i++) {
  //   cout << i << ": ";
  //   for (auto &&e : G[i])
  //     cout << e << ' ';
  //   cout << endl;
  // }

  vector<int> previous;
  vector<int> distances = dijkstra_shortest_path(G, 0, previous);
  for (int i = 0; i < G.numVertices; i++) {
    vector<int> path = extract_shortest_path(distances, previous, i);
    print_path(path, distances[i]);
  }

  return 0;
}
