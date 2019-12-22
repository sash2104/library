#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include "../../graph/strongly-connected-components.cpp"

int main() {
  int V, E;
  cin >> V >> E;
  Graph<int> graph(V);
  for (int i = 0; i < E; ++i) {
    int x, y;
    cin >> x >> y;
    graph[x].emplace_back(x, y);
  }
  stronglyConnectedComponents<int> scc(graph);
  scc.build();
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; ++i) { 
    int u, v;
    cin >> u >> v;
    if (scc.same(u, v)) { cout << "1" << endl; }
    else { cout << "0" << endl; }
  }
}
