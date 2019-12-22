#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"
#include "../../graph/topological-sort.cpp"

#include <iostream>
using namespace std;

using G = Graph<int>;
int main() {
  int V, E; cin >> V >> E;
  G graph(V);
  for (int i = 0; i < E; ++i) {
    int s, t; cin >> s >> t;
    graph[s].emplace_back(s, t);
  }
  vector<int> order = topologicalSort(graph);
  for (int v: order) { cout << v << endl; }
}
