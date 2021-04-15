#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"

#include "../../graph/bin-bfs.hpp"
#include <iostream>
using namespace std; 

int main() {
  int n; cin >> n;
  Graph<int> g(n);
  for (int i = 0; i < n; ++i) {
    int u, k; cin >> u >> k;
    --u;
    for (int j = 0; j < k; ++j) {
      int v; cin >> v; --v;
      g[u].emplace_back(u, v, 1);
    }
  }
  BinBFS<int> bfs(g);
  bfs.init(0);
  for (int i = 0; i < n; ++i) {
    int d = bfs.dist[i];
    if (d == bfs.INF) d = -1;
    cout << i+1 << " " << d << endl;
  }
}
