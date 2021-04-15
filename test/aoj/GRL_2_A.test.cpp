#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include "../../graph/mst-kruskal.hpp"

#include <iostream>
using namespace std;

using edge = Edge<int>;
int main() {
  vector<edge> edges;
  int V, E;
  cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    edges.emplace_back(x, y, w);
  }
  int ans = kruscal(V, edges);
  cout << ans << endl;
}
